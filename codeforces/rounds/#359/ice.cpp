#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n;
	int i;
	ll x;

	cin>>n>>x;

	int d=0;
	char c;
	char b;
	ll y;
	
	//cout<<n<<endl;
	for(i=0;i<n;i++){
		cin>>c>>y;

		if(c=='+'){
			x+=y;
		}
		if(c=='-'){
			if(x>=y){
				x-=y;
			}else{
				d++;
			}
		}


	}


	cout<<x<<" "<<d<<endl;

	return 0;	
}