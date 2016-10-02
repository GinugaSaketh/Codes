#include<bits/stdc++.h>

using namespace std;

vector <pair <int,int> > h;

int stay[100005];
int left[100005];
int right[100005];


int main(){
	int i,n;

	cin>>n;
	int x,h_;

	for(i=0;i<n;i++){
		cin>>x>>h_;

		h.push_back(make_pair(x,h_));
	}

	h.push_back(make_pair(2000000005,100005));


	int net=1;

	for(i=1;i<n;i++){

		if(h[i].first-h[i].second>h[i-1].first){
			net++;
		}else if(h[i].first+h[i].second<h[i+1].first){
			net++;
			h[i].first+=h[i].second;
		}

	}



	cout<<net<<endl;






	return 0;
}