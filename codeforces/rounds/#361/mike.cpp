#include<bits/stdc++.h>

using namespace std;


int a[200005];

int b[200005];

int dp[200005];


int main(){
	int i;
	int n;
	cin>>n;
	for(i=0;i<=n;i++){
		b[i]=-1;
	}

	for(i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==-1){
			b[a[i]]=i;
		}
	}


	dp[1]=0;
	int inf=(int)(1e9);

	for(i=2;i<=n;i++){
		dp[i]=inf;
	}


	for(i=2;i<=n;i++){
		if(b[i]==-1){
			dp[i]=dp[i-1]+1;
			continue;
		}
		dp[i]=min(dp[i-1]+1,dp[b[i]]+1);
	}

	for(i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;




	return 0;
}