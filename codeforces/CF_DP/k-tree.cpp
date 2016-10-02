#include<bits/stdc++.h>

using namespace std;
#define ll long long 

ll mod=(ll)(1e9+7);

ll dp[105][2];
//1 exist


int main(){

 	int n,k,d;

 	cin>>n>>k>>d;

 	int i;




 	int j;

 	dp[0][0]=1;
 	dp[0][1]=0;



 	for(i=1;i<=n;i++){
 		dp[i][0]=0;
 		for(j=1;j<d&&i-j>=0;j++){
 			dp[i][0]+=dp[i-j][0];
 			dp[i][0]%=mod;
 		}

 		dp[i][1]=0;

 		for(j=1;j<=k&&i-j>=0;j++){
 			dp[i][1]+=dp[i-j][1];
 			dp[i][1]%=mod;
 		}

 		for(j=d;j<=k&&i-j>=0;j++){
 			dp[i][1]+=dp[i-j][0];
 			dp[i][1]%=mod;
 		}
 	}

 	cout<<dp[n][1]<<endl;














	return 0;
}