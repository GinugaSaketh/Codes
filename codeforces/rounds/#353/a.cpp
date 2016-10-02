#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;

	b-=a;

	if(c==0){
		if(b==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}else{
		if(c>0){
			if(b>=0){
				if(b%c==0){
					cout<<"YES"<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}else{
				cout<<"NO"<<endl;
			}
		}else{
			if(b<=0){
				
				if(b%c==0){
					cout<<"YES"<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}else{
				cout<<"NO"<<endl;
			}
		}
	}




	return 0;
}