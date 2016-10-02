#include<bits/stdc++.h>

using namespace std;


char a[200005];

int n,i,t;

int main(){
	
	cin>>n>>t;
	int dot=-1;

	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='.'){
			dot=i;
		}
	}
	int j;

	int flag=0;
	for(i=2;i<=n;i++){
		if(i==dot){
			continue;
		}
		if(a[i]-'0'>=5){
			//cout<<i<<endl;
			int ti=0;
			for(j=i-1;j>=1,ti<t;j--){
				if(j==dot){
					continue;
				}
				if(j==1){
					if(a[1]=='9'){
						flag=1;
						a[0]='1';
						a[1]='0';

					}

					break;
				}

				a[j]++;
				//cout<<a[j]<<endl;
				ti++;

				if(a[j]-'0'<5){
					break;
				}else{
					if(ti<t)i=j;
				}
				

			}
			//if a[1]==9
			//cout<<i<<endl;
			a[i]='x';
			break;
		}
	}


	int k;
	if(flag==1){
		if(i<dot||a[dot+1]=='x'){
			for(k=0;k<dot;k++){
				if(a[k]=='x'){
					
					if(i<dot){
						for(j=k;j<dot;j++){
							cout<<'0';
						}
			
					}
					cout<<endl;
					break;
				}



				cout<<a[k];
			}
			return 0;
		}


		for(k=0;k<=n;k++){
			if(a[k]=='x'){
				cout<<endl;
				break;
			}
			cout<<a[k];
		}

	}else{

		if(a[dot+1]=='x'){
			for(k=1;k<dot;k++){
				cout<<a[k];
			}
			cout<<endl;
		}else{
			int fl=1;
			for(k=1;k<=n;k++){
				//cout<<"YeS"<<endl;
				if(a[k]=='x'){
					
					if(k<dot){
						for(j=k;j<dot;j++){
							cout<<'0';
						}
					}
					cout<<endl;
					fl=0;
					break;
				}
				cout<<a[k];
			}if(fl==1){
				cout<<endl;
			}


		}







	}


	



	return 0;
}