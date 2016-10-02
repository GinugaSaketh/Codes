#include<bits/stdc++.h>

using namespace std;


bool dp[505][505][505];

int c[505];

int main(){

	int n,k_;
	cin>>n>>k_;

	int i,j,k;



	for(i=1;i<=n;i++){
		cin>>c[i];
	}

	for(i=0;i<=n;i++){
		for(j=0;j<=k_;j++){
			for(k=0;k<=k_;k++){
				dp[i][j][k]=false;
			}
		}
	}

	dp[0][0][0]=true;


	for(i=1;i<=n;i++){

		for(j=0;j<=k_;j++){
			for(k=0;k<=j;k++){
				dp[i][j][k]|=dp[i-1][j][k];

				if(j-c[i]>=0){
					dp[i][j][k]|=dp[i-1][j-c[i]][k];
					if(k-c[i]>=0){
						dp[i][j][k]|=dp[i-1][j-c[i]][k-c[i]];
					}
				}
			}
		}
	}

	

	int net=0;

	for(i=0;i<=k;i++){
		if(dp[n][k_][i]){
			net++;
			//cout<<i<<" ";
		}
	}//cout<<endl;	

	cout<<net<<endl;
	for(i=0;i<=k_;i++){
		if(dp[n][k_][i]){
			//net++;
			cout<<i<<" ";
		}
	}cout<<endl;	




	return 0;
}