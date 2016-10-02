#include<iostream>

using namespace std;

int a[100005];


int main(){
	int n;
	cin>>n;
	int i;

	for(i=0;i<n;i++){
		cin>>a[i];
	}

	int l=0;
	int j;
	
	for(i=0;i<n;i++){
		int flag=0;
		for(j=i;j<n;j++){
			if(a[j+1]<a[j]){
				l=max(l,j-i+1);
				flag=1;
				i=j;
				break;

			}

		}

		if(flag==0){
			l=max(l,j-i);
		}


	}


	cout<<l<<endl;



	return 0;
}