#include<bits/stdc++.h>

using namespace std;

int main(){
	


	int t,x,s;

	cin>>t>>s>>x;

	x-=t;

	if(x<0){
		cout<<"NO"<<endl;
	}else{
		if(x==1){
			cout<<"NO"<<endl;
			return 0;
		}

		if(x%s==0||x%s==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}



	}








	return 0;
}