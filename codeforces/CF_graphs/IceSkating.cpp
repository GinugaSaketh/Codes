#include<iostream>
#include<vector>

using namespace std;

int pt[105][2];
//x->0 y->1

int visit[105];

vector <vector <int > > x;
vector < vector <int > > y;

void dfs(int v){
	//cout<<"wdfav  "<<v<<endl;
	int u,j;
	int x_=pt[v][0];
	int y_=pt[v][1];
    //cout<<x_<<" "<<y_<<endl;
	for(j=0;j<x[x_].size();j++){
		if(visit[x[x_][j]]==0){
			visit[x[x_][j]]=1;
			dfs(x[x_][j]);
		}
	}
	for(j=0;j<y[y_].size();j++){
		if(visit[y[y_][j]]==0){
			visit[y[y_][j]]=1;
			dfs(y[y_][j]);
		}
	}
	

}



int main(){
	int n,i;
	cin>>n;
	x.resize(1005);
	y.resize(1005);

	for(i=0;i<n;i++){
		cin>>pt[i][0]>>pt[i][1];
		x[pt[i][0]].push_back(i);
		y[pt[i][1]].push_back(i);
	}

	for(i=0;i<n;i++){
		visit[i]=0;
	}
	int net=0;
	for(i=0;i<n;i++){
		if(visit[i]==0){
			//cout<<i<<endl;
			net++;
			visit[i]=1;
			dfs(i);
		}
	}

	net--;
	cout<<net<<endl;




	return 0;
}
