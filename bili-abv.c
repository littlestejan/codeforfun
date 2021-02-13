/* 
 * @Version : 1.0 
 * @Time	: 2020/04/05 
 * @Author  : little_stejan 
 * @File	: abv.c 
 * @Description: 
 *  ��ĳ֪��������ĳ������ 
 *  https://www.zhihu.com/question/381784377/answer/1099438784 
 *  �Ļظ��и��ϵĴ���Ϊ������������C�汾�ı���av��bv��ת�ĳ��� 
 *  ��Դ����ΪPython�汾�� 
 *  �÷����ڿ���̨��ֱ������av�ţ���av170001����bv�ţ���BV17x411w7KC�� 
 *  ���ɣ�������Զ����ת����Ķ�Ӧbv��av�� 
 *  ע���������������bug���ð汾��Ϊ���հ汾�����˽�����ά���͸��� 
 *  ��������WTFPLЭ�鿪Դ
 */
#include<stdio.h>
int main(){
	long long av=0,type=0;
	char bv[13];
	char type1,type2;
	char table[59]="fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
	int bs[10]={11,10,3,8,4,6,2,9,5,7};
	int bt[10]={6,2,4,8,5,9,3,7,1,0};
	long long orx=177451812; //xor��C++�ؼ��֣��ʶ���Ϊorx������ 
	long long add=100618342136696320;
	long long n=1;
	int tr[128]={};
	int i;
	for(i=0;i<59;i++){
		tr[table[i]]=i;
	}
	scanf("%c%c",&type1,&type2);
	if(type1=='a'){
		scanf("%lld",&av);
		av=(av^orx)+add;
		for(i=0;i<10;i++){
			bv[bs[i]]=table[av/n%58];
			n*=58;
		}
		bv[0]='B';bv[1]='V';
		printf("%s",bv);
	}else if(type1=='B' || type1 == 'b'){
		scanf("%s",&bv);
		long long x[10];
		for(i=0;i<10;i++){
			x[bt[i]]=tr[bv[i]];
		}
		for(i=0;i<10;i++){
			av+=x[i]*n;
			n*=58;
		}
		av=(av-add)^orx;
		printf("av%lld",av);
	}
}

