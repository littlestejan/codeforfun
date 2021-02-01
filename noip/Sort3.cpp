//≤Â»Î≈≈–Ú 
#include<iostream>
using namespace std;
#define N 10000
int a[N];
int n;
void insert(){
	for(int i=2;i<=n;i++){
		int x=a[i];
		for(int j=1;j<i;j++){
			if(a[j]>=x){
				for(int k=i;k>=j+1;k--){
					a[k]=a[k-1];
				}
				a[j]=x;
				break;
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	insert();
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	return 0;
}

