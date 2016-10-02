#include<bits/stdc++.h>

using namespace std;


vector<vector<int> > adj;

long long net=0;

long long a,b,c;
int flag3=0;
int flag2=1;


int dist[100005];



void dfs(int u){

	int v,i;
	for(i=0;i<adj[u].size();i++){
		v=adj[u][i];

		if(dist[v]==-1){
			dist[v]=dist[u]+1;
			if(dist[v]%2==0){
				a++;
			}else{
				b++;
			}
			c++;
			dfs(v);
		}else{

			if((dist[u]-dist[v])%2==0){
				flag3=1;
			}

		}

	}


}




int main(){

	long long n,m;
	cin>>n>>m;


	adj.resize(n+5);
	int i;

	int p,q;

	for(i=1;i<=m;i++){
		cin>>p>>q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}

	for(i=1;i<=n;i++){
		dist[i]=-1;
	}



	if(m==0){
		net=(n)*(n-1)*(n-2);
		net/=6LL	;
		cout<<"3 "<<net<<endl;
		return 0;
	}







	for(i=1;i<=n;i++){
		if(dist[i]==-1){
			a=0,b=0,c=0;
			a++;//even dist.
			dist[i]=0;
			c++;
			dfs(i);
			if(c>2){
				flag2=0;
			}
			net+=(a*(a-1))/2;
			net+=(b*(b-1))/2;
		}
	}


	if(flag3==1){
		cout<<"0 1"<<endl;
		return 0;
	}

	if(flag2==1){
		cout<<"2 "<<(m*(n-2))<<endl;
		return 0;
	}

	cout<<"1 "<<net<<endl;

	return 0;
}