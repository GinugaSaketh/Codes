#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int mi,ma;
	mi=ma=n/7;
	mi*=2;
	ma*=2;
	int x=(n)%7;
	if(x==6){
		mi+=1;
		ma+=2;
	}else if(x==1){
		ma+=1;
	}else if(x!=0){
		ma+=2;
	}

	

	cout<<mi<<" "<<ma<<endl;


}