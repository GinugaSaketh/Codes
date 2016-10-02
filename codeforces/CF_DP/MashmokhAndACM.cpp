#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[2005][2005];

ll mod=(ll)(1e9+7);

int main(){
	int n,k_;
	cin>>n>>k_;
	int i,j,k;

	for(i=0;i<=k_;i++){
		for(j=0;j<=n;j++){
			dp[i][j]=0;
		}
	}

	for(i=0;i<=n;i++){
		dp[1][i]=1;	
	}

	//dp[i][j] is added to dp[i+1][j'] j'=j*k

	for(i=1;i<k_;i++){
		for(j=1;j<=n;j++){
			for(k=1;j*k<=n;k++){
				dp[i+1][j*k]+=dp[i][j];
				dp[i+1][j*k]%=mod;
			}
		}
	}

	ll net=0;

	for(i=1;i<=n;i++){
		net+=dp[k_][i];
		net%=mod;
	}

	cout<<net<<endl;


	/*for(i=1;i<=k_;i++){
		for(j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	*/

	return 0;
}