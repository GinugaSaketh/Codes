#include<bits/stdc++.h>

using namespace std;

int dp[1105][105];


int main(){

	int u,v,t,d;
	cin>>u>>v;
	cin>>t>>d;
	int i,j,k;

	for(i=0;i<1105;i++){
		for(j=0;j<=100;j++){
			dp[i][j]=-1;
		}
	}

	dp[u][0]=0;
	dp[u][1]=u;

	for(i=1;i<t;i++){
		for(j=0;j<1105;j++){
			if(dp[j][i]!=-1){
				for(k=0;k<=d;k++){
					dp[j+k][i+1]=max(dp[j+k][i+1],j+k+dp[j][i]);
				}
				for(k=0;j-k>=0&&k<=d;k++){
					dp[j-k][i+1]=max(dp[j-k][i+1],j-k+dp[j][i]);
				}
			}
		}
	}


	for(i=0;i<=t;i++){
		for(j=0;j<20;j++){
			//cout<<dp[j][i]<<" ";
		}//cout<<endl;
	}



	int net=dp[v][t];

	
	cout<<net<<endl;

	//cout<<dp[7][2]<<" "<<dp[8][3]<<" "<<dp[6][4]<<endl;





	return 0;
}