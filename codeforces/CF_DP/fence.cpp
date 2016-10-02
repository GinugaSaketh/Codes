#include<bits/stdc++.h>

using namespace std;

int h[150005];

int main(){
	int n,k;

	cin>>n>>k;
	int i;

	int net=(int)(1e8);

	h[0]=0;

	cin>>h[1];

	for(i=2;i<=n;i++){
		cin>>h[i];
		h[i]+=h[i-1];
	}

	int index=0;

	for(i=k;i<=n;i++){
		int t=h[i]-h[i-k];

		//cout<<t<<endl;


		if(t<net){
			net=t;
			index=i;
		}
	}

	index=index-k+1;

	cout<<index<<endl;


	return 0;
}