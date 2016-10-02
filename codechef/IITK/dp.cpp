#include<bits/stdc++.h>

using namespace std;

vector <vector<int> > adj;

int p[100005],q[100005];

int v[100005];
int dp[100005][2];


void dfs(int x){

	int one=0;
	int zero=0;
	int i;
	int s=0;
	if(x==1){
		s+=adj[x].size();
	}else{
		s+=adj[x].size()-1;
	}

	if(s==0){
		if(p[x]==1){
			dp[x][1]=0;
			dp[x][0]=1;
		}else{
			dp[x][1]=1;
			dp[x][0]=0;
		}
		

		return ;
	}

	int y;

	for(i=0;i<adj[x].size();i++){
		y=adj[x][i];
		if(v[y]==0){
			v[y]=1;
			dfs(y);
			one+=dp[y][1];
			zero+=dp[y][0];
		}
	}

	if(p[x]==1){

		dp[x][1]=0+one;
		dp[x][1]=min(dp[x][1],1+zero+1);
		dp[x][1]=min(dp[x][1],zero+s);

		dp[x][0]=1+zero;
		dp[x][0]=min(dp[x][0],1+one);
	
	}else{

		dp[x][0]=0+zero;
		dp[x][0]=min(dp[x][0],1+one+1);
		dp[x][0]=min(dp[x][0],one+s);

		dp[x][1]=1+one;
		dp[x][1]=min(dp[x][1],1+zero);

	}




}



int main(){
	
	int n;
	cin>>n;
	adj.resize(n+5);
	int i,a,b;
	for(i=1;i<n;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	for(i=1;i<=n;i++){
		cin>>p[i];
	}
	for(i=1;i<=n;i++){
		cin>>q[i];
		if(p[i]==q[i]){
			p[i]=0;
		}else{
			p[i]=1;
		}

	}

	for(i=1;i<=n;i++){
		v[i]=0;
	}

	//handle 1 and 2

	v[1]=1;
	dfs(1);

	/*for(i=1;i<=n;i++){
		//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}*/



	cout<<dp[1][0]<<endl;


	return 0;
}