#include<bits/stdc++.h>

using namespace std;

int dist[200005];
int red[200005];
int ar=0;
int ans[200005];


vector <vector <pair<int,int> > > adj;


void dfs(int x){

	//cout<<x<<endl;

	int i,y;
	int r;

	for(i=0;i<adj[x].size();i++){
		y=adj[x][i].first;
		r=adj[x][i].second;
		if(dist[y]==-1){
			dist[y]=dist[x]+1;
			red[y]=red[x];
			if(r==0){
				ar++;
				red[y]++;
			}
			dfs(y);
		}
	}
}



int main(){
	int n;
	cin>>n;
	adj.resize(n+5);

	int i,u,v;
	for(i=1;i<n;i++){
		cin>>u>>v;
			
		adj[u].push_back(make_pair(v,1));
		adj[v].push_back(make_pair(u,0));
	}

	int j;

	/*for(i=1;i<=n;i++){
		for(j=0;j<adj[i].size();j++){
			cout<<adj[i][j].first<<" ";
		}cout<<endl;
	}**/



	for(i=0;i<=n;i++){
		dist[i]=-1;
		red[i]=0;
	}
	dist[1]=0;
	dfs(1);

	int mi=(300005);

	for(i=1;i<=n;i++){
		ans[i]=ar+dist[i]-2*red[i];
		mi=min(mi,ans[i]);
	}
	cout<<mi<<endl;


	for(i=1;i<=n;i++){
		if(ans[i]==mi){
			cout<<i<<" ";
		}
	}cout<<endl;





	return 0;
}