#include<bits/stdc++.h>

using namespace std;

#define ll long long
map<ll,ll> l;
map<ll,ll> r;

ll a[200005];
ll al[200005];
ll ar[200005];


int main(){
	ll n,k;
	ll i;
	cin>>n>>k;

	for(i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		l[a[i]]=0;
		r[a[i]]=0;
		al[i]=0;
		ar[i]=0;
	}

	for(i=1;i<=n;i++){
		if(a[i]%k==0){
			ll x=a[i]/k;
			if(l.find(x)!=l.end()){
				al[i]=l[x];
			}
		}

		l[a[i]]++;
	}

	for(i=n;i>=1;i--){
		ll x=a[i]*k;
		if(x<=(ll)(1e9)){
			if(r.find(x)!=l.end()){
				ar[i]=r[x];
			}
		}
		r[a[i]]++;
	}

	ll net=0;

	for(i=1;i<=n;i++){
		//cout<<al[i]<<" "<<ar[i]<<endl;
		net+=al[i]*ar[i];
	}
	cout<<net<<endl;


	return 0;
}