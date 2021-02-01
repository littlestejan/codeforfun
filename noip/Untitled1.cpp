#include<iostream>
#include<algorithm>
using namespace std;
int a[1000][2];
int dis[1000],dis2[1000],sum=0,ans=2147483647;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i][0] >> a[i][1];
		if(i>=2){
			dis[i-1]=abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1]);
			dis2[i-1]=abs(a[i][0]-a[i-2][0])+abs(a[i][1]-a[i-2][1]);
			sum+=dis[i-1];
		}
	}
	for(int i=2;i<=n-1;i++){
		if(ans>sum-dis[i-1]-dis[i]+dis2[i]){
			ans=sum-dis[i-1]-dis[i]+dis2[i];
		}
	}
	cout << ans << endl;
	return 0;
}

