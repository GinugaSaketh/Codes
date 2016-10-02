#include<bits/stdc++.h>

using namespace std;


int a[10];

string s;

int main(){
	int v;
	cin>>v;
	int i;

	for(i=1;i<10;i++){
		cin>>a[i];
	}

	int mi=100005;
	int d=0;

	for(i=1;i<10;i++){
		if(a[i]<=mi){
			mi=a[i];
			d=i;
		}
	}

	if(mi>v){
		cout<<"-1"<<endl;
		return 0;
	}


	int digits;
	digits=v/mi;

	v-=digits*mi;



	//v+=mi;
	int p=d;

	int j;

	for(i=0;i<digits;i++){
		v+=mi;
		//cout<<v<<endl;
		p=d;
		for(j=d;j<10;j++){
			if(a[j]<=v){
				p=j;
			}
		}
		v-=a[p];
		

		cout<<p;


	}cout<<endl;


/*
	for(i=d;i<10;i++){
		if(a[i]<=v){
			p=i;
		}
	}

	cout<<p;

	for(i=0;i<digits-1;i++){
		cout<<d;
	}cout<<endl;

*/
	return 0;
}