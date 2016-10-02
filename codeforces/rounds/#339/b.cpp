#include<iostream>

using namespace std;

long long a[100005];

int main(){
	long long n;
	cin>>n;
	long long max=-1;

	long long s=0;
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
		if(a[i]>max)max=a[i];

	}

	long long net=2*max-s+1;

	cout<<net<<endl;








	return 0;
}