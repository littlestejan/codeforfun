#include<stdio.h>
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
	freopen("int.txt","r",stdin); 
	int a[7];
	int b[17],lb=0;
	int i;
	for(i=0;i<6;i++){
		scanf("%d",&a[i]);
	}
	fclose(stdin);
	for(i=0;i<6;i++){
		int j;
		for(j=i+1;j<6;j++){
			b[lb]=a[i]+a[j];
			b[lb]=b[lb]%987;
			b[lb]=b[lb]%60;
			lb++;
		}
	}
	for(i=0;i<15;i++){
		printf("%c",code[b[i]]);
	}
	printf("\n");
	return 0;
}

