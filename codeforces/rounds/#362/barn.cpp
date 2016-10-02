#include<bits/stdc++.h>

using namespace std;


string s;


int main(){


	cin>>s;

	int i;

	//0.0e10
	int net=3;


	if(s[0]=='0'&&s[1]=='.'&&s[2]=='0'&&s[3]=='e'){
		cout<<"0"<<endl;
		return 0;
	}

	int k;




	for(i=0;i<s.size();i++){
		if(s[i]=='e'){
			net=i;
			
			i=s.size()-1;

			int	t=1;
			k=0;
			while(i!=net){
				k+=(s[i]-'0')*t;
				//cout<<(s[i]-'0')<<endl;
				t*=10;
				i--;
			}
		}
	}
	//cout<<net<<endl;
	//cout<<k<<endl;

	if(k==0){
		for(i=0;i<net;i++){
			cout<<s[i];
		}cout<<endl;
		return 0;
	}



	if(s[0]=='0'){
		int num=0;

		for(i=2;i<=k+1;i++){
			if(i>=net){
				cout<<"0";
				continue;
			}
			cout<<s[i];
			num++;
		}

		if(k+2<net){
			cout<<".";
			for(i=k+2;i<net;i++){
				cout<<s[i];
			}
		}
		cout<<endl;
	}else{
		cout<<s[0];


		for(i=2;i<=k+1;i++){
			if(i>=net){
				cout<<"0";
				continue;
			}
			cout<<s[i];
		}
		if(k+2<net){
			cout<<".";
			for(i=k+2;i<net;i++){
				cout<<s[i];
			}	
		}

		cout<<endl;




	}






	return 0;
}