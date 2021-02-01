//—°‘Ò≈≈–Ú 
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10000
int a[N];
int n;
void select(){
	for(int i=1;i<=n-1;i++){
		int min=2147483647,pos=0;
		for(int j=i;j<=n;j++){
			if(a[j]<=min){
				min=a[j];
				pos=j;
			}
		}
		swap(a[i],a[pos]);
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	select();
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	return 0;
}

