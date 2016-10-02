#include<bits/stdc++.h>

using namespace std;


int w[200005];
int h[200005];

int main(){
	
	int n;
	cin>>n;

	int wd=0;
	int hi=0;
	int ht=0;
	int i;

	for(i=0;i<n;i++){
		cin>>w[i]>>h[i];
		wd+=w[i];
		if(ht<h[i]){
			hi=i;
			ht=h[i];
		}
	}

	int h2=0;

	for(i=0;i<n;i++){
		if(i==hi)continue;

		if(h2<h[i]){
			h2=h[i];
		}
	}
	int net;

	for(i=0;i<n;i++){
		if(i==hi){
			net=h2*(wd-w[i]);
			cout<<net<<" ";
			continue;
		}

		net=ht*(wd-w[i]);
		cout<<net<<" ";
		
	}cout<<endl;


	return 0;
}