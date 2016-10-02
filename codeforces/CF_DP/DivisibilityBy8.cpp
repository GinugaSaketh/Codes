#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int ne;
	int net=0;

	int i,j,k;
	int l;

	string n;
	cin>>n;

	int number=0;

	for(i=0;i<n.size();i++){
		if(n[i]=='0'){
			net=1;
			break;
		}
	}

	if(net==1){
		cout<<"YES"<<endl;
		cout<<number<<endl;
		return 0;
	}

	for(i=1;i<125;i++){
		int num=i*8;
		//cout<<num<<endl;
		int tm=num;
		string snum="000";

		for(j=0;j<3;j++){
			int x=num%10;
			//cout<<x<<"  fdfsc"<<endl;
			num/=10;
			char c='0';
			c+=x;
			snum[2-j]=c;
		}

		
		k=0;
		while(snum[k]=='0'&&k<3){
			k++;
		}
		//cout<<k<<endl;

		//cout<<snum<<endl;

		for(l=0;l<n.size();l++){
			if(snum[k]==n[l]){
				k++;
			}

			if(k==3){
				net=1;
				
				number=tm;
				//cout<<tm<<endl;
				break;
			}
			

		}

		//cout<<net<<endl;

		ne=net;
		if(ne==1){
			break;

		}

	

	}

	if(net==1){
		cout<<"YES"<<endl;
		cout<<number<<endl;
	}else{
		cout<<"NO"<<endl;
	}






	return 0;
}