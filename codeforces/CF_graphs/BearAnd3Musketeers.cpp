/*
Here we use the fact that the number of edges is of O(n) so we iterate over the edges
*/
#include<iostream>
#include<vector>

using namespace std;


vector <vector <int> > adj;

int am[4005][4005];

int edge[4005][2];

int main(){
	int n,m;
	cin>>n>>m;
	adj.resize(n+5);
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			am[i][j]=0;
		}
	}
	int a,b;
	for(i=1;i<=m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		am[a][b]=1;
		am[b][a]=1;
		edge[i][0]=a;
		edge[i][1]=b;
	}
	int mi=1205;
	for(i=1;i<=m;i++){
		a=edge[i][0];
		b=edge[i][1];
		for(j=1;j<=n;j++){
			if(j==a||j==b)continue;

			if(am[a][j]==1&&am[b][j]==1){
				int temp=adj[a].size()+adj[b].size()+adj[j].size();
				temp-=6;
				if(temp<mi){
					mi=temp;

				}
			}
		}
	}

	if(mi==1205){
		cout<<"-1"<<endl;
	}else{

	cout<<mi<<endl;

	}


	return 0;
}