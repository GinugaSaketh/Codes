#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > v;


int a[1000005];

long long b[1000005];

int main(){

	v.resize(1000005);
	int i,j;
	for(i=1;i<=1000000;i++){
		a[i]=1;
	}
	a[0]=0;



	for(i=2;i<=1000000;i++){
		if(a[i]==1){
			a[i]=2;

			for(j=2;i*j<=1000000;j++){
				v[i*j].push_back(i);
				a[i*j]=0;
			}
		}
	}

	for(i=2;i<=1000000;i++){
		if(a[i]==0){
			a[i]=1;
			b[i]=

			for(j=0;j<v[i].size();j++){
				a[i]+=a[i/v[i][j]];
			}
		}
	}

	int t;

	cin>>t;

	int n;

	for(i=0;i<t;i++){
		cin>>n;
		
	}








	return 0;
}