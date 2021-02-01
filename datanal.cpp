//早期代码 给定数据个数和数据，计算数据的平均数、中位数、  
//众数、极差、方差和标准差并按顺序输出 无注释请谨慎食用 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	const int N=10000;
	int n,i,j;
	long double a[N],count[2]={1,1},m,h,s=0,e,v=0,d;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		s+=a[i];
	}
	m=s/n;
	sort(a,a+n);
	if(n%2==0){
		h=(a[n/2-1]+a[n/2])/2;
	}else{
		h=a[(n+1)/2-1];
	}
	long double most=a[0];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if (a[i] == a[j]){
				count[0]++;
			}
		}
		if(count[0]>count[1]){
			count[1]=count[0];
			most=a[i];
		}else if(count[0]==count[1]){
            if(most>a[i]){
                most=a[i];
            }
        }
		count[0]=1;
	}
	e=a[n-1]-a[0];
	for(i=0;i<n;i++){
		v+=(a[i]-m)*(a[i]-m);
	}
	v/=n;
	d=sqrt(v);
	cout << m << " " << h << " " << most << " " << e << " " << v << " " << d << endl;
	return 0;
}
