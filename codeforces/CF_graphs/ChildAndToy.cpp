#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int energy[1005];

int adj[1005][1005];

vector <pair<int,int > > v;

int main(){
	int n,m,i,x,y,j;

	cin>>n>>m;

	for(i=1;i<=n;i++){
		cin>>x;
		energy[i]=x;
		v.push_back(make_pair(x,i));
	}

	sort(v.begin(),v.end());


	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			adj[i][j]=0;
		}
	}

	for(i=0;i<m;i++){
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}

	int net=0;
	for(i=n-1;i>=0;i--){
		int k=v[i].second;
		
		for(j=1;j<=n;j++){
			
			if(adj[k][j]==1){
				adj[k][j]=0;
				adj[j][k]=0;
				net+=energy[j];
			}
		}

	}

	cout<<net<<endl;




	return 0;
}