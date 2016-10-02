#include<iostream>
#include<vector>

using namespace std;

int visited[30005];

vector <vector <int > > adj; 


void dfs(int v){

	int j;
	
	for(j=0;j<adj[v].size();j++){
		int u=adj[v][j];

		if(visited[u]==0){
			dfs(u);
		}

	}

	visited[v]=1;
	



}



int main(){
	int n,t;
	
	cin>>n>>t;

	int i,a;

	adj.resize(n+5);

	for(i=1;i<n;i++){
		cin>>a;
		adj[i].push_back(i+a);//directed from i to a+i
	}

	for(i=1;i<=n;i++){
		visited[i]=0;
	}

	dfs(1);

	if(visited[t]==0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}



	return 0;
}