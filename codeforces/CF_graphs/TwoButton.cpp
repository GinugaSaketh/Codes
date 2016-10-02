#include<iostream>
#include<queue>
using namespace std;


int n,m;


vector <vector<int > > adj;

queue <int> q;

int dist[200050];


void bfs(int v){
	
	q.push(v);
	dist[v]=0;

	while(!q.empty()){
		int u=q.front();
		//cout<<u<<" "<<dist[u]<<endl;
		q.pop();

		int j;
		if(u==m){
			break;
		}
		int u1=2*u;
		int u2=u-1;
		if(u2>0&&dist[u2]==-1){
			dist[u2]=dist[u]+1;
			q.push(u2);
		}

		if(u1<20050&&u1<=2*m&&dist[u1]==-1){
			dist[u1]=dist[u]+1;

			q.push(u1);
		}
		

	}


}






int main(){
	

	cin>>n>>m;
	int i;

	if(n==m){
		cout<<"0"<<endl;
	}else if(n>m){
		n-=m;
		cout<<n<<endl;

	}else{
		adj.resize(10004);
		
		
		for (i = 0; i <10005; ++i)
		{
			
			dist[i]=-1;
		}
			
		bfs(n);
		cout<<dist[m]<<endl;

	}







	return 0;
}
