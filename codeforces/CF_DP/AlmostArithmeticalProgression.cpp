#include<bits/stdc++.h>

using namespace std;

int dp[4005][4005];

int a[4005];



int main(){
	
	int n;
	int i,j;
	cin>>n;

	for(i=1;i<=n;i++){
		cin>>a[i];
	}


	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=0;
		}
	}

	for(i=1;i<=n;i++){
		dp[0][i]=1;
	}

	int ma=1;

	for(i=1;i<=n;i++){
		int pv=0;
		for(j=1;j<i;j++){
			dp[j][i]=dp[pv][j]+1;
			if(a[j]==a[i])pv=j;
			ma=max(ma,dp[j][i]);
		}
	}

	cout<<ma<<endl;





	return 0;
}