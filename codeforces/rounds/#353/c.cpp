#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector <long long >a;

map <long long,long long > sum;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	long long n;
	cin>>n;
	int i;

	a.resize(n+5);

	
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	for(i=1;i<n;i++){
		a[i]+=a[i-1];
	}

	for(i=0;i<n;i++){
		sum[a[i]]++;
	}

	int m=0;
	for(i=0;i<n;i++){
		if(sum[a[i]]>m){
			m=sum[a[i]];
		}
	}

	n-=m;

	cout<<n<<endl;





	return 0;
}