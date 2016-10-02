#include<bits/stdc++.h>

using namespace std;

#define ll long long 


ll dp[105][105][105];
int c[105];
ll p[105][105];

int i,j,k,j_;

int m,n,l;

int main(){

	cin>>n>>m>>l;

	for(i=1;i<=n;i++){
		cin>>c[i];
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}

	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			for(k=0;k<=l;k++){
				dp[i][j][k]=-1;
			}
		}
	}

	//i==1

	if(c[1]==0){
		for(j=1;j<=n;j++){
			dp[1][j][1]=p[1][j];
		}
	}else{
		dp[1][c[1]][1]=0;
	}


	for(i=2;i<=n;i++){

		if(c[i]==0){
			for(j=1;j<=m;j++){
				for(k=1;k<=i&&k<=l;k++){
					for(j_=1;j_<=m;j_++){

						if(k>1){
							if(dp[i-1][j_][k-1]!=-1){
								if(dp[i][j][k]==-1){
									//cout<<i<<" "<<j<<" "<<p[i][j]<<endl;
									if(j!=j_)dp[i][j][k]=p[i][j]+dp[i-1][j_][k-1];
								}else{
									if(j!=j_)dp[i][j][k]=min(dp[i][j][k],p[i][j]+dp[i-1][j_][k-1]);
								}
							}

						}

						if(j_==j){

							if(dp[i-1][j_][k]!=-1){
								if(dp[i][j][k]==-1){
									dp[i][j][k]=p[i][j]+dp[i-1][j_][k];
								}else{
									dp[i][j][k]=min(dp[i][j][k],p[i][j]+dp[i-1][j_][k]);
								}
							}
						}		
					}
					//cout<<i<<" "<<j<<" "<<k<<" = "<<dp[i][j][k]<<endl;
				}
			}
		}else{
			j=c[i];
			for(k=1;k<=l;k++){
				//cout<<k<<endl;
				for(j_=1;j_<=m;j_++){
					if(k>1){
						if(dp[i-1][j_][k-1]!=-1){
							if(dp[i][j][k]==-1){
								if(j!=j_)dp[i][j][k]=dp[i-1][j_][k-1];
							}else{
								if(j!=j_)dp[i][j][k]=min(dp[i][j][k],dp[i-1][j_][k-1]);
							}
						}

					}

					if(j_==j){

							if(dp[i-1][j_][k]!=-1){
								if(dp[i][j][k]==-1){
									dp[i][j][k]=dp[i-1][j_][k];
								}else{
									dp[i][j][k]=min(dp[i][j][k],dp[i-1][j_][k]);
								}
							}
						}
					//cout<<i<<" "<<j<<" "<<k<<" = "<<dp[i][j][k]<<endl;
				}
			}



		}



	}
	ll ans=-1;

	if(c[n]==0){
		for(j=1;j<=m;j++){

			if(dp[n][j][l]!=-1){
				if(ans==-1){
					ans=dp[n][j][l];
				}else{
					ans=min(ans,dp[n][j][l]);
				}
			}
		}
	}else{
		ans=dp[n][c[n]][l];
	}

	cout<<ans<<endl;




	return 0;
}
