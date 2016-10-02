#include<iostream>

using namespace std;


int main(){
	long long n,a,b,c,d;

	cin>>n>>a>>b>>c>>d;

	long long p,q,r,s;
	p=a+b;
	q=a+c;
	r=c+d;
	s=b+d;

	//cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;

	if(p==q&&q==r&&r==s){
		
		n=n*n;
		cout<<n<<endl;	
	}else{
		long long x=min(p,q);
		x=min(x,r);
		x=min(x,s);
		long long y=max(p,q);
		y=max(y,r);
		y=max(y,s);
		//cout<<x<<" "<<y<<endl;
		if(y+1>x+n){
			cout<<"0"<<endl;
		}else{
			long long z=x+n-y;
			n*=z;
			cout<<n<<endl;
		}

	}




	return 0;
}