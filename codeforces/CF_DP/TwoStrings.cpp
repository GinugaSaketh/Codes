#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;

	cin>>s;

	int i,j;

	int net=0;

	for(i=0;i<s.size()-1;i++){

		if(s[i]=='A'&&s[i+1]=='B'){
			for(j=i+2;j<s.size()-1;j++){

				if(s[j]=='B'&&s[j+1]=='A'){
					net=1;
					break;
				}
			}
			if(net==0){
				net=-1;
			}
		}


		

		if(net==-1){
			break;
		}


		if(net==1){
			break;
		}
	}




	for(i=0;i<s.size()-1;i++){

		if(s[i]=='B'&&s[i+1]=='A'){
			//cout<<"sfdv"<<endl;
			for(j=i+2;j<s.size()-1;j++){

				if(s[j]=='A'&&s[j+1]=='B'){
					//cout<<"YES"<<endl;
					net=1;
					break;
				}
			}
			if(net==0){
				net=-2;
			}
		}


		

		if(net==-2){
			break;
		}


		if(net==1){
			break;
		}
	}












	if(net==1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}





	return 0;
}