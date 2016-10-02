#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int t;

	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int i;
		string s;
		cin>>s;
		//
		int x;
		if(s[0]=='I'){
			x=200;
		}else{
			x=400;
		}
		int laddu=0;
		for(i=0;i<n;i++){
			cin>>s;
			if(s[0]=='C'){
				if(s[8]=='W'){
					int q;
					cin>>q;
					laddu+=300;
					if(q<=20){
						laddu+=20-q;
					}
				}else{
					laddu+=50;
				}

			}
			if(s[0]=='T'){
				laddu+=300;
			}
			if(s[0]=='B'){
				int z;
				cin>>z;
				laddu+=z;
			}
		}
		laddu/=x;
		cout<<laddu<<endl;


	}




	return 0;
}