#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll mod=(ll)(1e9+7);


ll dp[100005];

ll sum[100005];


int main(){

	int t,k;
	int i;
	cin>>t>>k;

	for(i=0;i<k;i++){
		dp[i]=1;
	}

	for(i=k;i<=(int)(1e5+1);i++){
		dp[i]=dp[i-1]+dp[i-k];
		dp[i]%=mod;
	}

	sum[0]=0;

	for(i=1;i<=(int)(1e5+1);i++){
		sum[i]=dp[i]+sum[i-1];
		sum[i]%=mod;
	}

	int a,b;

	for(i=0;i<t;i++){
		cin>>a>>b;

		ll net=sum[b]-sum[a-1]+2*mod;

		net%=mod;

		cout<<net<<endl;


	}


	


	return 0;
}