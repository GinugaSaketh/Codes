#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i,j;
	long long n,c;
	for(j=0;j<t;j++){
		cin>>n>>c;
		

		if(c%n!=0){
			cout<<"No"<<endl;
			continue;
		}else{
			c/=n;
			if(n%2LL==1LL){
				long long x=(n-1)/2LL;
				c-=x;

				if(c>=1LL){
					cout<<"Yes"<<endl;
				}else{
					cout<<"No"<<endl;
				}


			}else{
				c-=n-1;

				if(c>=1LL){
					cout<<"Yes"<<endl;
				}else{
					cout<<"No"<<endl;
				}




			}
			





		}


	}


	return  0;
}