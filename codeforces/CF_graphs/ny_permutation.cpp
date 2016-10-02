#include<iostream>
#include<vector>
using namespace std;


vector <vector <int > > adj;

int i;
int visit[305];
int mi;
char a[305][305];
int p[305];


void dfs(int v){
	//cout<<i<<" "<<v<<endl;
	/*if(v<i){
		return ;
	}*/
	if(v>i&&p[v]<p[mi]){
		mi=v;
	}

	int k;
	for(k=0;k<adj[v].size();k++){
		int u=adj[v][k];
		if(visit[u]==0){
			
			visit[u]=1;
			dfs(u);
		}
	}



}



int main(){
	int n;
	cin>>n;

	
	for(i=1;i<=n;i++){
		cin>>p[i];
	}

	int j,t;
	adj.resize(n+5);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>a[i][j];
			//cout<<a[i][j];
			if(a[i][j]=='1'&&i>j){
				//cout<<i<<" "<<j<<endl;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	

	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			visit[j]=0;
		}
		visit[i]=1;
		mi=i;
		dfs(i);
		t=p[mi];
		p[mi]=p[i];
		p[i]=t;
	}
	for(i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}cout<<endl;


	return 0;
}
