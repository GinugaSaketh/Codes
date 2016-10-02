#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> f;

int main(){
	int n,m,i;

	cin>>n>>m;

	

	for(i=0;i<m;i++){
		int y;
		cin>>y;
		f.push_back(y);
	}

	sort(f.begin(),f.end());

	int mi=4000;

	for(i=0;i<m;i++){
		if(i+n-1>=m)break;

		int x=f[i+n-1]-f[i];
		if(x<mi){
			mi=x;
		}
	}

	cout<<mi<<endl;



	return 0;
}
