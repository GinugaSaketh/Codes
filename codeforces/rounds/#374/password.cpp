#include<bits/stdc++.h>

using namespace std;

int a[105];


vector<string > s;
string s_;

int main(){

	int n,k;

	int i;
	cin>>n>>k;
	for(i=0;i<105;i++){
		a[i]=0;
	}
	s.resize(n+5);


	for(i=0;i<n;i++){
		cin>>s[i];
		a[s[i].size()]++;
	}

	cin>>s_;

	int l=s_.size();

	int net=0;
	for(i=0;i<l;i++){
		net+=a[i];
	}

	int ex=net%k;
	int net_=0;
	net_=net+(net/k)*5;
	int mi,ma;

	mi=net_+1;

	int same=0;
	int si=0;

	for(i=0;i<n;i++){
		if(s_==s[i]){
			same++;
		}

	}


	net+=a[l]-same+1;

	ma=net+((net-1)/k)*5;

	cout<<mi<<" "<<ma<<endl;








	return 0;
}