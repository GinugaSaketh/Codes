#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll M=(ll)(1e9+7);

long long mod=(long long)(1e9+7);

long long a[100005];


struct matrix {
	ll m[2][2];
 
	matrix()
	{
		memset(m,0,sizeof(m));
	}
 
	matrix operator * (matrix b){
		matrix c;
 
		/*c.m[0][0]=0;
		c.m[1][0]=0;
		c.m[0][1]=0;
		c.m[1][1]=0;
        */
 
 
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					c.m[i][j]=(c.m[i][j]+(1LL*m[i][k]*b.m[k][j])%M)%M;
				}
			}
		}
		return c;
	}
	matrix operator + (matrix b){
		matrix c;
		
		for(int i =0;i<2;i++){
			for(int j=0;j<2;j++){
				c.m[i][j]=(m[i][j]+b.m[i][j])%M;
			}
		}
		return c;
 
	}
 
};

matrix net; 
matrix fib;
matrix unit;
 
 matrix modpow(matrix x,ll n){
	if(n==0){
		return unit;
	}
	if(n==1){
		return x;
	}
 
	matrix tmp=modpow(x,n/2);
	matrix net=tmp*tmp;
 
	if(n%2==1){
		net=net*x;
	}
 
	return net;
 
}
/*matrix make_matrix(ll n){
 
//..	cout<<"n here "<<n<<" ";
	matrix tm=modpow(fib,n);
///	cout<<tm.m[0][0]<<" ";
	tm=tm+unit;
//	cout<<tm.m[0][0]<<endl;
	return tm;
 
 
}*/


ll mo(ll n_,ll po){

	if(po==0){
		return 1;
	}
	if(po==1){
		return n_;
	}

	ll tm=mo(n_,po/2);
	tm*=tm;
	tm%=M;
	if(po%2==1){
		tm*=n_;
		tm%=M;
	}

	return tm;
}





int main(){
	


	int k;

	cin>>k;
	int i;
	for(i=1;i<=k;i++){
		cin>>a[i];
	}
	long long p,q;


	fib.m[0][0]=1;
	fib.m[1][0]=1;
	fib.m[0][1]=2;
	fib.m[1][1]=0;


	//a[1]--;

	unit.m[0][0]=0;
	unit.m[0][1]=1;
	unit.m[1][0]=mo(2,M-2);
	unit.m[1][1]=-mo(2,M-2);
 	

	for(i=1;i<=k;i++){
		fib=modpow(fib,a[i]);
	}
	fib=unit*modpow(unit,M-2);


	//cout<<fib.m[0][0]<<" "<<fib.m[0][1]<<endl;
	p=fib.m[0][0];

	p/=2;

	q=2;

	for(i=1;i<=k;i++){
		
		q=mo(q,a[i]);
		q%=M;
	}
	
	q*=mo(2,M-2);
	q%=M;
	


	cout<<p<<"/"<<q<<endl;













	return 0;
}