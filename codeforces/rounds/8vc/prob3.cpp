#include<iostream>
#include<cmath>

using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	long long  p,q;
	p=n/3;
	q=m/2;
	if(p<q){
	q=p;///q->min;
	}
	long long  a=2*n;
	long long b=3*m;
	//long long p=min(a,b);
	long long i;
	long long m1=1e7;

	for(i=0;i<=q;i++){
		long long  x=a+2*i;
		long long y=b+3*(q-i);
		long long tm=max(x,y);
		m1=min(m1,tm);
	}
	cout<<m1<<endl;













}