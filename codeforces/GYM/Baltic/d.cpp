#include<iostream>

using namespace std;

long long k;
long long a[100005],b[100005],c;
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

	c=b[0]/a[0];
	long long mi=c;
	for(i=1;i<n;i++){
		c=b[i]/a[i];
		if(c<mi){
			mi=c;
		}
	}

	net=mi;

	for(i=0;i<n;i++){
		b[i]-=(mi)*a[i];
	}

	
	while(k>0){
	for(i=0;i<n;i++){
		if(a[i]>b[i]){
			k-=a[i]-b[i];
		}else{
			b[i]-=a[i];
		}
	}
	
	if(k>=0){
		net++;
		x=k/a_;
		k=k-(x)*(a_);
		net+=x;
	}else{
		break;
	}
	for(i=0;i<n;i++){
		if(b[i]>x*(a[i])){
			b[i]-=x*a[i];
			k+=x*(a[i]);
		}else{
			b[i]=0;
			k+=b[i];
		}
	}

	}
	cout<<net<<endl;


	return 0;
}