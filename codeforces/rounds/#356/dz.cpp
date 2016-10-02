#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n;

	cin>>n;
	int i;

	if(n<=7){
		cout<<n<<" "<<n<<endl;
		return 0;
	}

	if(n>7&&n<15){
		cout<<"7 7"<<endl;
		return 0;
	}






 	long long s=7;

 	long long net=7;

 	for(i=2;s<n;i++){
 		s+=i*i*i;
 		net++;
 		if(n>=s&&s+8>n){
 			cout<<net<<" "<<s<<endl;
 			break;
 		}

 		if(s+8<=n&&s+(i+1)*(i+1)*(i+1)>=n){
 			net++;
 			cout<<net<<" "<<s<<endl;
 			break;


 		}


 	}









	return 0;
}