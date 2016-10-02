#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


int main(){
	long double r,R,h;
	cin>>r>>R>>h;
	long double r1=(R*h)/(R-r+sqrt((h*h)+(R-r)*(R-r)));

	long double r2=(r*h)/(r-R+sqrt((R-r)*(R-r)+h*h));
	h/=2.0;
	if(h<=r1&&h<=r2){
	
		cout<<setprecision(12)<<h<<endl;
	}else if(h>r1&&h>r2){
		r=max(r1,r2);
		cout<<setprecision(12)<<r<<endl;

	}else {
		r=min(r1,r2);
		cout<<setprecision(12)<<r<<endl;
	}

	





	return 0;
}