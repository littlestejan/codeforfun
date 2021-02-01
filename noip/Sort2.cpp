//ц╟ещеепР 
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10000
int a[N];
int n;
void bubble(){
	for(int i=1;i<=n;i++){
		bool bo=true;
		for(int j=1;j<=n-i;j++){
			if(a[j]>=a[j+1]){
				swap(a[j],a[j+1]);
				bo=false;
			}
		}
		if(bo) break;
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	bubble();
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	return 0;
}
