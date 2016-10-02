#include<iostream>
#include<cstring>

long long mod=1e9+7;

using namespace std;


long long mmi_1[(long long)(1e5+7)];
long long mmi_2[(long long)(1e5+7)];//inverse factorial
long long fac[(long long )(1e5+7)];


long long mmi(long long n,long long pow){
	
	if(pow==0){
		return 1;
	}
	if(pow==1){
		return n;
	}

	
		long long p=mmi(n,pow/2);
		p%=mod;
		if(pow%2==0){
			p=(p*p)%mod;
			
		
		}else{
			p=(p*p)%mod;
			
			p=(p*n)%mod;
			
		
		}

		return p;
	

}




int main(){
	int t;
	cin>>t;
	long long i;
	for(i=0;i<=(long long )(1e5+5);i++){
		mmi_1[i]=mmi(i,mod-2);
	}

	mmi_2[0]=1;

	for(i=1;i<=(long long)(1e5+5);i++){
		mmi_2[i]=(mmi_1[i]*mmi_2[i-1])%mod;
	}

	fac[0]=1;
	
	for(i=1;i<=(long long)(1e5+5);i++){
		fac[i]=i*fac[i-1];

		fac[i]%=mod;
		//cout<<fac[i]<<" ";
	}
	//cout<<endl;

	while(t--){
		
		string str;
		cin>>str;
		long long alp[27];

		for(i=0;i<27;i++){
			alp[i]=0;
		}
		
		for(i=0;i<str.size();i++){
			alp[str[i]-'a']++;
		}
		long long a[27];
		int j,l,k=0;
		for(i=0;i<=26;i++){
			if(alp[i]>0){
				a[k]=alp[i];
				k++;
			}
		}

		int p=k;

		///p is size
		long long all=fac[str.size()];
		for(i=0;i<p;i++){
			all=(all*mmi_2[a[i]])%mod;
		}



		//ij
		long long ij=0;
		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				tmp+=a[j];
				tmp%=mod;
			}
			ij+=(a[i]*tmp)%mod;
			ij%=mod;
		}
		ij%=mod;

		long long ij_=0;
		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				if(a[j]>1){
				tmp+=((a[j]*(a[j]-1))/2)%mod;
				tmp%=mod;
				}
			}
			if(a[i]>1){
			long long ta=((a[i]*(a[i]-1))/2)%mod;
			ij_+=(ta*tmp)%mod;
			ij_%=mod;
			}
		}
		ij_%=mod;


		long long ijk=0;

		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				long long tmp1=0;
				for(k=j+1;k<p;k++){
					tmp1+=(a[k]);
					tmp1%=mod;
				}
				tmp+=(a[j]*tmp1)%mod;
				tmp%=mod;
			}
			ijk+=(tmp*a[i])%mod;
			ijk%=mod;
		}
		ijk=(ijk*2LL)%mod;
		ijk%=mod;


		long long ijk_=0;

		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				long long tmp1=0;
				for(k=j+1;k<p;k++){
					tmp1+=(a[k]);
					tmp1%=mod;
				}
				tmp+=(a[j]*tmp1)%mod;
				tmp%=mod;
			}
			if(a[i]>1){
			long long tl=((a[i]*(a[i]-1)))%mod;
			ijk_+=(tmp*tl)%mod;
			ijk_%=mod;
			}
		}
		
		ijk_%=mod;

		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				long long tmp1=0;
				for(k=j+1;k<p;k++){
					tmp1+=(a[k]);
					tmp1%=mod;
				}
				if(a[j]>1){
				long long tl=((a[j]*(a[j]-1)))%mod;
				tmp+=(tl*tmp1)%mod;
				tmp%=mod;
				}
			}
			
			
			ijk_+=(tmp*a[i])%mod;
			ijk_%=mod;
			
		}
		
		ijk_%=mod;


		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				long long tmp1=0;
				for(k=j+1;k<p;k++){
					if(a[k]>1){
					long long tl=((a[k]*(a[k]-1)))%mod;
					tmp1+=(tl);
					tmp1%=mod;
					}
				}
				
				
				tmp+=(a[j]*tmp1)%mod;
				tmp%=mod;
				
			}
			
			
			ijk_+=(tmp*a[i])%mod;
			ijk_%=mod;
			
		}
		
		ijk_%=mod;


		long long ijkl=0;

		for(i=0;i<p;i++){
			long long tmp=0;
			for(j=i+1;j<p;j++){
				long long tmp1=0;
				for(k=j+1;k<p;k++){
					long long tmp2=0;
					for(l=k+1;l<p;l++){
						tmp2+=a[l];
						tmp2%=mod;
					}
					tmp1+=(a[k]*tmp2)%mod;
					tmp1%=mod;
				}
				tmp+=(a[j]*tmp1)%mod;
				tmp%=mod;
			}
			ijkl+=(tmp*a[i])%mod;
			ijkl%=mod;
		}
		ijkl=(ijkl*3LL)%mod;
		ijkl%=mod;

		long long in=(all-ij-ijk-ijkl-ij_-ijk_-1LL+7LL*mod)%mod;
		long long net=(all*in)%mod;
		


		net%=mod;
		
		//cout<<all<<" "<<ij<<" "<<ijk<<" "<<ij_<<" "<<ijk_<<" "<<in;
		cout<<net<<endl;
	}



	endl 0;
}
