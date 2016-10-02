#include<bits/stdc++.h>

using namespace std;

int dp[1000005];

int c[1000005];


int main(){
	int n;
	cin>>n;

	int i;
	for(i=0;i<1000005;i++){
		dp[i]=0;
		c[i]=0;
	}

	int a,b;

	for(i=0;i<n;i++){
		cin>>a>>b;
		c[a]=b;
	}

	if(c[0]>0){
		dp[0]=1;
	}

	int mx=dp[0];


	for(i=1;i<1000005;i++){
		if(c[i]==0){
			dp[i]=dp[i-1];
		}else{
			if(i-c[i]-1>=0){
				dp[i]=1+dp[i-c[i]-1];
			}else{
				//cout<<i<<endl;
				dp[i]=1;
			}
		}
		mx=max(mx,dp[i]);
	}

	cout<<(n-mx)<<endl;




	return 0;
}