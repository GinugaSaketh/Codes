#include<bits/stdc++.h>

using namespace std;


int t[105];

int main(){


	int n,a;
	cin>>n>>a;
	int i;
	for(i=1;i<=n;i++){
		cin>>t[i];
	}

	int net=0;

	

	if(t[a]==1){
		net++;
	}

	for(i=1;(a+i<=n&&a-i>=1);i++){
		if(t[a+i]==1&&t[a-i]==1){
			net+=2;
		}
	}

	if(a-i<1){
		for(;a+i<=n;i++){
			if(t[a+i]==1){
				net++;
			}
		}
	}else if(a+i>n){
		for(;a-i>=1;i++){
			if(t[a-i]==1){
				net++;
			}
		}
	}

	cout<<net<<endl;



	return 0;
}