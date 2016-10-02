#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	long double d ,h,e,v;

	cin>>d>>h>>v>>e;

	//cout<<acos(-1)<<endl;


	long double l=(v-(acos(-1)*d*d*.25*e));
	if(l<=0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		long double r=(acos(-1)*d*d*(.25)*h);
		long double t=r/l;
		cout<<setprecision(12)<<t<<endl;
	}


	return 0;
}