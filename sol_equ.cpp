/* 
 * 解一元一次方程 2019-07-07 Ver 1.0 by little_stejan with Dev-Cpp & MIT License
 * 
 * 输入方程方法：在空白控制台中直接输入需要解的一元一次
 *               方程（方程内不要有空格）然后输入回车即可。
 * 输出格式：每行的输出为对应步骤的结果，即：移项，合并同类项，系数化为1。
 *           暂不支持去分母，去括号，原因在注意事项内。
 * 
 * 注意事项：
 * 1.本文件为软件C++代码，含有少量注释，供读者理解大意。
 * 2.本文件无非标准函数（除428行使用Windows系统命令暂停）使用其它编译软件应能编译。
 * 3.本软件只能解一元一次方程，且不能处理含x式系数和常数为分数或小数的方程， 
 *   若方程正常执行到系数化为1的过程时若常数除以系数不是整数则结果精度将不准确。
 * 4.由于本软件不能处理分数和小数，所以程序中无去
 *   分母功能，输入的方程也请不要含任何分数和小数。
 * 5.但本软件解方程为标准顺序，每个步骤都有单独的函数执行，其可
 *   直接处理字符串，因此您可在主函数中注释某个过程仍可正常执行。
 * 6.本软件设未知数均为x，请不要使用y，z等字符表示未知数，避免出现错误。
 * 7.从左起第一项和等号右面的单项式若是系数为1的含x式，可省略整个系
 *   数为x，其它单项式若是系数为1或-1的含x式（包括左起第一项和等号
 *   右面的单项式）可以保留符号去掉数字，即+1x变为+x，-1x变为-x。
 * 8.请不要在输入方程时输入空格，否则程序将无法正确处理。
 * 9.本软件解方程时，尽管每个步骤对方程已经正确处理，
 *   仍可能会出现无需整理，仍然输出的情况，请自行整理。
 * 10.方程字符数量可在代码第58行修改，数据必须小于2^31-1（即2147483647） 
 * 11.去括号功能暂无，原因为时间和技术不足，将在后期加入。
 * 12.本软件以MIT开源协议开源。如果在操作及代码上有任何
 *    问题，欢迎发邮件给本人 little_stejan@hotmail.com
 * 
 * MIT License
 * 
 * Copyright (c) 2019 little_stejan
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#include<iostream>
#include<cstring>
//using namespace std;

const int N=10000;//修改10000为您想要的方程字符数量即可，但必须小于2^31-1
char exp[N];
int head=0,tail=strlen(exp)-1;
void movemono() {
	int coe[N]= {},val[N]= {};
	int coen=0,valn=0,te=0,iseq=0,fl=1;
	for(int i=head; i<=tail; i++) {
		if(exp[i]=='x') {
			//收集式子
			if(exp[i-1]=='+') {
				te=1;
			} else if(exp[i-1]=='-') {
				te=-1;
			} else if(i==head||exp[i-1]=='=') {
				te=1;
			}
			if(iseq) {
				te*=-1;
			}
			te*=fl;
			coe[coen++]=te;
			//printf("%d",te);
			te=0;
			if(exp[i+1]=='-'&&exp[i+2]!='x') {
				fl=-1;
			} else {
				fl=1;
			}
		} else if((exp[i]=='+'||exp[i]=='-')&&exp[i-1]!='x'&&i!=head) {
			//收集除第一个外的所有常数
			if(!iseq) {
				te*=-1;
			}
			if(exp[i-1]!='=') {
				te*=fl;
				val[valn++]=te;
			}
			//printf("%d",te);
			te=0;
			if(exp[i]=='-'&&exp[i+1]!='x') {
				fl=-1;
			} else {
				fl=1;
			}
		} else if(exp[i]=='=') {
			//等号后面的处理
			iseq=1;
			if(exp[i-1]!='x') {
				te*=fl;
				te*=-1;
				val[valn++]=te;
				//printf("%d",te);
				te=0;
				exp[i+1]=='-'?fl=-1:fl=1;
			}
		} else if(exp[i]!='+'&&exp[i]!='-') {
			//常数系数处理
			te*=10;
			te+=exp[i]-'0';
		} else if((exp[i]=='+'||exp[i]=='-')&&i==head&&exp[i+1]!='x') {
			//第一个常数处理
			exp[i]=='+'?fl=1:fl=-1;
		}
		if(i==tail&&exp[i]!='x') {
			//末项处理
			te*=fl;
			val[valn++]=te;
			//printf("%d",te);
			te=0;
		}
	}
	/*
	for(int i=0;i<coen;i++){
		printf("%d\n",coe[i]);
	}
	for(int i=0;i<valn;i++){
		printf("%d\n",val[i]);
	}
	*/
	//修改方程
	head=0,tail=-1,iseq=0;
	//含x式写入
	for(int i=0; i<coen; i++) {
		int len=0;
		//获取位数
		{
			int x=coe[i];
			while(x) {
				x/=10;
				len++;
			}
		}
		if(coe[i]>0&&i!=0) {
			exp[++tail]='+';
		} else if(coe[i]<0) {
			exp[++tail]='-';
			coe[i]*=-1;
		}
		if(coe[i]!=1&&coe[i]!=-1) {
			for(int j=tail+len; j>=tail+1; j--) {
				exp[j]=(coe[i]%10)+'0';
				coe[i]/=10;
			}
			tail+=len;
		}
		exp[++tail]='x';
	}
	//等号写入
	exp[++tail]='=';
	//常数写入
	for(int i=0; i<valn; i++) {
		int len=0;
		//获取位数
		{
			int x=val[i];
			while(x) {
				x/=10;
				len++;
			}
		}
		if(val[i]>0&&exp[tail]!='=') {
			exp[++tail]='+';
		} else if(val[i]<0) {
			exp[++tail]='-';
			val[i]*=-1;
		}
		for(int j=tail+len; j>=tail+1; j--) {
			exp[j]=(val[i]%10)+'0';
			val[i]/=10;
		}
		tail+=len;
	}
	//输出
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
void mergemono() {
	int coe=0,val=0;
	for(int i=head; i<=tail; i++) {
		//获取带系数的式子（等号左侧）
		if(exp[i]=='x') {
			for(int j=i; j>=0; j--) {
				if(exp[j]=='+'||exp[j]=='-') {
					if(j+1==i&&(exp[j]=='+'||exp[j]=='-')) {
						exp[j]=='+'?coe+=1:coe-=1;
						break;
					}
					int te=0;
					for(int k=j+1; k<i; k++) {
						te*=10;
						te+=exp[k]-'0';
					}
					te*=exp[j]=='+'?1:-1;
					coe+=te;
					break;
				} else if(j==head) {
					if(j+1==i&&exp[j]=='-') {
						coe-=1;
						break;
					} else if((j+1==i&&exp[j]=='+')||exp[head]=='x') {
						coe+=1;
						break;
					}
					int te=0;
					if(exp[j]=='+'||exp[j]=='-') {
						for(int k=1; k<i; k++) {
							te*=10;
							te+=exp[k]-'0';
						}
						exp[j]=='+'?coe+=te:coe-=te;
					} else {
						for(int k=0; k<i; k++) {
							te*=10;
							te+=exp[k]-'0';
						}
						coe+=te;
					}
				}
			}
		}
		//获取常数（等号右侧）
		if(exp[i]=='=') {
			int te=0;
			int fl=1;
			for(int j=i+1; j<=tail; j++) {
				if(exp[j]=='+') {
					val+=te*fl;
					te=0;
					fl=1;
				} else if(exp[j]=='-') {
					val+=te*fl;
					te=0;
					fl=-1;
				} else {
					te*=10;
					te+=exp[j]-'0';
				}
			}
			val+=te*fl;
		}
	}
	//printf("%d %d\n",coe,val);
	int len=0;
	//获取位数
	{
		int x=coe;
		while(x) {
			x/=10;
			len++;
		}
	}
	//修改方程
	head=0;
	//写入合并后的含x式
	if(coe>=0) {
		if(coe==1) {
			head=1;
		}
		for(int i=len-1; i>=head; i--) {
			exp[i]=(coe%10)+'0';
			coe/=10;
		}
		tail=len-1;
		exp[len]='x';
		exp[len+1]='=';
	} else {
		exp[head]='-';
		coe*=-1;
		if(coe==1) {
			exp[head+1]='x';
			exp[head+2]='=';
			tail=head;
		} else {
			for(int i=len; i>head; i--) {
				exp[i]=(coe%10)+'0';
				coe/=10;
			}
			tail=len;
			exp[len+1]='x';
			exp[len+2]='=';
		}
	}
	len=0;
	//获取位数
	{
		int x=val;
		while(x) {
			x/=10;
			len++;
		}
	}
	//写入常数
	if(val>=0) {
		for(int i=tail+len+2; i>=tail+3; i--) {
			exp[i]=(val%10)+'0';
			val/=10;
		}
		tail+=len+2;
	} else {
		exp[tail+3]='-';
		val*=-1;
		for(int i=tail+len+3; i>=tail+4; i--) {
			exp[i]=(val%10)+'0';
			val/=10;
		}
		tail+=len+3;
	}
	//输出
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
void coe21() {
	int coe=0,val=0;
	for(int i=head; i<=tail; i++) {
		//获取系数
		if(exp[i]=='x') {
			if(exp[i-1]=='-'&&i-1>=head) {
				coe=-1;
			} else if(i==head) {
				coe=1;
			} else {
				int fl=1;
				for(int j=head; j<i; j++) {
					if(exp[j]=='-') {
						fl=-1;
					} else if(exp[j]=='+') {
						fl=1;
					} else {
						coe*=10;
						coe+=exp[j]-'0';
					}
				}
				if(coe==0) {
					printf("x no solution\n");//系数为0无解
					return;
				} else {
					coe*=fl;
				}
			}
		}
		//获取常数
		if(exp[i]=='=') {
			int fl=1;
			for(int j=i+1; j<=tail; j++) {
				if(exp[j]=='-') {
					fl=-1;
				} else if(exp[j]=='+') {
					fl=1;
				} else {
					val*=10;
					val+=exp[j]-'0';
				}
			}
			val*=fl;
		}
	}
	//printf("%d %d\n",coe,val);
	val/=coe;//系数化为1
	int len=0;
	//获取位数
	{
		int x=val;
		while(x) {
			x/=10;
			len++;
		}
	}
	//修改方程（直接在原位置写入）
	for(int i=head; i<=tail; i++) {
		if(exp[i]=='x') {
			head=i;
		}
		if(exp[i]=='=') {
			if(val>=0) {
				tail=i+len;
				for(int j=i+len; exp[j]!='='; j--) {
					exp[j]=(val%10)+'0';
					val/=10;
				}
			} else {
				exp[i+1]='-';
				val*=-1;
				tail=i+len+1;
				for(int j=i+len+1; exp[j]!='-'; j--) {
					exp[j]=(val%10)+'0';
					val/=10;
				}
			}
		}
	}
	//输出
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
//主函数
int main() {
	gets(exp);
	tail=strlen(exp)-1;
	movemono();
	mergemono();
	coe21();
	system("pause");//非Windows系统请注释该代码 
	return 0;
}

