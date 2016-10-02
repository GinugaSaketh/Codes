
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>

#define MAXN 1000005



#define ll long long

ll mi(ll a,ll b){
	if(a>b){
		return b;
	}else{
		return a;
	}
} 

ll INF=(ll)(1e16);

using namespace std;

ll a[(ll)(1e6+7)];
ll sa[(ll)(1e6+7)];

ll ab(ll a){
	if(a>0){
		return a;
	}else{
		return -a;
	}
}


int main(){
	int t;
	cin>>t;

	ll i;


	while(t--){
		ll n;
		cin>>n;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);

			//cin>>a[i];
		}

		sort(a,a+n);
		sa[0]=a[0];
		for(i=1;i<n;i++){
			sa[i]=sa[i-1]+a[i];
		}

		/*for(i=0;i<n;i++){
			cout<<a[i]<<" ";

		}cout<<endl;
		*/

		ll net=INF;
		
		ll
 			
			
		for(i=1;i<=1;i++){
				ll ts=0;
				//ll j;
				/*for(j=0;j<n;j++){
					ts+=mi(ab(a[j]-ls),ab(a[j]-rs));//00
				}*/
					ll llb,rlb,xlb;

					llb=(lower_bound(a,a+i,ls)-(a+1));
					if(llb+1<n&&a[llb+1]==ls){
						llb++;
					}
					rlb=(lower_bound(a+i,a+n,rs)-(a+1));
					if(rlb+1<n&&a[rlb+1]==rs){
						rlb++;
					}

					xlb=(lower_bound(a,a+n,x)-(a+1));
					if(xlb+1<n&&a[xlb+1]==x){
						xlb++;
					}

					//cout<<llb<<" "<<xlb<<" "<<rlb<<endl;
					ts+=((llb-0+1)-(xlb-llb))*ls+sa[xlb]-2*sa[llb];
					//cout<<ts<<" ";
					ts+=((rlb-xlb)-(n-1-rlb))*rs+sa[n-1]-sa[xlb]-2*(sa[rlb]-sa[xlb]);
					//cout<<ts<<" "<<ls<<" "<<rs<<endl;
					net=mi(net,ts);ts=0;	

					ls++;

					llb=(lower_bound(a,a+i,ls)-(a+1));
					if(llb+1<n&&a[llb+1]==ls){
						llb++;
					}
					rlb=(lower_bound(a+i,a+n,rs)-(a+1));
					if(rlb+1<n&&a[rlb+1]==rs){
						rlb++;
					}

					xlb=(lower_bound(a,a+n,x)-(a+1));
					if(xlb+1<n&&a[xlb+1]==x){
						xlb++;
					}

					//cout<<llb<<" "<<xlb<<" "<<rlb<<endl;
					ts+=((llb-0+1)-(xlb-llb))*ls+sa[xlb]-2*sa[llb];
					//cout<<ts<<" ";
					ts+=((rlb-xlb)-(n-1-rlb))*rs+sa[n-1]-sa[xlb]-2*(sa[rlb]-sa[xlb]);
					//cout<<ts<<" "<<ls<<" "<<rs<<endl;
					net=mi(net,ts);ts=0;	


					rs--;

					llb=(lower_bound(a,a+i,ls)-(a+1));
					if(llb+1<n&&a[llb+1]==ls){
						llb++;
					}
					rlb=(lower_bound(a+i,a+n,rs)-(a+1));
					if(rlb+1<n&&a[rlb+1]==rs){
						rlb++;
					}

					xlb=(lower_bound(a,a+n,x)-(a+1));
					if(xlb+1<n&&a[xlb+1]==x){
						xlb++;
					}

					//cout<<llb<<" "<<xlb<<" "<<rlb<<endl;
					ts+=((llb-0+1)-(xlb-llb))*ls+sa[xlb]-2*sa[llb];
					//cout<<ts<<" ";
					ts+=((rlb-xlb)-(n-1-rlb))*rs+sa[n-1]-sa[xlb]-2*(sa[rlb]-sa[xlb]);
					//cout<<ts<<" "<<ls<<" "<<rs<<endl;
					net=mi(net,ts);ts=0;	
			
					/*ls--;

					llb=(lower_bound(a,a+i,ls)-(a+1));
					if(llb+1<n&&a[llb+1]==ls){
						llb++;
					}
					rlb=(lower_bound(a+i,a+n,rs)-(a+1));
					if(rlb+1<n&&a[rlb+1]==rs){
						rlb++;
					}

					xlb=(lower_bound(a,a+n,x)-(a+1));
					if(xlb+1<n&&a[xlb+1]==x){
						xlb++;
					}

					//cout<<llb<<" "<<xlb<<" "<<rlb<<endl;
					ts+=((llb-0+1)-(xlb-llb))*ls+sa[xlb]-2*sa[llb];
					//cout<<ts<<" ";
					ts+=((rlb-xlb)-(n-1-rlb))*rs+sa[n-1]-sa[xlb]-2*(sa[rlb]-sa[xlb]);
					//cout<<ts<<" "<<ls<<" "<<rs<<endl;
					net=mi(net,ts);ts=0;	
		*/
		}

		if(n==1||n==2){
			net=0;
		}

		cout<<net<<endl;





	}





	return 0;
}