#include<iostream>
#include<vector>

using namespace std;


int count =0;

vector <vector <int> > adj;

int visit[405];

void dfs(int v){
	//cout<<v<<endl;
	visit[v]=1;
	count++;
	int j;
	for(j=0;j<adj[v].size();j++){
		int u=adj[v][j];
		if(visit[u]==0){
			dfs(u);
		}
	}


}

int main(){
	int n,m;
	int i,j;
	cin>>n>>m;
	char c;
	adj.resize(405);

	//pt is j+m*(i-1)

	for(i=1;i<=n;i++){
		cin>>c;
		if(c=='>'){
			for(j=1;j<m;j++){
				adj[j+m*(i-1)].push_back(j+1+(m)*(i-1));
			}
		}else{
			for(j=m;j>1;j--){
				adj[j+m*(i-1)].push_back(j+m*(i-1)-1);
			}
		}
	}

	for(j=1;j<=m;j++){
		cin>>c;
		if(c=='v'){
			for(i=1;i<n;i++){
				adj[j+m*(i-1)].push_back(j+m*i);
			}
		}else{
			for(i=n;i>1;i--){
				adj[j+m*(i-1)].push_back(j+m*(i-2));
			}
		}

	}
	//dfs(1);

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			int k;
			for(k=0;k<405;k++){
				visit[k]=0;
			}
			dfs(j+m*(i-1));
		}
	}

	if(count==n*m*n*m){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}





	return 0;
}