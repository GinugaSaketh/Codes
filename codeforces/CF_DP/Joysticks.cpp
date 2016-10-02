#include<bits/stdc++.h>

using namespace std;


int main(){

	int a,b;

	cin>>a>>b;

	int net=0;


	if(a==1&&b==1){
		cout<<"0"<<endl;
		return 0; 
	}


	int t;

	//a is increasing and b is decreasing.

	if(a>b){
		t=a;
		a=b;
		b=t;
	}


	while(!(a<=2&&b<=2)){
	net++;	

	//cout<<a<<" "<<b<<endl;
	t=min(a,b);

	if(t<=2){
		b=a+b-t;
		a=t;

	}
	a+=1;
	b-=2;


	}

	net++;


	cout<<net<<endl;	


	return 0;
}