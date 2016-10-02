#include<bits/stdc++.h>

using namespace std;

#define ll long long


long double x,y,v;

int main(){
	long double a,b;

	cin>>a>>b;
	int n;
	cin>>n;
	int i;

	long double t=100000;


	for(i=0;i<n;i++){
		cin>>x>>y>>v;

		long double d=(long double)(sqrt((x-a)*(x-a)+(y-b)*(y-b)));

		d/=v;

		if(d<t){
			t=d;
		}
	}

	cout<<setprecision(12)<<t<<endl;


	return 0;
}
