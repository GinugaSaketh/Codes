#include<iostream>
#include<set>
#include<iomanip>


using namespace std;

long long a[2005];
long long dcount[5005];
long long sum[5005];

int main(){
	long long  n;
	long long i,j;
	cin>>n;
	for(i=0;i<5005;i++){
		dcount[i]=0;
	}

	for(i=0;i<n;i++){
		cin>>a[i];
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int d=a[j]-a[i];
			if(d<0){
				d=-d;
			}
			dcount[d]+=1;
		}

	}
	sum[5002]=0;
	for(i=5001;i>=0;i--){
		sum[i]+=sum[i+1]+dcount[i];
	}
	long double net=0;
	for(i=0;i<5000;i++){
		for(j=0;j<5000;j++){
			if(i+j>5000){
				continue;
			}
			long long  t=i+j+1;
			long double tnet=dcount[i]*dcount[j]*sum[i+j+1];
			tnet/=(sum[0]);
			tnet/=(sum[0]);
			tnet/=(sum[0]);
			net+=tnet;
			//cout<<sum[0]<<endl;
		}
	}

	
	cout<<setprecision(15)<<net;







	return 0;
}