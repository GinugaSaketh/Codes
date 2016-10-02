#include<bits/stdc++.h>

using namespace std;
char str[50];
string s;

int n,x;

char ab[10][21][50];

vector <vector <string> > abc;

vector <string > abc_;

int mx[10];

void fun(int p){
	if(p==n){
		x++;
	for(int i=0;i<n;i++){
		ab[n][x][i]=str[i];
		//cout<<str[i];
	}//cout<<endl;
	
	return ;
	}
	
	str[p]='a';
	int d,flag=1;
	for(d=1;d<n;d++){
	if(p-2*d<0){
		break;
	}
	if(str[p]==str[p-d]&&str[p]==str[p-2*d]){
		flag=0;
		break;
		
	}
	
	
	}
	if(flag==1){
		fun(p+1);
	}
	
	flag=1;
	
	str[p]='b';
	 flag=1;
	for(d=1;d<n;d++){
	if(p-2*d<0){
		break;
	}
	if(str[p]==str[p-d]&&str[p]==str[p-2*d]){
		flag=0;
		break;
		
	}
	
	
	}
	if(flag==1){
		fun(p+1);
	}


}
int mx_[35];

//ab->9==0
void fun_(int p){
	

	if(p==n){
		
		
		x++;
		
	
		abc_.push_back(s);
		//cout<<s;
		//cout<<endl;
		return ;
	}
	
	s[p]='a';
	//cout<<s<<endl;	
	int d,flag=1;
	for(d=1;d<n;d++){
	if(p-2*d<0){
		break;
	}
	if(s[p]==s[p-d]&&s[p]==s[p-2*d]){
		flag=0;
		break;
		
	}
	
	
	}
	if(flag==1){

		fun_(p+1);
	}
	
	
	
	s[p]='b';
	 flag=1;
	for(d=1;d<n;d++){
	if(p-2*d<0){
		break;
	}
	if(s[p]==s[p-d]&&s[p]==s[p-2*d]){
		flag=0;
		break;
		
	}
	
	
	}
	if(flag==1){
		fun_(p+1);
	}

	
	s[p]='c';
	
	 flag=1;
	for(d=1;d<n;d++){
	if(p-2*d<0){
		break;
	}
	if(s[p]==s[p-d]&&s[p]==s[p-2*d]){
		flag=0;
		break;
		
	}
	
	
	}
	if(flag==1){
		fun_(p+1);
	}


}

// abc max 26;

//ab 8

//a 2

int main(){
	/*n=9;
	fun(0);
	*/
	s.resize(55);
	
	for(n=1;n<=8;n++){
	x=0;
	fun(0);
	mx[n]=x;
	}
	/*for(n=1;n<=8;n++){
		cout<<mx[n]<<" ";	
	}cout<<endl;
	*/
	for(n=1;n<=26;n++){
	x=0;
	abc_.clear();
	fun_(0);
	abc.push_back(abc_);
	mx_[n]=x;
	}/*
	for(n=1;n<=26;n++){
	cout<<abc[n-1].size()<<" ";	
	}cout<<endl;
	*/
	
	
	
	int t;
	cin>>t;
	
	while(t--){
		int k,a_;
		cin>>a_>>k;
		
		string s1;
		cin>>s1;
		int net=0;
		int l=s1.size();	
		int i,j,k_;
		
		if(a_==1){
			if(l<=2){
				net++;
			}
		}
		//cout<<"dsvv z    "<<l<<endl;
		if(a_==2){
			if(l<=8){

			for(i=1;i<=mx[l];i++){
				k_=0;
				for(j=0;j<l;j++){
					if(s1[j]!=ab[l][i][j]){
						k_++;
					}
				}
				//cout<<ab[l][i]<<"   "<<i<<endl;
				if(k_<=k){
					net++;
				}
			}
			}
		}



		if(a_==3){
			if(l<=26){
			for(i=0;i<mx_[l];i++){
				k_=0;
				for(j=0;j<l;j++){
					if(s1[j]!=abc[l-1][i][j]){
						k_++;
					}

				}
				if(k_<=k){
					net++;
				}

			}
			}
		}
		
		cout<<net<<endl;
	
	
	
	
	
	
	}





return 0;
}