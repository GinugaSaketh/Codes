#include<bits/stdc++.h>

using namespace std;

vector <vector<int> > adj;

int dist[100005];
int par[100005];

int n,m,k;
int found=0;
int start=0;
int net=0;


void dfs(int u){
	

	int v,i;

	for(i=0;i<=adj[u].size();i++){
		if(found==1){
			break;
		}


		v=adj[u][i];
		if(dist[v]==-1){
			par[v]=u;
			dist[v]=dist[u]+1;
			dfs(v);



		}else{
			/*if(dist[u]-dist[v]>=k&&!start){
				net=v;
				start=u;
				//cout<<(dist[u]-dist[v]+1)<<endl;

				found=1;
				break;
			}*/
		}
	}

	/*if(found==1){
		cout<<u<<" ";
		if(u==net){
			found=-1;
			cout<<endl;

		}
	}*/

}


int main(){
	
	cin>>n>>m>>k;

	adj.resize(n+5);

	ll ans=0;

	int  i,j,s,t;

	for(i=0;i<m;i++){
		cin>>s>>t;
		adj[s].push_back(t);
		adj[t].push_back(s);
	}


	for(i=0;i<=n;i++){
		dist[i]=-1;
		par[i]=-1;
	}

	dist[1]=0;

	dfs(1);




	while(start!=net){
		cout<<start<<" ";

		start=par[start];

	}

	cout<<net<<endl;







	return 0;
}