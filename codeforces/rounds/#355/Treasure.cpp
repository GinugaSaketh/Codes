#include<bits/stdc++.h>

using namespace std;

int INF=1000000005;

vector<vector <pair<pair<int,int> ,int> > >l;


int abs(int x){
	if(x>0){return x;}
	return  -x;
}

int main(){


int n, m ,p,i,j;

cin>>n>>m>>p;
	l.resize(p+1);
	int a;

	l[0].push_back(make_pair(make_pair(0,0),0));

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a;
			l[a].push_back(make_pair(make_pair(i,j),INF));
		}
	}

	int k;

	for(i=1;i<=p;i++){
		for(j=0;j<l[i].size();j++){

			for(k=0;k<l[i-1].size();k++){
				l[i][j].second=min(l[i][j].second,l[i-1][k].second+abs(l[i][j].first.first-l[i-1][k].first.first)+abs(l[i][j].first.second-l[i-1][k].first.second));
			}



		}


	}

	cout<<l[p][0].second<<endl;


	return 0;
}