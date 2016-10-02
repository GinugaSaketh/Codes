#include<iostream>

using namespace std;

long long k;
long long a[100005],b[100005],c[100005];
long long n;
long long a_;

int main(){
	cin>>n>>k;
	a_=0;
	long long x;
	long long i,net;
	for(i=0;i<n;i++){
		cin>>a[i];
		a_+=a[i];
	}

	for(i=0;i<n;i++){
		cin>>b[i];

	}

	c[0]=b[0]/a[0];
	long long mi=c[0];
	for(i=1;i<n;i++){
		c[i]=b[i]/a[i];
		if(c[i]<mi){
			mi=c[i];
		}
	}

	net=mi;

	for(i=0;i<n;i++){
		b[i]-=(mi)*a[i];
	}

	int flag=0;
	while(k>0){
		x=(k)/a_;
		
		if(x==0&&flag==1){

			break;
		}
		if(x==0)flag=1;

	for(i=0;i<n;i++){
		if((x)*a[i]>b[i]){
			k-=(x)*a[i]-b[i];
			b[i]=0;
		}else{
			b[i]-=(x)*a[i];
		}
	}if(k>=0)net+=x;
	if(k>=0&&flag==1){
		net+=1;
	}

	}
	
	
	cout<<net<<endl;


	return 0;
}