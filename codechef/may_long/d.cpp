#include<iostream>

using namespace std;


long long mod=(long long )(1e9+7);

int dp[1005][1005];

int a[1005];

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m,s;
		cin>>n>>m>>s;
		int i,j;
		for(i=1;i<=m;i++){
			cin>>a[i];
		}

		for(i=1;i<=n;i++){
			dp[i][0]=0;
		}
		dp[s][0]=1;

		

		for(j=1;j<=m;j++){
			//a[j]
			for(i=1;i<=n;i++){
				dp[i][j]=0;
				if(i+a[j]<=n){
					
					dp[i][j]+=dp[i+a[j]][j-1];
					dp[i][j]%=mod;
				}
				if(i-a[j]>=1){
					dp[i][j]+=dp[i-a[j]][j-1];
					dp[i][j]%=mod;
				}
				
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;


			}

		}


		for(i=1;i<=n;i++){
			cout<<dp[i][m]<<" ";
		}cout<<endl;	







	}

	return 0;
}