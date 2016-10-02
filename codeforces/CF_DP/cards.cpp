#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;


int main(){
	
	int b=0,r=0,g=0;
	int n;
	cin>>n;
	char c;
	int i;

	for(i=0;i<n;i++){
		cin>>c;
		if(c=='B'){
			b++;
		}if(c=='R'){
			r++;
		}
		if(c=='G'){
			g++;
		}
	}

	if((b>=2&&r>=2)||(b>=2&&g>=2)||(r>=2&&g>=2)){
		cout<<"BGR"<<endl;
	}else{
		if(b>=1&&g==0&&r==0){
			cout<<"B"<<endl;
		}
		if(b==0&&g>=1&&r==0){
			cout<<"G"<<endl;
		}
		if(b==0&&g==0&&r>=1){
			cout<<"R"<<endl;
		}
		if(b>=2&&g==1&&r==1){//n 1 1
			cout<<"BGR";
		}
		if(b==1&&g==1&&r>=2){//n 1 1
			cout<<"BGR";
		}
		if(b==1&&g>=2&&r>=1){//n 1 1
			cout<<"BGR";
		}

		//2 1 0
		if(b>=2&&g==1&&r==0){
			cout<<"GR"<<endl;
		}
		if(b==1&&g>=2&&r==0){
			cout<<"BR";
		}
		if(b==0&&g>=2&&r==1){
			cout<<"BR";
		}
		if(b==0&&g==1&&r>=2){
			cout<<"BG";
		}
		if(b>=2&&g==0&&r==1){
			cout<<"GR";
		}
		if(b==1&&g==0&&r>=2){
			cout<<"BG";
		}
		if(b==1&&g==1&&r==1){
			cout<<"BGR";
		}
		if(b==1&&g==1&&r==0){
			cout<<"R";
		}
		if(b==1&&g==0&&r==1){
			cout<<"G";

		}
		if(b==0&&g==1&&r==1){
			cout<<"B";
		}




	}
	


	return 0;
}