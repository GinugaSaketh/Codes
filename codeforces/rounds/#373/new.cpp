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
	a[0]='1';
	int in,k;


	for(i=2;i<=n;i++){
		if(i==dot){
			continue;
		}

		if(a[i]-'0'>=5){
			//cout<<i<<endl;

			in=i;
			int ti=0;
			for(j=i-1;j>=1,ti<t;j--){
				if(j==dot){
					continue;
				}
				if(j==1){
					if(a[1]=='9'){
						//flag=1;
						a[0]='1';
						a[1]='0';

					}

					if(j+1==dot){
						a[j+2]='x';
					}else{
						if(j+1<dot)a[j+1]='0';
						else if(j+1>dot)a[j+1]='x';
					}

					for(i=0;i<dot;i++){
						cout<<a[i];
					}cout<<endl;
					return 0;

					break;
				}
				//cout<<j<<endl;
				a[j]++;
				
				if(j+1==dot){
					a[j+2]='x';
				}else{
					if(j+1<dot)a[j+1]='0';
					else if(j+1>dot)a[j+1]='x';
				}
				//cout<<a[j]<<endl;
				ti++;

				if(a[j]-'0'<5||ti==t){
					if(j>dot){

						for(i=1;i<=j;i++){
							cout<<a[i];
						}cout<<endl;

						return 0;

					}else{

						for(i=1;i<=j;i++){
							cout<<a[i];
						}
						for(i=j+1;i<dot;i++){
							cout<<"0"<<endl;
						}
						cout<<endl;


						return 0;
					}




					break;
				}
				

			}
			//a[i]='x';
			break;
		}
	}

	int x,y;

	for(i=1;i<=n;i++){
		cout<<a[i];
	}cout<<endl;










	return 0;
}