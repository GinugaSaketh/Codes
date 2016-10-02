#include<iostream>
#include<cstring>
#include<set>


using namespace std;

int dp[20005][2];


set <string> str;
string s1;



int main(){
	string s;
	cin>>s;

	int n=s.size();
	//dp 1 indexed

	dp[1][0]=0;
	dp[1][1]=0;
	if(n>6){
		dp[2][0]=1;
		dp[2][1]=0;
	}else{
		dp[2][0]=0;
		dp[2][1]=0;
	}

	if(n>7){
	
		dp[3][1]=1;
		dp[3][0]=0;
	}else{
		dp[3][1]=0;
		dp[3][0]=0;
	}

	int i;
	for(i=4;i<=n-5;i++){
		//2
		if(dp[i-2][1]==1){
			dp[i][0]=1;
		}else if(dp[i-2][0]==1) {
			
			if((s[n-i]==s[n-i+2])&&(s[n-i+1]==s[n-i+3])){
				dp[i][0]=0;
			}else{
				dp[i][0]=1;
			}
		}else{
			dp[i][0]=0;
		}

		if(dp[i-3][0]==1){
			dp[i][1]=1;
		}else if(dp[i-3][1]==1) {
			
			if((s[n-i]==s[n-i+2])&&(s[n-i+1]==s[n-i+3])&&(s[n-i+2]==s[n-i+4])){
				dp[i][1]=0;
			}else{
				dp[i][1]=1;
			}
		}else{
			dp[i][1]=0;
		}

	}

	/*for(i=1;i<=n-5;i++){
		cout<<dp[i][1]<<" ";
	}*/
	for(i=1;i<=n-5;i++){
		if(dp[i][0]==1){
			s1="";
			s1+=s[n-i];
			s1+=s[n-i+1];
			str.insert(s1);
			s1="";
		}
		if(dp[i][1]==1){
			s1="";
			s1+=s[n-i];
			s1+=s[n-i+1];
			s1+=s[n-i+2];
			str.insert(s1);
			s1="";
		}
	}

	cout<<str.size()<<endl;

	set<string> ::iterator it;

	it=str.begin();

	while(it!=str.end()){
		cout<<(*it)<<endl;
		it++;
	}


	return 0;
}