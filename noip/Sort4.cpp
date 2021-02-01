//Õ∞≈≈–Ú 
#include<iostream>
using namespace std;
#define N 10000
int a[N],b[N*10]={};
int n;
void buckle(){
	int max=-1,len=0;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		if(a[i]>=max) max=a[i];
	}
	for(int i=0;i<=max;i++){
		if(b[i]!=0){
			int count=b[i];
			while(count--){
				a[++len]=i;
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	buckle();
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	return 0;
}

