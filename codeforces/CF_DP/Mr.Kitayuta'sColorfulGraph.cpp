#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector <vector <vector <int> > > adj;

int visit[105];
int n,m;
int i;

int bfs(int v,int w,int col){

	for(i=1;i<=n;i++){
		visit[i]=0;
	}
	visit[v]=1;

	queue <int > q;
	q.push(v);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=0;i<adj[col][u].size();i++){
			int x=adj[col][u][i];
			if(visit[x]==0){
				visit[x]=1;
				q.push(x);
			}
		}
	}

	if(visit[w]==1){
		return 1;
	}else{
		return 0;
	}

}

int color[105];


int main(){

	cin>>n>>m;
	adj.resize(m+5);

	
	for(i=1;i<=m;i++){
		adj[i].resize(n+5);
	}
	int a,b,c;

	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		color[c]=1;
		adj[c][a].push_back(b);
		adj[c][b].push_back(a);
	}

	int query;
	cin>>query;
	int j,k;
	
	for(k=0;k<query;k++){
		cin>>a>>b;
		int net=0;

		for(j=1;j<=m;j++){
			if(color[j]==1){
				net+=bfs(a,b,j);
			}
		}
		cout<<net<<endl;
	}

	return 0;
}