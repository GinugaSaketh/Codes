#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll a[505][505];

ll r[505],l[505];
ll d=0,d_=0;


int main(){

	int n;
	int p,q;
	int i,j;

	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				p=i,q=j;
			}
		}
	}

	for(i=0;i<n;i++){
		r[i]=l[i]=0;
	}


	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}

	ll rm=0;
	ll ri=(ll)(1e18);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			r[i]+=a[i][j];
		}
		rm=max(rm,r[i]);
		ri=min(ri,r[i]);
	}
	int net=0;
	ll x=-1;
	ll y=-1;
	for(i=0;i<n;i++){
		if(rm==r[i]){
			net++;
		}
	}

	if(net!=n-1){
		cout<<"-1"<<endl;
		return 0;
	}else{
		x=rm-ri;
	}
	ll u=rm;

	net=0;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			l[j]+=a[i][j];
		}
		rm=max(rm,l[j]);
		ri=min(ri,l[j]);
	}

	if(u!=rm){
		cout<<"-1"<<endl;;
		return	0;
	}

	for(i=0;i<n;i++){
		if(rm==l[i]){
			net++;
		}
	}
	if(net!=n-1){
	
		cout<<"-1"<<endl;
		return 0;
	}else{
		y=rm-ri;
	}

	if(x!=y){
		cout<<"-1"<<endl;
		return 0;
	}

	for(i=0;i<n;i++){
		d+=a[i][i];
	}


	if((p!=q&&d!=rm)||(p==q&&d!=rm-x)){
		cout<<"-1"<<endl;
		return 0;
	}
	d=0;


	for(i=0;i<n;i++){
		d+=a[i][n-1-i];
	}


	if((p+q!=n-1&&d!=rm)||(p+q==n-1&&d!=rm-x)){
		cout<<"-1"<<endl;
		return 0;
	}
	
	cout<<x<<endl;











	return 0;
}