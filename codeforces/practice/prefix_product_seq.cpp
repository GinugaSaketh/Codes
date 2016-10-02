// http://codeforces.com/problemset/problem/487/C
//number theory
#include<bits/stdc++.h>

using namespace std;

long long inv[100005];
long long n;

long long  inverse(long long x,long long p){
	if(x==1){
		return 1LL;
	}
	if(p==0){
		return 1LL;
	}
	if(p==1){
		return x;
	}
	long long tmp=inverse(x,p/2);
	tmp*=tmp;
	tmp%=n;
	if(p%2==1){
		tmp*=x;
		tmp%=n;
	}
	return tmp;
}




int main(){
	
	cin>>n;
	long long i;
	
	if(n<=3){
		cout<<"YES"<<endl;
		
		for(i=1;i<=n;i++){
			cout<<i<<endl;
		}

		return 0;
	}

	if(n==4){
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		cout<<"3"<<endl;
		cout<<"2"<<endl;
		cout<<"4"<<endl;
		return 0;
	}


	for(i=2;i<n&&i<1000;i++){
		if(n%i==0){
			cout<<"NO"<<endl;
			return 0;		
		}
	}	

	cout<<"YES"<<endl;

	for(i=1;i<n;i++){
		inv[i]=inverse(i,n-2);
	}

	
	long long x;
	cout<<"1"<<endl;
	for(i=2;i<=n-1;i++){
		x=(i*inv[i-1]);
		x%=n;
		cout<<x<<endl;
	}cout<<n<<endl;
	




	return 0;
}