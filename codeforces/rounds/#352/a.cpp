#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str [2005];

int main(){

	int n;
	cin>>n;
	if(n<=9){
		cout<<n<<endl;
	}else if(n>9&&n<=189){
		n-=9;
		int m=n/2;
		if(n%2==0){
			int x=m+9;
			x%=10;
			cout<<x<<endl;
		}else{
			int x=m+10;
			x/=10;
			cout<<x<<endl;
		}

	}else if(n>189&&n<=1000){
		n-=189;
		int m=n/3;
		if(n%3==0){
			int x=m+99;
			x%=10;
			cout<<x<<endl;
		}else if(n%3==2
			){
			int x=m+100;
			x/=10;
			x%=10;
			cout<<x<<endl;
		}else{
			int x=m+100;
			x/=10;
			x/=10;
			cout<<x<<endl;
		}
	}





	return 0;
}