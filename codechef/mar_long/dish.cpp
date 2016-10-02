#include<iostream>

using namespace std;


int main(){
	long long d;
	cin>>d;

	while(d--){
		long long i;
		string str;
		cin>>str;
		long long n=str.size();
		if(n%2==0){
			int flag=0;//yes
			for(i=0;i<(n/2);i++){
				if(str[i]!=str[(n/2)+i]){
					flag=1;break;
				}
			}
			if(flag==1){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}



		}else{
			//firsthalf
			int flag=0;
			for(i=0;i<n/2;i++){
				if(flag==0&&i==n/2){
					flag=1;
					break;
				}
				if(flag==0){
					if(str[i]!=str[(n/2)+i+1]){
						flag=1;
					}
				}

				if(flag==1){
					if(str[i+1]!=str[(n/2)+i+1]){
						flag=2;
						break;
					}
				}

			}
			if(flag==1||flag==0){
				cout<<"YES"<<endl;
				continue;
			}

			flag=0;

			for(i=0;i<n/2;i++){
				if(flag==0&&i==n/2){
					flag=1;
					break;
				}
				if(flag==0){
					if(str[i]!=str[(n/2)+i]){
						flag=1;
					}
				}
				if(flag==1){
					if(str[i]!=str[(n/2)+i+1]){
						flag=2;
						break;
					}
				}

			}
			if(flag==1||flag==0){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}



		}


	}



	return 0;
}