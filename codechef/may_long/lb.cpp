#include<iostream>

using namespace std;

int main(){
	cout<<"1"<<endl;
	cout<<"3 1 2 2"<<endl;
	cout<<"3 3 4 4"<<endl;

	int x;
	cin>>x;

	cout<<"2"<<endl;
	if(x==0){
		
		cout<<"5"<<endl;
	}else{
		if(x==1){
			cout<<"1"<<endl;
		}
		if(x==2){
			cout<<"2"<<endl;
		}
		if(x==-1){
			cout<<"3"<<endl;
		}
		if(x==-2){
			cout<<"4"<<endl;
		}
	}



	return 0;
}