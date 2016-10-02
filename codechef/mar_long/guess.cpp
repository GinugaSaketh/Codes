#include "bits/stdc++.h"
/*
#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
*/
using namespace std;

int main(){
	int n,m,c;
	cin>>n>>m>>c;
	int x;
	int a[10005];
	int l=0;
	int i,j,k;
	i=1;j=1;
	
	
	/*for(l=0;l<c;l++){
		cout
	}*/
		cout<<"2 1 1 1 1"<<endl;
		fflush(stdout);
		cin>>x;


	cout<<"3"<<endl;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(l<c){
				
				cout<<a[l]<<" ";
				l++;
				

			}else{
				cout<<"25 ";
			}
		}
		cout<<endl;
		fflush(stdout);
	}

	return 0;
}