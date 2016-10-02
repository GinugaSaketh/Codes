#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int am[405][405];
int n,m;

vector <vector <int> > adj;
vector <vector < int> > adj1;
int dist[405];
queue <int > q;

void bfs(int v){
	//train->1

	dist[v]=0;
	int j;
	
	q.push(v);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(j=0;j<adj[u].size();j++){
			int w=adj[u][j];
			if(dist[w]==-1){
				dist[w]=dist[u]+1;
				q.push(w);
			}
		}

	}



}

void bfs1(int v){
	//watch out for j,j
	dist[v]=0;
	int j;
	
	q.push(v);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(j=0;j<adj1[u].size();j++){
			int w=adj1[u][j];
			//cout<<w<<" "<<u<<endl;

			if(dist[w]==-1){
				dist[w]=dist[u]+1;
				q.push(w);
			}
		}

	}


}




int main(){
	
	cin>>n>>m;
	adj.resize(n+5);
	adj1.resize(n+5);
	int u,v,i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			am[i][j]=0;
		}
	}
	for(i=1;i<=n;i++){
		dist[i]=-1;
	}

	for(i=0;i<m;i++){
		cin>>u>>v;
		am[u][v]=1;
		am[v][u]=1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){


			if(am[i][j]==0){
				adj1[i].push_back(j);
				adj1[j].push_back(i);
			}
		}
	}
	

	if(n==2){

		cout<<"-1"<<endl;
	}else if(m==0||m==(n*(n-1))/2){
		
		cout<<"-1"<<endl;
	}else{
		if(am[1][n]==0){
			dist[1]=0;
			bfs(1);


		}else{

			
			bfs1(1);
		}
		cout<<dist[n]<<endl;
	}
	

	return 0;
}