#include<bits/stdc++.h>

using namespace std;

long long mod=(long long)(1e9+7);



int main(){
	int n;
	cin>>n;
	int i;
	long long pa,pb,a,b;
	//a 1 b 0

	pa=1,pb=0;

	for(i=0;i<n;i++){
		a=3*pb;
		a%=mod;
		b=2*pb+pa;
		b%=mod;
		pa=a;
		pb=b;
	}

	cout<<pa<<endl;




	return 0;
}