#include<bits/stdc++.h>

using namespace std;

int flag;

int a[100005];
int one,two;

vector <vector <int> > adj;

void dfs(int v){
	if(flag==1){
		return;
	}


	int u,i;

	for(i=0;i<adj[v].size();i++){
		u=adj[v][i];

		if(a[u]==a[v]){
			flag=1;
			break;
		}

		if(a[u]==0){
			if(a[v]==1){
				//cout<<u<<" dsvz"<<endl;
				a[u]=2;
				two++;
			}else{
				one++;
				a[u]=1;
			}

			dfs(u);
		}


	}


	if(flag==1){
		return;
	}




}





int main(){
	flag=0;
	int n,m;

	cin>>n>>m;

	int i;
	int x,y;

	adj.resize(n+5);

	for(i=1;i<=m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(i=1;i<=n;i++){
		a[i]=0;
	}

	a[0]=1;
	one=0;
	two=0;

	for(i=1;i<=n;i++){
		if(flag==1){
			break;
		}

		if(a[i]==0){
			a[i]=1;
			one++;
			dfs(i);
		}
	}

	if(flag==1){
		cout<<"-1"<<endl;
		return 0;
	}


	cout<<one<<endl;

	for(i=1;i<=n;i++){
		if(a[i]==1){
			cout<<i<<" ";
		}
	}cout<<endl;


	cout<<two<<endl;
	for(i=1;i<=n;i++){
		if(a[i]==2){
			cout<<i<<" ";
		}
	}cout<<endl;





	return 0;
}