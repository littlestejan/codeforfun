/*
 * 
 * @Version : 1.0 
 * @Time	: 2021/01/27 
 * @Author  : little_stejan 
 * @File	: int2ch.cpp 
 * @Description: 
 *  闲的无聊写的程序 可以将6组数字转一串文本
 * （技术含量极低且不支持逆转）仅用作后期软件的开发和研究 
 *  甚至连简介都是走形式 （无注释也可放心食用？） 
 *  本代码以WTFPL协议开源 
 * （话说我也该去学习了 看到我请叫我滚去学习！） 
 *
 */
#include<cstdio>
char code[62]={
'N','X','7','s','h',
'f','c','U','Z','u',
'e','o','2','5','3',
'b','W','H','J','m',
'1','i','A','9','z',
'P','Y','M','j','D',
'g','G','L','C','K',
'T','w','r','y','R',
'n','E','0','4','a',
'O','6','t','F','8',
'x','V','p','B','d',
'Q','k','S','v','q'};
int main(){
	//freopen("int.txt","r",stdin); 
	int a[7];
	int b[17],lb=0;
	for(int i=0;i<6;i++){
		scanf("%d",&a[i]);
	}
	//fclose(stdin);
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			b[lb]=a[i]+a[j];
			b[lb]=b[lb]%987;
			b[lb]=b[lb]%60;
			lb++;
		}
	}
	for(int i=0;i<15;i++){
		printf("%c",code[b[i]]);
	}
	printf("\n");
	return 0;
}

