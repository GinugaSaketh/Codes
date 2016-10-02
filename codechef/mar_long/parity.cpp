#include<iostream>
#include<vector>


#define INF 1e5+7

using namespace std;

vector <vector < int> >  adj;
vector <pair< pair <int ,int >,pair<int ,int> > > qry;
vector<int> euler;
vector <int > euler_d;

vector <int > d;
vector <int > foc;


void dfs(int v,int p = -1){
	euler.push_back(v);
	vector <int > :: iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++){
		if(p - *it)
		{
			d[*it]=d[v]+1;
			dfs(*it,v), euler.push_back(v);
			euler_d.push_back(d[v]);
		}
	}
}


int main(){
	int t;
	cin>>t;

	while(t--){

		int n,q;
		d.clear();
		d.resize(n+5);
		
		d[1]=0;
		
		cin>>n>>q;
		adj.clear();
		adj.resize(n+5);

		int i,j;
		int u,v;
		for(i=1;i<=n-1;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		qry.clear();
		qry.resize(q+5);
		int x;
		pair <pair<int ,int >,pair<int, int > > tmp;
		for (i = 1;i<=q;i++)
		{
			cin>>u>>v>>x;
			(tmp.first).first=u;
			(tmp.first).second=v;
			(tmp.second).first=x;
			qry.push_back(tmp);
		}

		/*vector <int>:: iterator it;
		for(i=1;i<=n;i++){
			cout<<i<<"-> ";
				
				
			for(it=(adj[i]).begin();it!=(adj[i]).end();++it){
				cout<<*it<<" ";
			}
			cout<<endl;
		}*/

		euler_d.clear();
		euler.clear();
		dfs(1,-1);
		foc.clear();
		foc.resize(n+5,INF);
		int net=0;
		vector <int > :: iterator it;

		for(i=0,it=euler.begin();it!=euler.end()&&net<n;i++,it++){  //i ->0 indexed
			if(foc[*it]==INF){
				foc[*it]=i;
				net++;
			}
		}

		


	}


	return 0;
}