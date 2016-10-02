#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >adj;


int dist[100005];
int sub[100005];



void dfs(int x){

	int i;
	for(i=0;i<adj[x].size();i++){

		int y=adj[x][i];

		if(dist[y]==-1){
			dist[y]=1+dist[x];
			dfs(y);
			sub[x]+=sub[y];
		}
	}
}


int main(){
	int n;
	cin>>n;
	int i;
	adj.resize(n+5);

	int u,v;

	for(i=1;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(i=1;i<=n;i++){
		dist[i]=-1;
		sub[i]=1;
	}

	dist[1]=0;

	dfs(1);

	sub[1]--;

	for(i=1;i<=n;i++){
		cout<<sub[i]<<" ";
	}cout<<endl;





	return 0;
}