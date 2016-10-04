#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;

	cin>>n;
	cin>>s;
	int i;
	int flag=0;
	int o=0;
	int in=0;
	int l=0;
	s="_"+s;
	s=s+"_";
	for(i=0;i<=n+1;i++){
		//cout<<l<<" ";
		if(s[i]=='_'){
			if(flag==1){
				if(l>0){
					in++;
				}
				//in=max(in,l);
				l=0;
			}else{
				o=max(o,l);
				l=0;
			}

		}else if(s[i]=='('){
			
			o=max(o,l);
			l=0;
			flag=1;
		}else if(s[i]==')'){
			if(l>0){
				in++;
			}
			//in=max(in,l);
			l=0;
			flag=0;
		}else{
			l++;
		}
	}//cout<<endl;

	cout<<o<<" "<<in<<endl;


	return 0;
}