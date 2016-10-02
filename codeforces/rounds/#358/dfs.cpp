#include<bits/stdc++.h>

using namespace std;

#define ll long long

int net;


int v[100005];

vector <vector <pair<int,ll> > > adj;

int a[100005];

ll d[100005];



void dfs1(int v_){

	//cout<<v_<<" asfc"<<endl;

	net++;
	int i;
	for(i=0;i<adj[v_].size();i++){
		int u;
		u=adj[v_][i].first;
		//ll dist=adj[v][i].second;
		if(v[u]==0){
			v[u]=1;
			//d[u]=dist+max(0,d[v_]);
			dfs1(u);
		}

	}

}


void dfs(int v_){

	//cout<<v_<<" "<<a[v_]<<endl;

	if(d[v_]>a[v_]){
		dfs1(v_);
	}

	int i;

	for(i=0;i<adj[v_].size();i++){
		int u;
		u=adj[v_][i].first;
		ll dist=adj[v_][i].second;
		if(v[u]==0){
			v[u]=1;
			d[u]=dist+max(0LL,d[v_]);
			dfs(u);
		}

	}

}


int main(){

	int n;
	cin>>n;
	int i;
	for(i=0;i<=n;i++){
		v[i]=0;
	}

	adj.resize(n+5);

	

	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	int p;
	ll c;

	net=0;


	for(i=1;i<n;i++){
		cin>>p>>c;
		//i+1 and p

		adj[i+1].push_back(make_pair(p,c));
		adj[p].push_back(make_pair(i+1,c));
	}


	v[1]=1;
	d[1]=0;

	dfs(1);


	cout<<net<<endl;

	return 0;
}