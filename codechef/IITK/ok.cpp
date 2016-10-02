#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i;
	int n;
	for(i=0;i<t;i++){
		cin>>n;
		if(n==1){
			cout<<"NO"<<endl;
			continue;
		}


		int k=2;

		while(n%2==0){
			n/=2;
			k*=2;
		}

		if(n+1==k){
			//cout<<k<<" "<<n<<endl;
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}




	}





	return 0;
}