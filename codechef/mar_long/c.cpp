#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i,a;
		int x=0;
		for(i=0;i<n;i++){
			cin>>a;
			x^=a;

		}
		
		//cout<<x<<endl;
		if(x==0){
			cout<<"First"<<endl;
		}else{
			if(n%2==0){
				cout<<"First"<<endl;
			}else{
				cout<<"Second"<<endl;
			}
		}

	}




	return 0;
}