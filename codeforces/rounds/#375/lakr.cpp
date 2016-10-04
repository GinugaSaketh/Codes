#include<bits/stdc++.h>

using namespace std;



char c[55][55];
char c_[55][55];
int v[55][55];
pair<int,int> par[55][55];
set<pair<int ,pair<int,int> > > se;
set<pair<int ,pair<int,int> > >:: iterator it;
int size[55][55];

int n,m,k;

pair<int,int> find(int x,int y){
	pair<int ,int> t;
	
	if(par[x][y].first==x&&par[x][y].second==y){
		return make_pair(x,y);
	}else{
		par[x][y]=find(par[x][y].first,par[x][y].second);
	}

}

void union_(pair<int,int > a_, pair<int,int > b_){

	pair<int,int> pa=find(a_.first,a_.second);
	pair<int,int > pb=find(b_.first,b_.second);

	/*cout<<"dac "<<endl;
	cout<<(pa.first)<<" "<<(pa.second)<<endl;
	cout<<(pb.first)<<" "<<(pb.second)<<endl;
	cout<<"dac "<<endl;
	*/
	if(size[pa.first][pa.second]<size[pb.first][pb.second]){
		size[pb.first][pb.second]+=size[pa.first][pa.second];

		par[pa.first][pa.second]=pb;
	}else{
		size[pa.first][pa.second]+=size[pb.first][pb.second];

		par[pb.first][pb.second]=pa;
	}
}



void dfs(int a,int b){
	if(a>1){
		if(v[a-1][b]==0&&c[a-1][b]=='.'){
			v[a-1][b]=1;
			dfs(a-1,b);
		}
	}

	if(a<n){
		if(v[a+1][b]==0&&c[a+1][b]=='.'){
			v[a+1][b]=1;
			dfs(a+1,b);
		}
	}

	if(b>1){
		if(v[a][b-1]==0&&c[a][b-1]=='.'){
			v[a][b-1]=1;
			dfs(a,b-1);
		}
	}

	if(b<m){
		if(v[a][b+1]==0&&c[a][b+1]=='.'){
			v[a][b+1]=1;
			dfs(a,b+1);
		}
	}
}


void dfs1(int a,int b){
	if(a>1){
		if(v[a-1][b]==0&&c[a-1][b]=='.'){
			v[a-1][b]=1;
			
			dfs1(a-1,b);
			c[a-1][b]='*';
		}
	}

	if(a<n){
		if(v[a+1][b]==0&&c[a+1][b]=='.'){
			v[a+1][b]=1;

			dfs1(a+1,b);
			c[a+1][b]='*';
		}
	}

	if(b>1){
		if(v[a][b-1]==0&&c[a][b-1]=='.'){
			v[a][b-1]=1;
			dfs1(a,b-1);
			c[a][b-1]='*';
		}
	}

	if(b<m){
		if(v[a][b+1]==0&&c[a][b+1]=='.'){
			v[a][b+1]=1;
			dfs1(a,b+1);
			c[a][b+1]='*';
		}
	}
}



int main(){
	


	int i;
	cin>>n>>m>>k;

	int j;
		
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>c[i][j];
			c_[i][j]=c[i][j];
		}
	}
	/*for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<c[i][j];
		}cout<<endl;
	}*/

	for(i=0;i<55;i++){
		for(j=0;j<55;j++){
			v[i][j]=0;
		}
	}


	for(i=1;i<=n;i++){
		//j==1;
		if(c[i][1]=='.'){
			//cout<<i<<" "<<1<<endl;
			v[i][1]=1;
			dfs(i,1);
		}
	}

	for(i=1;i<=n;i++){
		if(c[i][m]=='.'&&v[i][m]==0){
			//cout<<i<<" "<<m<<endl;
			v[i][m]=1;
			dfs(i,m);

		}
	}

	for(j=1;j<=m;j++){
		if(c[1][j]=='.'&&v[1][j]==0){
			v[1][j]=1;
			dfs(1,j);
		}
	}

	for(j=1;j<=m;j++){
		if(c[n][j]=='.'&&v[n][j]==0){
			v[n][j]=1;		
			dfs(n,j);
		}
	}

	for(i=2;i<n;i++){
		for(j=2;j<m;j++){
			if(v[i][j]==0){
				if(c[i][j]=='.'){
					par[i][j]=make_pair(i,j);
					size[i][j]=1;

				}
			}else{
				size[i][j]=0;
				par[i][j]=make_pair(-1,-1);	
			}
		}
	}
	

	int lake=0;

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]=='.'&&v[i][j]==0){

				int a=i;
				int b=j;
				pair<int,int> tm=make_pair(a,b);

				if(a>1){
					if(c[a-1][b]=='.'&&c[a-1][b]=='.'){
					//v[a-1][b]=1;

						if(find(tm.first,tm.second)!=find(a-1,b));
						union_(tm,make_pair(a-1,b));
					}
				}

				if(a<n){
					if(c[a+1][b]==0&&c[a+1][b]=='.'){
					//	v[a+1][b]=1;
					//	dfs(a+1,b);
						if(find(tm.first,tm.second)!=find(a+1,b));
						union_(tm,make_pair(a+1,b));
					}
				}

				if(b>1){
					if(c[a][b-1]==0&&c[a][b-1]=='.'){
					//	v[a][b-1]=1;
					//	dfs(a,b-1);
						if(find(tm.first,tm.second)!=find(a,b-1));
						union_(tm,make_pair(a,b-1));
					}
				}


				if(b<m){
					if(v[a][b+1]==0&&c[a][b+1]=='.'){
						//cout<<"fdzv c "<<a<<" "<<b+1<<endl;
						//v[a][b+1]=1;
						if(find(tm.first,tm.second)!=find(a,b+1));
						
						union_(tm,make_pair(a,b+1));
					}
				}
			}

		}
	}





	


	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			//cout<<v[i][j];
			if(c[i][j]=='.'&&v[i][j]==0){
				//cout<<i<<" "<<j<<endl;
				pair<int,int> tmp=find(i,j);
				//cout<<tmp.first<<" "<<tmp.second<<endl;
				se.insert(make_pair(size[tmp.first][tmp.second],tmp));
			}

		}//cout<<endl;
	}
	//cout<<se.size()<<endl;;

	while(se.size()>k){

		it=se.begin();
		se.erase(it);


		dfs1(((*it).second).first,((*it).second).second);
		c[((*it).second).first][((*it).second).second]='*';
	}
			

	//cout<<se.size()<<endl;





	int dif=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]!=c_[i][j]){
				dif++;
			}
		}
	}

	cout<<dif<<endl;

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<c[i][j];
		}cout<<endl;
	}



	return 0;
}

