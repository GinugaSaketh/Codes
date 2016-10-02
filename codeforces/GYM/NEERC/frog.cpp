#include<bits/stdc++.h>

using namespace std;
#define x first
#define y second
//#define fin cin
//3#define fout cout


vector<pair<long double,long double> > a;

long double dp[1005][2];


long double d[1005][1005];


int main(){
	

	ifstream fin("froggy.in");
	ofstream fout("froggy.out");

	long double inf=2e18;

	int w,n;

	fin>>w>>n;

	int a_,b_;
	long double p,q;
	int i;

	for(i=0;i<n;i++){
		fin>>a_>>b_;

		a.push_back(make_pair((long double)(a_),(long double)(b_)));
	}

	a.push_back(make_pair(0,0));

	a.push_back(make_pair((long double)(w),0));

	sort(a.begin(),a.end());

	



	int j;
	for(i=1;i<=n;i++){

		for(j=i+1;j<=n;j++){

			d[i][j]=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			d[j][i]=d[i][j];
		}
	}

	for(i=1;i<=n+1;i++){
		d[0][i]=d[i][0]=(a[i].x*a[i].x);
	}

	for(i=0;i<=n;i++){
		d[i][n+1]=d[n+1][i]=((long double)(w)-a[i].x)*((long double)(w)-a[i].x);
	}


	dp[0][0]=0;

	for(i=1;i<=n+1;i++){
		dp[i][0]=inf;
		if(i==n+1){
			for(j=i-1;j>=0;j--){
				if(j==0){
					dp[i][0]=min(dp[i][0],a[i].x*a[i].x);
					continue;
				}

				dp[i][0]=min(dp[i][0],max(dp[j][0],((long double)w-a[j].x)*((long double)w-a[j].x)));
			}
			continue;
		}
		for(j=i-1;j>=0;j--){
			if(j==0){
				dp[i][0]=min(dp[i][0],a[i].x*a[i].x);
				continue;
			}


			dp[i][0]=min(dp[i][0],max(d[i][j],dp[j][0]));
		}
	}

	p=0.5;

	q=0;

	dp[n+1][1]=0;

	for(i=n;i>=0;i--){
		dp[i][1]=inf;
		if(i==0){

			for(j=1;j<=n+1;j++){

				if(j==n+1){
					dp[i][1]=min(dp[i][1],(long double)(w)*(long double)(w));

					continue;
				}

				dp[i][1]=min(dp[i][1],max(dp[j][1],max(dp[j][1],a[j].x*a[j].x)));

			}
			continue;
		}



		for(j=i+1;j<=n+1;j++){
			if(j==n+1){
				dp[i][1]=min(dp[i][1],((long double)w-a[i].x)*((long double)w-a[i].x));
				continue;
			}


			dp[i][1]=min(dp[i][1],max(d[i][j],dp[j][1]));
		}
	}


	long double s=inf;



	long double net;

	for(i=0;i<=n+1;i++){
		for(j=i+1;j<=n+1;j++){

			net=max(dp[i][0],dp[j][1]);

			net=max(net,(d[i][j])/(long double)(4.0));
			//cout<<s<<" "<<net<<endl;
			if(net<s){
				//cout<<a[i].x<<" ds "<<a[j].x<<endl;
				s=net;
				p=(a[i].x+a[j].x)/(long double)(2.0);
				q=(a[i].y+a[j].y)/(long double)(2.0);
			}
		}
	}

	fout<<setprecision(6)<<p<<" "<<q<<endl;




	return 0;
}