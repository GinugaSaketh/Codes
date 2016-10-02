#include <iostream>
#include <cstdio>



using namespace std;


vector <vector <int > > adj;
int a[100005];

int main(){
	int n,m;
	cin>>n>>m;
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	adj.resize(n+5);
	int u,v;
	for(i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v)
;		adj[v].push_back(u);
	}
return 0;	
}