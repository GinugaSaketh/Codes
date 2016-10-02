#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i,j;
	long long n,c;
	for(j=0;j<t;j++){
		cin>>n>>c;

		if(n%2==1){
			if(c%n!=0){
				cout<<"No"<<endl;
			}else{
				c/=n;

				c-=(n-1)/2LL;

				if(c>=1){
					cout<<"Yes"<<endl;
				}else{
					cout<<"No"<<endl;
				}

			}

		}else{
			long long x=n/2LL;




			if(n%x!=0){
				cout<<"No"<<endl;
			}else{
				
				c/=x;

				if(c%2==0){
					c/=2;
					if(c>=n){
						cout<<"Yes"<<endl;
						continue;
					}else{
						cout<<"No"<<endl;
						continue;
					}


				}




				c-=(n-1);

				if(c%2==1){
					cout<<"No"<<endl;
				}else{
					if(c>=2){
						cout<<"Yes"<<endl;
					}else{
						cout<<"No"<<endl;
					}


				}




			}	





		}



	}

	return 0;

}

