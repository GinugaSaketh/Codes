#include<bits/stdc++.h>

using namespace std;

const double eps=1e-7;

 inline double abso(double a)
{
	return (a>0)?a:(-a);
}


int main(){
	

	int a,b,r;

	cin>>a>>b>>r;

	int net=0;

	int i;

	for(i=3;i<(int)1e8;i++){
		

		double rad=((double)(r)/(1.0*(double)(sin(acos(-1)/i))))-r;

		
		if(abso(a-rad)<eps){
			net++;
			continue;
		}
		if(abso(b-rad)<eps){
			net++;
			break;
		}

		if(rad>b){
			break;
		}

		if(rad<b&&rad>a){
			net++;
		}



	}



	cout<<net<<endl;








	return 0;
}