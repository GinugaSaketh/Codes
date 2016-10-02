#include<bits/stdc++.h>

using namespace std;





int x[100005];
int y[100005];
long long  n,m,i;


int main(){
	int a,b;
	cin>>n>>m;




	long long int l=0;
	long long r=0;


	for(i=1;i<=n;i++){
		x[i]=0;
		y[i]=0;
	}
	

	for(i=0;i<m;i++){
		cin>>a>>b;

		if(x[a]==0){
			x[a]=1;
			l++;
		}
		if(y[b]==0){
			y[b]=1;
			r++;
		}
		//cout<<l<<" "<<r<<endl;
		cout<<(n*n-(l+r)*n+l*r)<<" ";
	}cout<<endl;






	return 0;
}