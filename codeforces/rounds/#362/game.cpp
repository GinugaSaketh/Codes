#include<bits/stdc++.h>

using namespace std;


long long mod=(long long)(1e9+7);

vector <int> v;
vector <int> a; 
vector <int> tp;

//vector <long long> invfac;
//vector <long long> fac;

long long inv(long long x,long long po){
	if(po==0){
		return 1;
	}
	if(po==1){
		return x;
	}
	long long tmp=inv(x,(po/2));
	if(po%2==0){
		tmp*=tmp;
		tmp%=mod;
	}else{
		tmp*=tmp;
		tmp%=mod;
		tmp*=x;
		tmp%=mod;
	}
	return tmp;
}




	
int main(){
	int t;
	int n,k,i,j;
	scanf("%d",&t);

	k=1;

	for(i=0;i<=17;i++){
		tp.push_back(k);
		k*=2;
	}
	long long p=1;

	//cout<<"fac"<<endl;
/*
	fac.push_back(1);
	for(i=1;i<=1000000;i++){
		p*=i;
		p%=mod;
		//cout<<p<<endl;
		fac.push_back(p);
	}

	//cout<<"invfac"<<endl;

	invfac.push_back(1);
	invfac.push_back(1);
	for(i=2;i<=10;i++){
		p*=inv(i,mod-2);
		p%=mod;
		//cout<<p<<endl;
		invfac.push_back(p);
	}
*/
	while(t--){
		scanf("%d%d",&n,&k);
		v.resize(0);
		a.resize(0);
		for(i=0;i<n;i++){
			scanf("%d",&j);
			v.push_back(j);
		}


		for(i=0;i<n;i++){
			if(v[i]>=17){
				a.push_back(0);
				continue;
			}

			if(tp[v[i]]>i){
				a.push_back(0);
			}else{
				a.push_back(1);
			}
		}

		for(i=0;i<n;i++){
			if(a[i]==1){
				a[i]=0;
				int flag=1;
				for(j=1;j<=100005;j++){
					if(i-(tp[v[i]])*(j)<0){
						break;
					}

					if(a[i-(tp[v[i]])*(j)]==0){
						flag=0;
						break;
					}
				}

				if(flag==0){
					a[i]=1;
				}else{
					a[i]=0;
				}
			}
		}
		int net=0;

		for(i=0;i<n;i++){
			net+=a[i];
			cout<<a[i]<<" ";
		}cout<<endl;
		//check if net==n
 

		cout<<"net"<<" = "<<net<<endl;

		long long ans=0;

		long long full=inv(n-net,k-1);

		long long lsq=inv(n-net,mod-2);
		lsq*=lsq;
		lsq%=mod;
			
		long long nsq=net*net;
		nsq%=mod;

		long long ke=k;
		ke*=full;
		ke%=mod;
		ke*=net;
		ke%=mod;


		for(i=1;i<=k;i+=2){
			//cout<<ke<<endl;
			ans+=ke;

			ans%=mod;


			if(k-i>0){
				ke*=k-i;
				ke%=mod;
			}

			if(k-i-1>0){
				ke*=k-i-1;
				ke%=mod;
			}


			if(i+1<=k){
				ke*=inv(i+1,mod-2);
				ke%=mod;
			}
			if(i+2<=k){
				ke*=inv(i+2,mod-2);
				ke%=mod;
			}

			ke*=nsq;
			ke%=mod;
			ke*=lsq;
			ke%=mod;

			/*
			//multiply kCi
			calc=fac[k]*invfac[i];
			calc%=mod;
			calc*=invfac[k-i];
			calc%=mod;
			//cout<<calc<<endl;
			calc*=pf;
			calc%=mod;
			ans+=calc;
			ans%=mod;
			//update pf

			pf*=nsq;
			pf%=mod;
			pf*=lsq;
			pf%=mod;
			*/
	
		}

		cout<<ans<<endl;




	}

	











	return 0;
}