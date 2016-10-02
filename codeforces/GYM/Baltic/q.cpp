#include<iostream>
#include<iomanip>
#include<cstdio>


using namespace std;

long double x,y;
long double net;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin>>n;

	while(n--){

		cin>>x>>y;
		//scanf("%Lf %Lf",&x,&y);
		y++;
		net=(y-x)/(x);
		net/=y;

		cout<<setprecision(12)<<net<<"\n";
		//printf("%.11Lf\n",net);
	}





	return 0;
}