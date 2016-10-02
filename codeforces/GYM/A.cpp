#include<bits/stdc++.h>

using namespace std;

#define cout fout
#define cin fin

vector<pair<int ,int> > a;
vector<pair<int,int> > b;

int mo(int x){
	if(x<0)x=-x;

	return x;
}


int main(){
	ifstream fin("black.in");
	ofstream fout("black.out");

	int i,n;

	cin>>n;
	int x;
	for(i=1;i<=n;i++){
		cin>>x;
		a.push_back(make_pair(x,i));
	}
	for(i=1;i<=n;i++){
		cin>>x;
		b.push_back(make_pair(x,i));
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long long net=0;
	for(i=0;i<n;i++){
		net+=mo(a[i].first-b[i].first);
	}

	cout<<net<<endl;

	for(i=0;i<n;i++){
		cout<<(a[i].second)<<" "<<(b[i].second)<<endl;
	}




	return 0;
}