#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector <vector <int > > adj;


string s[105];

int cycleFound=0;

int visit[30];

vector <int > order;



void dfs(int v){
	if(cycleFound==1){
		return;
	}
	visit[v]=1;//grey

	int k;
	for(k=0;k<adj[v].size();k++){
		int u=adj[v][k];
		if(visit[u]==1){
			cycleFound=1;
			return;
		}
		if(visit[u]==0){
			dfs(u);
		}
	}
	visit[v]=2;
	order.push_back(v);

}


int main(){

	int n;
	cin>>n;
	int i,j;

	adj.resize(30);

	for(i=1;i<=n;i++){
		cin>>s[i];
	}
	int f_=0;

	for(i=1;i<n;i++){
		int f=1;
		int l=min(s[i].size(),s[i+1].size());
		for(j=0;j<l;j++){
			if(s[i][j]!=s[i+1][j]){
				f=0;
				int x=s[i][j]-'a'+1;
				int y=s[i+1][j]-'a'+1;
				adj[x].push_back(y);

				break;
			}

		}
		if(f==1){
			if(s[i].size()>s[i+1].size()){
				f_=1;break;
			}
		}
	}

	
	if(f_==1){
		cout<<"Impossible"<<endl;
	}else{
		for(i=0;i<30;i++){
			visit[i]=0;
		}
		for(i=1;i<=26;i++){
			if(visit[i]==0){
				dfs(i);
			}
		}
		if(cycleFound==1){
			cout<<"Impossible"<<endl;

		}else{
		for(i=25;i>=0;i--){
			char c='a';
			c+=order[i]-1;
			cout<<c;
		}cout<<endl;
		}
	}



	return 0;
}