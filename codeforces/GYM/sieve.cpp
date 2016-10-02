#include<bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

string s;
char mat[20][20];

char si[20][20];
int chk[20][20];



int main(){
	 
	ifstream fin ("sieve.in");
	ofstream fout("sieve.out");


	cin>>s;

	int n;
	cin>>n;
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			chk[i][j]=0;
		}


	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[i][j]=s[j+(n*i)];
		}
	}


	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>si[i][j];
		}
	}
	string net="";

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(si[i][j]=='+'){
				chk[i][j]=1;
				//cout<<mat[i][j]<<endl;
				net=net+mat[i][j];
			}
		}
	}
	int flag=1;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(si[i][j]=='+'){
				if(chk[n-i-1][j]==1){
					flag=0;
					break;
				}else{
					chk[n-i-1][j]=1;
					net+=mat[n-i-1][j];
				}
			}
		}
	}

	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(si[i][j]=='+'){
				if(chk[n-i-1][n-j-1]==1){
					flag=0;
					break;
				}else{
					chk[n-i-1][n-j-1]=1;
					net+=mat[n-i-1][n-j-1];

				}
			}
		}
	}
	

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(si[i][j]=='+'){
				if(chk[i][n-j-1]==1){
					flag=0;
					break;
				}else{
					chk[i][n-j-1]=1;
					net+=mat[i][n-j-1];
					//cout<<mat[i][n-j-1];
				}
			}
		}
	}


	//cout<<net.size()<<endl;

	if(flag==0 || s.size()>(n*n)){
		cout<<"No solution."<<endl;
		
	}else{

		if(net.size()!=s.size()){
			cout<<"No solution."<<endl;
		}else{
			cout<<net<<endl;
		}


	}








	return 0;
}