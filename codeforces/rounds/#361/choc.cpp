#include<bits/stdc++.h>

using namespace std;
#define ll long long




int main(){

	long long m;
	cin>>m;
	ll mid;
	ll l,r;
	ll i;
	ll ans=-1;

	l=1;
	r=(ll)(1e18+5);
	ll net;
	while(l<=r){
		//cout<<l<<" "<<r<<endl;
		if(l==r){
			net=0;
			for(i=2;i<=(ll)(1e6);i++){
			
				if((l/(i*i*i))==0){
					break;
				}
				net+=(l/(i*i*i));
			}	
			
			if(net==m){
				if(ans==-1){
					ans=l;
				}else{
					ans=min(ans,l);
				}
			}


			break;

		}

		net=0;
		mid=(l+r)/2;

		for(i=2;i<=(ll)(1e6);i++){
			if((mid/(i*i*i))==0){
				break;
			}
			net+=(mid/(i*i*i));
		}	

		if(net==m){
			if(ans==-1){
				ans=mid;
			}else{
				ans=min(ans,mid);
			}
			r=mid-1;
			continue;

		}

		if(net<m){
			l=mid+1;
		}else if(net>m){
			r=mid-1;
		}	

	}

	cout<<ans<<endl;






	return 0;
}