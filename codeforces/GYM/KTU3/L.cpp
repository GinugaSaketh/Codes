#include<bits/stdc++.h>

using namespace std;


long long mod=(long long)(1e9)+7;



long long fast_mod(long long pow){
	if(pow==0){
		return 1;
	}

	if(pow==1){
		return 2;
	}

	long long p=fast_mod(pow/2);

	long long net=p*p;
	net%=mod;


	if(pow%2==1){
		net*=2;
		net%=mod;
	}
	return net;




}



int main(){
 	long long a;
	cin>>a;

	long long ans=fast_mod(a);

	cout<<ans<<endl;







	return 0;
}