#include<iostream>

using namespace std;

int main(){
	int n,d,h;
	int i;
	cin>>n>>d>>h;
	if(d-h>h){
		cout<<"-1"<<endl;
	}else{
		if(h==1&&d==1){
			if(n>2){
			cout<<"-1"<<endl;
			}else{
				cout<<"1 2"<<endl;
			}
		}else if(d==2&&h==1){
			for(i=2;i<=n;i++){
				cout<<"1 "<<i<<endl;
			}
		}else{
			if(d==h){
				for(i=1;i<=h;i++){
					cout<<i<<" "<<(i+1)<<endl;
				}
				for(i=h+2;i<=n;i++){
					cout<<"2 "<<i<<endl;
				}


			}else{
				for(i=1;i<=h;i++){
					cout<<i<<" "<<(i+1)<<endl;
				}
				cout<<"1 "<<(h+2)<<endl;
				for(i=h+2;i<d+1;i++){
					cout<<i<<" "<<(i+1)<<endl;
				}
				for(i=d+2;i<=n;i++){
					cout<<"1 "<<i<<endl;
				}
			}
		}
	}




	return 0;
}