#include<iostream>

using namespace std;

long long  a[100005];

long long b;
long long b_;

int main(){
	long long n,k;

	long long i;

	
    cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	long long x;
	for(i=0;i<1000005;i++){
		b=(i*(i+1))/2;
		if(k<=b){
			x=b_;
			break;
		}
		b_=b;
	}
	x=k-x;
	
	cout<<a[x]<<endl;
	

	return 0;
}