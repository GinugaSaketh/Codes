#include<bits/stdc++.h>

#define ll long long 

using namespace std;

ll dist[100005];

vector<vector<pair<int,ll> > > adj;


void dfs(int u){

	int v,i;

	for(i=0;i<adj[u].size();i++){
		v=adj[u][i].first;
		if(dist[v]==-1){
			dist[v]=dist[u]+adj[u][i].second;
			dfs(v);
		}
	}
}

int main(){
	int n,i;

	cin>>n;
	int x,y;
	ll w_;
	ll net=0;
	adj.resize(n+5);
	for(i=1;i<n;i++){
		cin>>x>>y>>w_;
		net+=2*w_;
		adj[x].push_back(make_pair(y,w_));
		adj[y].push_back(make_pair(x,w_));
	}

	for(i=0;i<=n;i++){
		dist[i]=-1;
	}

	dist[1]=0;

	dfs(1);
	int j;
	
	ll mx=-1;
	for(i=1;i<=n;i++){

		mx=max(mx,dist[i]);
		
	}

	net=net-mx;
	net++;
	net--;
	cout<<net<<endl;



	return 0;
}