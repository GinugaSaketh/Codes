#include<bits/stdc++.h>

using namespace std;

#define INF (int)(2e9)

int n,t,i,j,k;
int dp[105][105];

int a[105];

int main(){

	

	for(i=0;i<105;i++){
		for(j=0;j<105;j++){
			if(i==j){
				unit[i][j]=1;
			}else{
				unit[i][j]=0;
			}
		}
	}

	cin>>n>>t;

	for(i=0;i<n;i++){
		cin>>a[i];
	}

	for(i=0;i<105;i++){
		for(j=0;j<105;j++){
			dp[i][j]=0;
		}
	}
	


	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<i){
				dp[i][j]=-INF;
				continue;
			}
			dp[i][j]=1;
			if(i==j)continue;
			for(k=j-1;k>=i;k--){
				if(a[j]>=a[k]&&a[j]>=a[i]){
					dp[i][j]=max(dp[i][j],1+dp[i][k]);
				}else if(a[j]<a[i]){
					dp[i][j]=-INF;
					break;
				}
			}
		}
	}

	dp=modpow(dp	,t);

	int net=-INF;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
			net=max(net,dp[i][j]);
		}cout<<endl;
	}
	cout<<net<<endl;







	return 0;
}