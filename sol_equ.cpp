/* 
 * ��һԪһ�η��� 2019-07-07 Ver 1.0 by little_stejan with Dev-Cpp & MIT License
 * 
 * ���뷽�̷������ڿհ׿���̨��ֱ��������Ҫ���һԪһ��
 *               ���̣������ڲ�Ҫ�пո�Ȼ������س����ɡ�
 * �����ʽ��ÿ�е����Ϊ��Ӧ����Ľ������������ϲ�ͬ���ϵ����Ϊ1��
 *           �ݲ�֧��ȥ��ĸ��ȥ���ţ�ԭ����ע�������ڡ�
 * 
 * ע�����
 * 1.���ļ�Ϊ���C++���룬��������ע�ͣ������������⡣
 * 2.���ļ��޷Ǳ�׼��������428��ʹ��Windowsϵͳ������ͣ��ʹ�������������Ӧ�ܱ��롣
 * 3.�����ֻ�ܽ�һԪһ�η��̣��Ҳ��ܴ���xʽϵ���ͳ���Ϊ������С���ķ��̣� 
 *   ����������ִ�е�ϵ����Ϊ1�Ĺ���ʱ����������ϵ�����������������Ƚ���׼ȷ��
 * 4.���ڱ�������ܴ��������С�������Գ�������ȥ
 *   ��ĸ���ܣ�����ķ���Ҳ�벻Ҫ���κη�����С����
 * 5.��������ⷽ��Ϊ��׼˳��ÿ�����趼�е����ĺ���ִ�У����
 *   ֱ�Ӵ����ַ����������������������ע��ĳ�������Կ�����ִ�С�
 * 6.�������δ֪����Ϊx���벻Ҫʹ��y��z���ַ���ʾδ֪����������ִ���
 * 7.�������һ��͵Ⱥ�����ĵ���ʽ����ϵ��Ϊ1�ĺ�xʽ����ʡ������ϵ
 *   ��Ϊx����������ʽ����ϵ��Ϊ1��-1�ĺ�xʽ�����������һ��͵Ⱥ�
 *   ����ĵ���ʽ�����Ա�������ȥ�����֣���+1x��Ϊ+x��-1x��Ϊ-x��
 * 8.�벻Ҫ�����뷽��ʱ����ո񣬷�������޷���ȷ����
 * 9.������ⷽ��ʱ������ÿ������Է����Ѿ���ȷ����
 *   �Կ��ܻ��������������Ȼ��������������������
 * 10.�����ַ��������ڴ����58���޸ģ����ݱ���С��2^31-1����2147483647�� 
 * 11.ȥ���Ź������ޣ�ԭ��Ϊʱ��ͼ������㣬���ں��ڼ��롣
 * 12.�������MIT��ԴЭ�鿪Դ������ڲ��������������κ�
 *    ���⣬��ӭ���ʼ������� little_stejan@hotmail.com
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

const int N=10000;//�޸�10000Ϊ����Ҫ�ķ����ַ��������ɣ�������С��2^31-1
char exp[N];
int head=0,tail=strlen(exp)-1;
void movemono() {
	int coe[N]= {},val[N]= {};
	int coen=0,valn=0,te=0,iseq=0,fl=1;
	for(int i=head; i<=tail; i++) {
		if(exp[i]=='x') {
			//�ռ�ʽ��
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
			//�ռ�����һ��������г���
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
			//�Ⱥź���Ĵ���
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
			//����ϵ������
			te*=10;
			te+=exp[i]-'0';
		} else if((exp[i]=='+'||exp[i]=='-')&&i==head&&exp[i+1]!='x') {
			//��һ����������
			exp[i]=='+'?fl=1:fl=-1;
		}
		if(i==tail&&exp[i]!='x') {
			//ĩ���
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
	//�޸ķ���
	head=0,tail=-1,iseq=0;
	//��xʽд��
	for(int i=0; i<coen; i++) {
		int len=0;
		//��ȡλ��
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
	//�Ⱥ�д��
	exp[++tail]='=';
	//����д��
	for(int i=0; i<valn; i++) {
		int len=0;
		//��ȡλ��
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
	//���
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
void mergemono() {
	int coe=0,val=0;
	for(int i=head; i<=tail; i++) {
		//��ȡ��ϵ����ʽ�ӣ��Ⱥ���ࣩ
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
		//��ȡ�������Ⱥ��Ҳࣩ
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
	//��ȡλ��
	{
		int x=coe;
		while(x) {
			x/=10;
			len++;
		}
	}
	//�޸ķ���
	head=0;
	//д��ϲ���ĺ�xʽ
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
	//��ȡλ��
	{
		int x=val;
		while(x) {
			x/=10;
			len++;
		}
	}
	//д�볣��
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
	//���
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
void coe21() {
	int coe=0,val=0;
	for(int i=head; i<=tail; i++) {
		//��ȡϵ��
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
					printf("x no solution\n");//ϵ��Ϊ0�޽�
					return;
				} else {
					coe*=fl;
				}
			}
		}
		//��ȡ����
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
	val/=coe;//ϵ����Ϊ1
	int len=0;
	//��ȡλ��
	{
		int x=val;
		while(x) {
			x/=10;
			len++;
		}
	}
	//�޸ķ��̣�ֱ����ԭλ��д�룩
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
	//���
	for(int i=head; i<=tail; i++) {
		printf("%c",exp[i]);
	}
	printf("\n");
	return;
}
//������
int main() {
	gets(exp);
	tail=strlen(exp)-1;
	movemono();
	mergemono();
	coe21();
	system("pause");//��Windowsϵͳ��ע�͸ô��� 
	return 0;
}

