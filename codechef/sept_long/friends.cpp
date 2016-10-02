#include<bits/stdc++.h>

using namespace std;

int adj[1005][1005];
int c[1005];
int flag,n,m;

void dfs(int a){
	if(flag==0){
		return ;
	}
	int i;

	for(i=1;i<=n;i++){
		if(i==a){
			continue;
		}
		if(adj[a][i]==1){
			if(c[i]==0){
				c[i]=(2*c[a])%3;
				dfs(i);
			}else if(c[i]==c[a]){
				flag=0;
				break;
			}
		}
	}

	if(flag==0){
		return ;
	}



}


int main(){
	int t;
	cin>>t;
	int i,j,k;
	int u,v;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				adj[i][j]=1;
			}
		}

		for(i=0;i<m;i++){
			cin>>u>>v;
			adj[u][v]=0;
			adj[v][u]=0;
		}

		/*
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout<<adj[i][j]<<" ";
			}cout<<endl;
		}*/

		for(i=1;i<=n;i++){
			c[i]=0;
		}
		
		flag=1;

		for(i=1;i<=n;i++){
			if(flag==0)break;
			if(c[i]==0){
				c[i]=1;
				dfs(i);
			}
		}

		if(flag==0){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}



	}






	return 0;
}