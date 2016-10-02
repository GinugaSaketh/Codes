#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,h;

	cin>>n>>h;
	int i;


	int net=0;
	int a;

	for(i=0;i<n;i++){
		cin>>a;

		if(a<=h){
			net+=1;
		}else{
			net+=2;
		}


	}



	cout<<net<<endl;




	return 0;
}