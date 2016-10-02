#include<bits/stdc++.h>

using namespace std;
#define bin bin212

long double A,B,R;
const long double eps=1e-6;
int flag;

//<=
long double abso(long double a)
{
	return (a>0)?a:(-a);
}
int bin(int l,int r,long double b){

	
	if(l>r)
	{
		return (l-1);
	}
	//cout<<l<<" "<<r<<endl;
	int m1=(l+r)/2;
	long double mid=m1;

	long double x=(long double)(sin(acos(-1)/mid));

	long double rad=((long double)(R)/(1.0*x))-R;

	//cout<<rad<<" "<<b<<endl;	

	

	if(abso(b-rad)<eps){
	//	cout<<"YES"<<endl;
		flag++;
		return (int)mid;
	}

	/*if(l==r){
		return l;
	}*/
	int y;
	if(b<rad){
		mid-=1;
		x=(long double)(sin(acos(-1)/mid));
		rad=((long double)(R)/(x))-R;
		if(abso(b-rad)<eps){
			flag++;
			return (int)mid;
		}

		if(b>rad){
			return mid;
		}


		return bin(l,m1-1,b);
	}else{
		mid+=1;
		x=(long double)(sin(acos(-1)/mid));
		rad=((long double)(R)/(1.0*x))-R;
		if(abso(b-rad)<eps){
			flag++;
			return (int)mid;
		}

		if(b<rad){
			return (mid-1);
		}




		return bin(m1+1,r,b);
	}





}



int main(){

		cin>>A>>B>>R;

	int l_=3;
	int r_=(int)(1e5);
	//int l_=6,r_=6;
	//	flag=0;
	int p=bin(l_,r_,B);

	int net=0;
	flag=0;

	//cout<<"GAP"<<endl;
	//cout<<A<<" "<<B<<" "<<R<<endl;
	int q=bin(l_,r_,A);

	if(flag==1){
		net+=1;
	}

	//cout<<p<<" "<<q<<endl;

	net+=p-q;

	cout<<net<<endl;

}