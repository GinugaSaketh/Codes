#include<bits/stdc++.h>

using namespace std;
int a;
int c[105];
vector<pair<int,int> > b;

int main(){
	int n;
	cin>>n;
	int a;
	int i;

	int s=0;
	for(i=0;i<n;i++){
		cin>>a;
		s+=a;
		b.push_back(make_pair(a,i+1));
	}	
	s/=n;
	s*=2;
	//cout<<s<<endl;
	int j;


	for(i=0;i<n;i++){
		c[i]=0;
	}

	sort(b.begin(),b.end());
	int x,y;
	for(i=0;i<n/2;i++){
		cout<<(b[i].second)<<" "<<(b[n-i-1].second)<<endl;



	}




	return 0;
}
