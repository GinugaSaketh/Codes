#include<bits/stdc++.h>

using namespace std;


vector <string> s;

long long dp[505][505];


int main(){
	int h,w;

	cin>>h>>w;
	s.resize(h+5);

	int i,j,k,l;

	for(i=0;i<h;i++){
		//cout<<"Yes"<<endl;
		cin>>s[i];
	}

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			dp[i][j]=0;
		}
	}

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(i-1>=0){
				dp[i][j]+=dp[i-1][j];
			}

			if(i-1>=0){
				for(k=0;k<=j;k++){
					if(s[i][k]=='.'&&s[i-1][k]=='.'){
						dp[i][j]++;
					}
				}

			}

			for(k=0;k<j;k++){
				if(s[i][k]=='.'&&s[i][k+1]=='.'){
					dp[i][j]++;
				}

			}
		}
	}




	int q,r1,r2,c1,c2;
	cin>>q;

	for(i=0;i<q;i++){
		cin>>r1>>c1>>r2>>c2;

		long long net=0;

		if(r1>=2&&c1>=2){

			net+=dp[r2-1][c2-1];
			net-=dp[r2-1][c1-2];
			net-=dp[r1-2][c2-1];
			net+=dp[r1-2][c1-2];

			for(j=c1-1;j<=c2-1;j++){
				if(s[r1-1][j]=='.'&&s[r1-2][j]=='.'){
					net--;
				}
			}
			for(j=r1-1;j<=r2-1;j++){
				if(s[j][c1-1]=='.'&&s[j][c1-2]=='.'){
					net--;
				}
			}


		}else if(r1>=2&&c1==1){
			net+=dp[r2-1][c2-1];
			net-=dp[r1-2][c2-1];

			for(j=c1-1;j<=c2-1;j++){
				if(s[r1-1][j]=='.'&&s[r1-2][j]=='.'){
					net--;
				}
			}


		}else if(r1==1&&c1>=2){

			net+=dp[r2-1][c2-1];
			net-=dp[r2-1][c1-2];

			for(j=r1-1;j<=r2-1;j++){
				if(s[j][c1-1]=='.'&&s[j][c1-2]=='.'){
					net--;
				}
			}



		}else if(r1==1&&c1==1){
			net+=dp[r2-1][c2-1];

		}

		cout<<net<<endl;



	}



	return 0;
}