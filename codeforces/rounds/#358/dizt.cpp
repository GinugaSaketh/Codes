#include<iostream>

using namespace std;

pair<long long ,long long> p;


int main(){
	int n;
	long long s;

	cin>>n>>s;
	int i;


	for(i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;

	}

	int i;

	int u=0,v=0;
	long long dist=0;

	for(i=0;i<n;i++){

		for(j=i+1;j<n;j++){
			long long d=(p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second);
			if(d>dist){
				u=i;
				v=j;
				dist=d;
			}

		}


	}


	




}