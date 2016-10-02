#include<iostream>

using namespace std;

int main(){
	int t;
	int n,m;
	cin>>t;

	while(t--){
		cin>>n>>m;
		int i;

		int net=0;
		int u,v;
		for (int i = 0; i <m; ++i)
		{
			cin>>u>>v;

			if(u==1&&v==n){
				net=1;
			}
		}

		if(net==1){
			cout<<"Jorah Mormont"<<endl;
		}else{
			cout<<"Khal Drogo"<<endl;
		}


		


	}




	return 0;
}