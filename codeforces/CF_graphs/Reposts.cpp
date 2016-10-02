#include<iostream>
#include<vector>
#include<string>
using namespace std;


string s[205];	
string s2,s1;

vector <vector <int> > adj;

int dist[205];

void dfs(int v){
	//cout<<v<<" "<<s[v]<<endl;
	int u,j;
	for(j=0;j<adj[v].size();j++){
		u=adj[v][j];
		if(dist[u]==-1){
			dist[u]=dist[v]+1;
			dfs(u);
		}
	}




}

int main(){
	int n,i,j;
	s[1]="polycarp";
	adj.resize(205);
	cin>>n;
	for(i=2;i<=n+1;i++){
		cin>>s[i]>>s2>>s1;
		for(j=0;j<s[i].size();j++){
			if(s[i][j]>='A'&&s[i][j]<='Z'){
				s[i][j]=s[i][j]-'A'+'a';
			}
		}
		for(j=0;j<s1.size();j++){
			if(s1[j]>='A'&&s1[j]<='Z'){
				s1[j]=s1[j]-'A'+'a';
			}
		}

		for(j=1;j<i;j++){
			if(s1==s[j]){
				//cout<<s[j]<<endl;
				break;
			}
		}
		//cout<<s[i]<<" "<<s1<<endl;
		adj[j].push_back(i);
	}
	//n+1 nodes

	for(i=0;i<205;i++){
		dist[i]=-1;
	}

	dist[1]=0;

	dfs(1);
	int mx=0;
	for(i=1;i<=n+1;i++){
		if(dist[i]>mx){
			mx=dist[i];
		}
	}
	mx++;
	cout<<mx<<endl;



	return 0;
}

