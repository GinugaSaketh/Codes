#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int s=0,f=0;

	int n;
	cin>>n;

	int i;
	string a;
	cin>>a;
	for(i=0;i<n-1;i++){
		if(a[i]==':'){
			if(a[i+1]==')'){
				s++;
			}
			if(a[i+1]=='('){
				f++;
			}
		}
		if(a[i]=='('){
			if(a[i+1]==':'){
				s++;
			}
		}
		if(a[i]==')'){
			if(a[i+1]==':'){
				f++;
			}
		}
	}
	if(s==f){
		cout<<"BORED"<<endl;
	}
	if(s>f){
		cout<<"HAPPY"<<endl;
	}
	if(s<f){
		cout<<"SAD"<<endl;
	}

	return 0;
}