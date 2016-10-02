#include<bits/stdc++.h>

using namespace std;
#define ll int

ll dp[5005][5005];

ll inf=(ll)(1e9+5);
vector<vector<pair<int ,ll> > > adj;
int last[5005][5005];

vector <int> net;

int main(){
	int n,m;
	int i,j;
	ll t;
	cin>>n>>m>>t;
	
	int u,v;

	adj.resize(n+5);
	ll c;
	for(i=0;i<m;i++){
		cin>>u>>v>>c;
		adj[v].push_back(make_pair(u,c));
		//u in edge to v
	}


	//i -> node j->edges

	for(i=0;i<=n;i++){

		for(j=0;j<=n-1;j++){
			dp[i][j]=inf;
			last[i][j]=-1;
		}
	}


	dp[1][0]=0;
	//last for 1 is base case
	int k;

	for(j=1;j<=n-1;j++){

		for(i=1;i<=n;i++){

			for(k=0;k<adj[i].size();k++){
				u=adj[i][k].first;
				c=adj[i][k].second;
				//cout<<u<<endl;
				if(dp[u][j-1]+c<dp[i][j]){
					last[i][j]=u;
				}

				dp[i][j]=min(dp[u][j-1]+c,dp[i][j]);

			}
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;

	}



	int in=0;

	for(i=0;i<=n-1;i++){

		if(dp[n][i]<=t){
			in=max(in,i);
		}

	}

	u=n;
	i=in;
	for(i=1;i<=in;i++){
		if(u==-1){
			 cout<<"ewfadc"<<endl;
		}

		net.push_back(u);
		u=last[u][in-i+1];
	}

	net.push_back(1);
	cout<<(in+1)<<endl;

	for(i=net.size()-1;i>=0;i--){
		cout<<net[i]<<" ";
	}cout<<endl;




	return 0;
}