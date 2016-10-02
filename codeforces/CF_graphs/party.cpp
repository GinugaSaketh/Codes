#include<iostream>
#include<vector>
using namespace std;

int p[2005];

int mx;

vector<vector<int> >  adj;

int dist[2005];

void dfs(int v){
	int j;
	for(j=0;j<adj[v].size();j++){
		int u=adj[v][j];
		if(dist[u]==-1){
			dist[u]=dist[v]+1;
			if(dist[u]>mx){
				mx=dist[u];
			}
			dfs(u);
		}

	}
}


int main(){
	int n;
	cin>>n;
	mx=0;

	int i;
	adj.resize(n+5);
	for(i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]!=-1)adj[p[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		dist[i]=-1;
	}

	//dfs

	for(i=1;i<=n;i++){
		if(p[i]==-1){
			dist[i]=0;
			dfs(i);
		}
	}
	mx++;
	cout<<mx<<endl;


	







	return 0;
}