#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <long long> a;

long long b[100005]; 	

long long dp[100005];


int main(){
	int n;
	cin>>n;
	int i;
	long long x;
	for(i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}

	sort(a.begin(),a.end());


	for(i=0;i<100005;i++){
		b[i]=0;
	}

	for(i=0;i<n;i++){
		b[a[i]]+=1;
	}


	dp[0]=0;

	dp[1]=b[1];

	for(i=2;i<=100000;i++){
		dp[i]=max(dp[i-1],dp[i-2]+b[i]*i);
	}

	cout<<dp[100000]<<endl;


	

	return 0;
}