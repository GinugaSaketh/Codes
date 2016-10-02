#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;

	cin>>t;
	int i;
	long long n,b,m;
	for(i=0;i<t;i++){
		cin>>n>>b>>m;
		long long net=0;

		while(n!=0){
			//cout<<n<<" "<<m<<endl;

			if(n==1){
				net+=m;
				break;
			}
			if(n%2LL==0){
				net+=(n/2LL)*m;
				n-=(n/2LL);
				net+=b;
				m*=2LL;
				//cout<<net<<" "<<n<<endl; 
			}else{
				net+=((n+1)/2LL)*m;
				n-=(n+1)/2LL;
				net+=b;
				m*=2LL;
				//cout<<net<<" "<<n<<endl;
			}


		}
		cout<<net<<endl;


	}

	return 0;
}