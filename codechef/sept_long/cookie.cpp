#include<bits/stdc++.h>

using namespace std;

int c[105][10];
int to[105];
vector <int > v;


int main(){
	
	int t,n;
	int i,j,k,x;
	v.resize(6);
	for(i=0;i<6;i++){
		v[i]=0;
	}

	cin>>t;

	for(j=0;j<t;j++){
		cin>>n;

		for(i=1;i<=n;i++){
			cin>>to[i];
			for(k=1;k<=6;k++){
				c[i][k]=0;
			}
			for(k=1;k<=to[i];k++){
				cin>>x;
				c[i][x]++;
			}
		}

		for(i=1;i<=n;i++){
			//v.resize(0);
			for(k=1;k<=6;k++){
				v[k-1]=(c[i][k]);
			}	
			sort(v.begin(),v.end());
			to[i]=0;

			to[i]+=v[0]*10;
			for(k=1;k<6;k++){
				v[k]-=v[0];
			}
			v[0]=0;
			to[i]+=v[1]*7;

			for(k=2;k<6;k++){
				v[k]-=v[1];
			}
			v[1]=0;

			to[i]+=v[2]*5;

			for(k=3;k<6;k++){
				v[k]-=v[2];
			}
			v[2]=0;
			to[i]+=v[3]+v[4]+v[5];
		}
		int in=1;
		int ma=to[1];
		int  flag=0;

		for(i=2;i<=n;i++){
			if(ma<to[i]){
				flag=0;
				ma=to[i];
				in=i;
			}else if(ma==to[i]){
				flag=1;
			}
		}
	
		if(flag==1){
			cout<<"tie"<<endl;
		}else if(in==1){
			cout<<"chef"<<endl;
		}else{
			cout<<in<<endl;
		}


	}



	return 0;
}