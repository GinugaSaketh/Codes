#include<iostream>


long long INF=(long long )(1e9+7);

using namespace std;
int main(){
	int t;
	cin>>t;
	long long i;
	while(t--){
		long long n,k;
		cin>>n>>k;
		long long a[100005],b[100005];
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		long long ma=-INF;
		long long mi=INF;
		
		long long sum=0;
		for(i=0;i<n;i++){
			cin>>b[i];
			if(ma<b[i]){
				ma=b[i];
				
			}
			if(mi>b[i]){
				mi=b[i];
				
			}
			sum+=a[i]*b[i];
		}
		
		if(mi==ma){
			if(ma>0){
			sum+=ma*k;
			}else{
			sum-=ma*k;
			}
		}else if(mi+ma>=0){
			sum+=ma*k;

		}else if(mi+ma<0){
			sum-=mi*k;
		}
		cout<<sum<<endl;

	}


	return 0;
}