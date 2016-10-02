#include<bits/stdc++.h>

using namespace std;
#define ll long long


ll a[5005];
ll b[5005];

vector <vector<ll > > dp;


int main(){	
	int n,m,k,l;
	int i,j;

	cin>>n>>m>>k;


	dp.resize(n+5);

	for(i=0;i<=n;i++){
		dp[i].resize(k+5,0);
	}

	
	a[0]=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	if(m==1&&k==n){
		ll net=0;
		for(i=1;i<=n;i++){
			net+=a[i];
		}

		cout<<net<<endl;
		return 0;
	}




	b[0]=0;

	for(i=1;i<=m;i++){
		b[i]=b[i-1]+a[i];
	}

	for(i=m+1;i<=n;i++){
		b[i]=b[i-1]+a[i]-a[i-m];
	}


	for(j=1;j<=k;j++){
		ll mx=0;
		for(i=1;i<=n;i++){
			dp[i][j]=b[i];
			if(i-m>=1){
				mx=max(mx,dp[i-m][j-1]);
				dp[i][j]=max(dp[i][j],b[i]+mx);
			}
			/*for(l=i-m;l>=1;l--){
				dp[i][j]=max(dp[i][j],b[i]+dp[l][j-1]);
			}*/
		}
	}

	ll net=0;

	for(i=1;i<=n;i++){
		net=max(net,dp[i][k]);
	}

	cout<<net<<endl;



	return 0;
}