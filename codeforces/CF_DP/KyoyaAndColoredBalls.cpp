#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll mod=(ll)(1e9+7);


ll modpow(ll q,ll p){
	//cout<<"YES"<<endl;
	
	if(q==0){
		return 1; 
	}
	if(q==1){
		return p;
	}

	ll x=modpow((q/2LL),p);

	if(q%2LL==0){
		ll net=x*x;
		net%=mod;
		return net;
	}else{
		ll net=x*x;
		net%=mod;
		net*=p;
		net%=mod;
		return net;
	}	
}

ll inv[1005];

int a[1005];

int b[1005];

int main(){
	int n;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	a[0]=0;
	b[0]=0;
	b[1]=0;
	for(i=2;i<=n;i++){
		b[i]=a[i-1]+b[i-1];
	}

	inv[0]=1;
	inv[1]=1;

	for(i=2;i<1005;i++){

		inv[i]=modpow(mod-2,i);
	}

	ll net;
	net=1;

	/*for(i=1;i<=n;i++){
		cout<<a[i]<<" "<<b[i]<<endl;
	}*/

	for(i=1;i<=n;i++){
		
		for(j=1;j<=a[i]+b[i]-1;j++){
			net*=j;
			net%=mod;
		}
		for(j=1;j<=a[i]-1;j++){
			net*=inv[j];
			net%=mod;
		}
		for(j=1;j<=b[i];j++){
			net*=inv[j];
			net%=mod;
		}



	}



	cout<<net<<endl;


	return 0;
}