#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	/*int a[5]={5,2,1,3,4};

	sort(a,a+4);
	int i;

	for(i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
*/
	int t;
	cin>>t;

	while(t--){
		int a[1005];

		int n;
		cin>>n;

		int i;
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		sort(a,a+n);

		/*for(i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	*/
		int net=0;
		for(i=0;i<n/2;i++){
			net-=a[i];
			net+=a[n-i-1];
		}
		cout<<net<<endl;

		
	}

	

	return 0;
}