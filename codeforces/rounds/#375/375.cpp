#include<bits/stdc++.h>

using namespace std;

int mo(int x){
	if(x<0)x=-x;
	return x;
}

int main(){
	int a,b,c,net;
	cin>>a>>b>>c;
	net=10000;
	int tmp;

	int i;

	for(i=1;i<=100;i++){
		tmp=(mo(i-a)+mo(i-b)+mo(i-c));
		net=min(net,tmp);
	}

	cout<<net<<endl;




	return 0;
}