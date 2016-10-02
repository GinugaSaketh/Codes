#include<bits/stdc++.h>

using namespace std;


vector <vector <int> > adj;
 
long double ct[100005];
int p[100005];
long double sub[100005];

int v[100005];


void dfs(int v_){
	int i;
	int u;
	for(i=0;i<adj[v_].size();i++){
		u=adj[v_][i];
		if(v[u]==-1){
			v[u]=1;
			dfs(u);
			sub[v_]+=sub[u];
		}


	}	
}


void dfs1(int v_){

	if(v_!=1){
		ct[v_]=ct[p[v_]]+(1+sub[p[v_]]-sub[v_])/((long double)(2.0));
	}


	int i;
	int u;
	for(i=0;i<adj[v_].size();i++){
		u=adj[v_][i];
		if(v[u]==1){
			v[u]=0;
			dfs1(u);
			//sub[v_]+=sub[u];
		}


	}


}





int main(){
	int n;

	cin>>n;
	int i;
	int q;
	adj.resize(n+5);
	for(i=2;i<=n;i++){
		cin>>q;
		p[i]=q;

		adj[q].push_back(i);
		adj[i].push_back(q);
	}


	for(i=1;i<=n;i++){
		v[i]=-1;
		sub[i]=1;
	}
	v[1]=1;

	dfs(1);
	ct[1]=1;
	v[1]=0;
	dfs1(1);

	for(i=1;i<=n;i++){
		cout<<setprecision(9)<<ct[i]<<" ";
	}cout<<endl;


	return 0;
}