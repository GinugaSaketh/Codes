#include<bits/stdc++.h>

using namespace std;

int a[70];

long long mod=(long long )(1e9)+7;

//6 bits\

string s;

long long net=1;

long long b[10];

int main(){
	int i;
	int j;

	for(i=0;i<=63;i++){
		a[i]=0;
	}


	for(i=0;i<=63;i++){
		int l=i;

		for(j=0;j<6;j++){
			if(l%2==0){
				a[i]++;
			}
			l/=2;
		}
		
	}

	cin>>s;

	

	for(i=0;i<=8;i++){
		long long t=1;
		for(j=0;j<i;j++){
			t*=3LL;
		}

		b[i]=t;

	}



	int x;

	for(i=0;i<s.size();i++){

		if(s[i]>='0'&&s[i]<='9'){
			x=s[i]-'0';
		}else if(s[i]>='A'&&s[i]<='Z'){
			x=s[i]-'A'+10;	
		}else if(s[i]>='a'&&s[i]<='z'){
			x=s[i]-'a'+36;
		}else if(s[i]=='-'){
			x=62;
		}else if(s[i]=='_'){
			x=63;
		}

		//cout<<x<<endl;

		net%=mod;

		net*=b[a[x]];

		net%=mod;


	}

	cout<<net<<endl;





	return  0;
}