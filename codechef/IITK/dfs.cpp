#include<bits/stdc++.h>

using namespace std;

vector <vector <int> > adj;

int a[100005];
int b[100005];

int sub[100005];

int dp[100005];
int dpm[100005];
int v_[100005];


void dfs(int x){

	int i;
	//cout<<x<<endl;

	dp[x]=dpm[x]=0;	

	for(i=0;i<adj[x].size();i++){
		int y=adj[x][i];
		//cout<<y<<endl;

		if(v_[y]!=-1){
			continue;
		}

		v_[y]=1;
		dfs(y);

		sub[x]+=sub[y];
		dp[x]+=dp[y];
		dpm[x]+=dpm[y];
	}
	
	int t=dp[x];
	//cout<<t<<endl;
	dp[x]=min(dp[x],sub[x]-dpm[x]+1);
	dpm[x]=max(dpm[x],sub[x]-t+1);

	if(a[x]==b[x]){
		dp[x]+=0;
		dpm[x]+=1;
	}else{
		dp[x]+=1;
		dpm[x]+=0;
	}

	cout<<x<<" "<<dp[x]<<" "<<dpm[x]<<endl;


}


int main(){
	int n;

	cin>>n;
	adj.resize(n+5);
	int i,u,v,j;
	for(i=1;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	for(i=1;i<=n;i++){
		cin>>b[i];
	}

	//handle n=1 & n=2


	for(i=0;i<=n;i++){
		//dp[i]=1000000;
		v_[i]=-1;
		sub[i]=1;
	}
	v_[1]=0;
	dfs(1);

	cout<<dp[1]<<endl;


	return 0;
}