#include<iostream>

using namespace std;

long long mi(long long a,long long b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}



int main(){
	long long t;
	cin>>t;
	long long r,b,g,k;

	while(t--){
		cin>>r>>b>>g;
		cin>>k;

		long long net=0;

		net+=mi(r,k-1);
		net+=mi(b,k-1);
		net+=mi(g,k-1);

		net++;
		cout<<net<<endl;



	}



	return 0;
}