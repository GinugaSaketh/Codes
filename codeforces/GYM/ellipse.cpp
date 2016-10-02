#include<bits/stdc++.h>

using namespace std;
#define ld long double

#define cout fout
#define cin fin



ld mo(ld x){
	if(x<0)x=-x;

	return x;
}

int main(){
	ifstream fin("ellipse.in");
	ofstream fout("ellipse.out");


	ld a,b,x1,y1,x2,y2,x3,y3,x4,y4;

	cin>>a>>b;
	cin>>x1>>y1;
	cin>>x2>>y2;

	if(a<b){
		ld tmp;
		tmp=a;
		a=b;
		b=tmp;

		tmp=x1;
		x1=y1;
		y1=tmp;

		tmp=x2;
		x2=y2;
		y2=tmp;
	}


	ld ang1,ang2;
	ld m,c;

	if(x1==x2&&x2==0){
		cout<<"1"<<endl;
		return 0;	
	}else if(x1==x2){

		x3=x4=x1;
		y3=(ld)(sqrt(a*a-x3));
		y4=-y3;

		ang1=atan(y3/x3);

		if(x3>=0){
			if(y3<0){
				ang1=2*acos(-1)-ang1;
			}
		}else{
			if(y3>=0){
				ang1=acos(-1)-ang1;
			}else{
				ang1=acos(-1)+ang1;
			}
		}


		ang2=atan(y4/x4);

		if(x4>=0){
			if(y4<0){
				ang2=2*acos(-1)-ang2;
			}
		}else{
			if(y4>=0){
				ang2=acos(-1)-ang2;
			}else{
				ang2=acos(-1)+ang2;
			}
		}




	}else{
		m=(y2-y1)/(x2-x1);
		c=(y1*x2-y2*x1)/(x2-x1);

		if(a*a*m*m+b*b-c*c<=0){
			cout<<"0"<<endl;
			return 0;
		}


		x3=(-a*a*m*c+a*b*(ld)(sqrt(a*a*m*m+b*b-c*c)))/(a*a*m*m+b*b);

		y3=(b*b*c+a*b*m*(ld)(sqrt(a*a*m*m+b*b-c*c)))/(a*a*m*m+b*b);


		x4=(-a*a*m*c-a*b*(ld)(sqrt(a*a*m*m+b*b-c*c)))/(a*a*m*m+b*b);

		y4=(b*b*c-a*b*m*(ld)(sqrt(a*a*m*m+b*b-c*c)))/(a*a*m*m+b*b);
		/*
		cout<<m<<" "<<c<<endl;

		cout<<x3<<" "<<y3<<endl;
		cout<<x4<<" "<<y4<<endl;	
		*/



		ang1=acos(mo(x3/a));


		if(x3>=0){
			if(y3<0){
				ang1=2*acos(-1)-ang1;
			}
		}else{
			if(y3>0){
				ang1=acos(-1)-ang1;
			}else{
				ang1=acos(-1)+ang1;
			}


		}




		ang2=acos(mo(x4/a));
		//cout<<ang2<<endl;
		if(x4>0){
			if(y4<0){
				ang2=2*acos(-1)-ang2;
			}
		}else{
			if(y4>0){
				ang2=acos(-1)-ang2;
			}else{
				ang2=acos(-1)+ang2;
				//cout<<"YES"<<endl;
			}
		}
	}

	//cout<<ang1<<" "<<ang2<<endl;

	ld ang=mo(ang1-ang2);


	if(ang>acos(-1)){
		ang=2*acos(-1)-ang;
	}

	ld ar1,ar2;
	ar1=(a*b/(ld)(2.0))*(ang-sin(ang));

	ar2=(acos(-1)*a*b)-ar1;

	ld net=ar1/ar2;

	//cout<<ar1<<" "<<ar2<<endl;

	cout<<setprecision(10)<<net<<endl;







	return 0;
}