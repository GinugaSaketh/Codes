#include<bits/stdc++.h>

using namespace std;


vector<int > x;




int main(){
		

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,i;
	cin>>n;
	int cost;
	for(i=0;i<n;i++){
		cin>>cost;
		x.push_back(cost);
	}


	sort(x.begin(),x.end());

	int q;
	cin>>q;

	int m;


	for(i=0;i<q;i++){
		cin>>m;
		//<=m

		vector<int>:: iterator up=upper_bound(x.begin(),x.end(),m);

		cout<<(up-x.begin())<<endl;



	}



	return 0;
}