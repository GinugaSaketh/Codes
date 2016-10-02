#include<bits/stdc++.h>

using namespace std;

int a[300];
int x;


string s;

int main(){
	int n;

	cin>>n;
	x=n;
	int i;
	cin>>s;

	int net=0;

	for(i=0;i<=256;i++){
		a[i]=0;
	}


	for(i=0;i<s.size();i++){
		if(a[s[i]]==0){
			a[s[i]]=1;
			//cout<<s[i]<<endl;
			net++;
		}
	}

	for(i=0;i<=256;i++){
		a[i]=0;
	}
	//cout<<net<<endl;

	int l=0;
	int r=0;

	int ans=s.size();

	int count=0;

	while(l<s.size()){

		if(r==s.size()){
			for(i=l;i<s.size();i++){
				if(count==net){
					ans=min(ans,r-i);
					if(ans==net){
						break;
					}
				}
			}
			break;
		}

		//cout<<a[s[r]]<<" !@! "<<s[r]<<" "<<r<<endl;
		if(a[s[r]]==0){
			a[s[r]]++;
			count++;
			//cout<<count<<" "<<l<<" "<<r<<endl;
			if(count==net){
				ans=min(ans,r-l+1);
				if(ans==net){
					break;
				}
				
				//l++;
				//cout<<s[l]<<endl;
				a[s[l]]--;
				//cout<<a[s[l]]<<endl;
				if(a[s[l]]==0){
					//cout<<"y"<<endl;
					count--;
				}
				l++;
				a[s[r]]=0;
				count--;

			}else{
				r++;
			}

		}else{
			a[s[r]]++;
			r++;
		}


	}


	cout<<ans<<endl;
	return 0;
}