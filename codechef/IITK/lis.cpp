#include<bits/stdc++.h>

using namespace std;

int a[5005];


int dp[5005];

int mod(int x){
	if(x<0){
		return -x;
	}else{
		return x;
	}
}


int main(){
	int n;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	dp[1]=1;

	for(i=2;i<=n;i++){
		dp[i]=1;
		for(j=1;j<i;j++){
			if(mod(a[j])<mod(a[i])){
				if(a[i]>0&&a[j]<0){
					dp[i]=max(dp[i],1+dp[j]);
				}else if(a[i]<0&&a[j]>0){
					dp[i]=max(dp[i],1+dp[j]);
				}
			}
		}
	}


	int net=1;


	for(i=1;i<=n;i++){
		net=max(net,dp[i]);
	}
	cout<<net<<endl;



	return 0;
}