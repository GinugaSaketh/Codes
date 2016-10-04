#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int >
#define pb push_back
#define mp make_pair

int adj[205][205];
int si[205];

int net[205][205];
int t;
int n,m;		
int vi[205];

void dfs(int u){
	
	int v;

	int i=u;
	int j;
	for(j=1;j<=n;j++){
		if(adj[i][j]==1&&vi[j]==0){
			//cout<<u<<" "<<j<<endl;
			vi[j]=1;
			if(net[i][j]==0&&net[j][i]==0){
				net[i][j]=1;
			}
			dfs(j);
		}else if(adj[i][j]==1&&vi[j]==1){
			if(net[i][j]==0&&net[j][i]==0){
				net[i][j]=1;
			}
		}



	}
}


int main(){
	int i,u,v,j;
	cin>>t;
	while(t--){
		
		for(i=1;i<=n;i++){
			vi[i]=0;
		}
		cin>>n>>m;
		//adj.resize(n+5);
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				adj[i][j]=0;
				net[i][j]=0;
			}
		}

		for(i=1;i<=n;i++){
			si[i]=0;
		}

		for(i=0;i<m;i++){
			cin>>u>>v;
			si[u]++;
			si[v]++;
			adj[u][v]=1;
			adj[v][u]=1;
		}

		for(i=1;i<=n;i++){
			if(vi[i]==0){
				//cout<<"dacxz"<<endl;
				vi[i]=1;
				dfs(i);
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(si[i]%2==0){
				ans++;
			}
		}
			/*for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					cout<<adj[i][j]<<" ";
				}cout<<endl;
			}*/

		cout<<ans<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				//cout<<net[i][j]<<" ";
				if(net[i][j]==1){
					cout<<i<<" "<<j<<endl;
				}
			}//cout<<endl;
		}




	}	










	return 0;
}