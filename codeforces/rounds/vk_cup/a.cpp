#include<iostream>


using namespace std;


int main(){
	int n;
	int i;
	cin>>n;
	int t[100];

	int t_=0;




	for(i=0;i<n;i++){
		cin>>t[i];
	}
	if(t[0]>=16){
		t_=15;
		cout<<t_<<endl;
	}else{
		t_=t[0];
		int flag=0;
		for(i=1;i<n;i++){
			if(t[i]-t[i-1]-1>=15){
				t_+=15;
				flag=1;
				break;
			}
			t_=t[i];
		}

		if(flag!=1){
			if(90-t[n-1]-1>=15){
				t_+=15;
			}else{
				t_=90;
			}
		}
		cout<<t_<<endl;




	}



	return 0;
}