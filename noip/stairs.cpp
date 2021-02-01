//洛谷-数楼梯 无注释请小心食用 2020/12/13
//https://www.luogu.com.cn/problem/P1255 
#include<iostream>
using namespace std;
unsigned long long int a[6000];
int b[6000][6000]={},len=1;
int main(){
	int n;
	cin >> n;
	b[1][1]=1;
	b[2][1]=2;
	for(int i=3;i<=n;i++){
    	for(int j=1;j<=len;j++){
     		b[i][j]=b[i-1][j]+b[i-2][j]; 
     	}
    	for(int j=1;j<=len;j++){ 
     		if(b[i][j]>=10){
         		b[i][j+1]+=b[i][j]/10;
         		b[i][j]=b[i][j]%10;
    			if(b[i][len+1]){
    				len++;
				} 
    		}
		}
	}
	for(int i=len;i>=1;i--){
		cout << b[n][i];
	}
	cout << endl;
	return 0;
} 

