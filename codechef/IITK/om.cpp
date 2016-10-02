#include<bits/stdc++.h>

using namespace std;

long long dp[100005];

int a[100005];

int p[100005];

vector <vector<int> > v;


int main(){
	int n;
	cin>>n;
	int i,j;

	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	p[0]=p[1]=0;
	for(i=2;i<100005;i++){
		p[i]=1;
	}

	v.resize(100005);

	for(i=2;i<=100000;i++){
		if(p[i]==1){
			v[i].push_back(i);
			for(j=2;i*j<=100000;j++){
				p[i*j]=0;
				v[i*j].push_back(i);
			}
		}
	}
	dp[1]=a[1];
	for(i=2;i<=n;i++){
		dp[i]=a[i];
		for(j=0;j<v[i].size();j++){
			dp[i]=max(dp[i],a[i]+dp[i/v[i][j]]);
		}
	}

	for(i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;







	return 0;
}