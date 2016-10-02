#include<bits/stdc++.h>

using namespace std;


int a[1000005][2];




int main(){



		ifstream fin("adjustment.in");
		ofstream fout("adjustment.out");
		long long n,q;

		fin>>n>>q;

		long long cs=(n*(n+1))/2;
		long long rs=(n*(n+1))/2;

		long long c=n;
		long long r=n;
		char s;
		int t,i;
		long long net;

		for(i=0;i<=n;i++){
			a[i][0]=a[i][1]=0;
		}

		for(i=0;i<q;i++){
			fin>>s;
			fin>>t;

			if(s=='R'){

				if(a[t][0]==1){
					fout<<"0"<<endl;
					continue;
				}

				net=t*(c)+cs;
					
				fout<<net<<endl;

				rs-=t;
				r--;
				a[t][0]=1;

			}else{

				if(a[t][1]==1){
					fout<<"0"<<endl;
					continue;
				}

				net=t*(r)+rs;

				fout<<net<<endl;
				cs-=t;
				c--;

				a[t][1]=1;


			}










		}









	return 0;
}