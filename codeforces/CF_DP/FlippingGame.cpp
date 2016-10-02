#include<iostream>

using namespace std;

int a[105];
int b[105];

int main(){
	int n;
	int i;
	cin>>n;
	int p=0;
	int q=0;

	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			b[i]=-1;
			p++;
		}else{
			q++;
			b[i]=1;
		}
	}
	int j;
	
	//KADANE's algorithm

	int max_ending_here=b[0];
	int max_so_far=b[0];

	for(i=1;i<n;i++){
		max_ending_here=max(b[i],b[i]+max_ending_here);
		max_so_far=max(max_so_far,max_ending_here);
	}

	p+=max_so_far;

	cout<<p<<endl;






	/*
	if(n==p){
		p--;
		cout<<p<<endl;
		return 0;
	}


	int change=0;

	for(i=0;i<n;i++){
		
		int o=0,z=0;

		for(j=i;j<n;j++){
			if(a[j]==1){
				o++;
			}else{
				z++;
			}

			change=max(change,z-o);


		}
	}


	p+=change;

	cout<<p<<endl;

	*/







	return 0;
}