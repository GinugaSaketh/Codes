#include<iostream>

using namespace std;

int u[1005];
int v[1005];

int main(){
	int n,k,i;
	cin>>n>>k;
	int a,b,c,d;
	int t;
	
	cin>>a>>b>>c>>d;

		if(n==4){
			cout<<"-1"<<endl;
		}else if(k<n+1){
			cout<<"-1"<<endl;
		}else{

			cout<<a<<" ";
			cout<<c<<" ";
			for(i=1;i<=n;i++){
				if(i==a||i==b||i==c||i==d){
					continue;
				}
				cout<<i<<" ";
			}
			cout<<d<<" ";
			cout<<b<<endl;

			cout<<c<<" ";
			cout<<a<<" ";
			for(i=1;i<=n;i++){
				if(i==a||i==b||i==c||i==d){
					continue;
				}
				cout<<i<<" ";
			}
			cout<<b<<" ";
			cout<<d<<endl;

		}
	





	return 0;
}