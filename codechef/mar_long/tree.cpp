#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define ll long long 


vector< vector <pair<int ,int > > > adj;


pair<vector<int >,vector<int > >  z;

vector <int > tp;//contains single element with 0





//int visited[100005];

int dist[100005];
int m,m1,m2,x;


vector <int > dfs(int v,int par){
	
	//cout<<v<<" node "<< adj[v].size()<<endl;

	pair <vector <int > ,vector <int > > tmp;
	tmp=z;
	if(adj[v].size()==1&&v!=1){
		//cout<<"adfv"<<endl;
		dist[v]=0;
		return tp;
	}

	for(int j=0;j<adj[v].size();j++){
		//cout<<v <<"ewfacd "<<endl;
		if(adj[v][j].first==par){
			continue;
		}
	//	cout<<v<<" "<<j<<" "<<adj[v][j].first<<" "<<adj[v][j].second<<endl;
		vector <int > tp_=dfs(adj[v][j].first,v);
		x=adj[v][j].second+((tp_.back()));
	//	cout<<adj[v][j].second<<"   dr "<<(tp_.back())<<endl;
		tp_.push_back(x);
		//cout<<(tp_.back())<<endl;
		if(((tmp.first).back())<x){
			tmp.second=tmp.first;
			tmp.first=tp_;
			//cout<<"yes 1  "<<((tmp.first).back())<<endl;
		}else if(((tmp.second).back())<x){
			tmp.second=tp_;
			//cout<<"yes 2"<<(tmp.second).back()<<endl;
		}

	}

	m1=((tmp.first).back());
	m2=((tmp.second).back());
	m=(m1+m2)/2;

	//cout<<v<<" "<<m1<<" "<<m2<<"  "<<m<<endl;
	//always gives greater than ,so if not begin check for --
	/*vector <int >::iterator it;
	it=upper_bound((tmp.first).begin(),(tmp.first).end(),m);
	//cout<<(*it)<<"    dsvsac"<<endl;
	dist[v]=max(m1+m2-(*it),*it);
	if(it!=(tmp.first).begin()){
		it--;
		dist[v]=min(dist[v],max(m1+m2-(*it),*it));
}
	*/
		dist[v]=1e9+10;
	for(int i=0;i<tmp.first.size();i++)
	{
		int w=m1-tmp.first[i]+m2;
		dist[v]=min(dist[v],max(w,tmp.first[i]));
	}	



//	for(int j=0;j<(tmp.first).size();j++){
//		cout<<(tmp.first)[j]<<" ";
//	}
//	cout<<endl;
	return tmp.first;

}


int main(){
	int n,t;
	tp.clear();
	tp.push_back(0);
	z.first=tp;
	z.second=tp;



	cin>>t;

	while(t--){
		adj.clear();
		adj.resize((ll)(1e5+5));
		cin>>n;
		int u,v,w;

		for(int i=0;i<=n;i++){
			//visited[i]=0;
			dist[i]=0;
		}

		for(int i=1;i<n;i++){
			scanf("%d%d%d",&v,&u,&w);
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}

/*		for(int i=1;i<=n;i++)s
		{
			for(int j=0;j<adj[i].size();j++)
				cout<<adj[i][j].first<<" "<<adj[i][j].second<<":::";
			cout<<endl;
		}
*/
		if(n==1)
		{
			printf("%d\n",0);
			continue;
		}	
		dfs(1,-1);

		for(int i=1;i<=n;i++){
			printf("%d\n",dist[i]);
		}
		//cout<<endl;



	}




	return 0;
}