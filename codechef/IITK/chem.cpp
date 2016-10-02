#include<bits/stdc++.h>

using namespace std;

int a[10005];

int main(){
	int n,m;

	int i;
	cin>>n>>m;

	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	for(i=2;i<=n;i++){
		a[i]+=a[i-1];
	}

	a[0]=0;

	int l,r,x;
	int net;
	int ans=0;

	for(i=0;i<m;i++){
		cin>>l>>r>>x;

		net=a[r]-a[l-1];

		if(net>=x){
			ans++;
		}

	}


	cout<<ans<<endl;

	return 0;
}