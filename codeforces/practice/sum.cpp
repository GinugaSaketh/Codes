#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,short>

map<int,short> mp;


vector <vector <int> > v;


long long a[30];

int main(){
	int n,k,j,i,x;



	v.resize(30);


	cin>>n>>k;


	if(n>=15){
		int val=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		
		if(k>2){
		mp[a]++;

		if(mp[a]==k)
			mp[a]=0;
		}

		else
			val=val^a;
	}
	
	/*sort(a,a+n);
	int cnt=1;
	for( i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
			cnt++;
		else
		{
			if(cnt%k==0)
			{
				cnt=1;
				continue;
			}
			cout<<a[i-1]<<endl;
			return 0;
		}
	}
	cout<<a[n-1]<<endl;
	*/

	if(k==2)
	{
		cout<<val<<endl;
		return 0;
	}

	for(map<int,short>::iterator it=mp.begin();it!=mp.end();it++)
	{
		int c=it->second;
		if(c!=0)
		{
			cout<<(it->first)<<endl;
			return 0;
		}
	}
	
	return 0;

	}



	for(i=0;i<30;i++){
		v[i].resize(k,0);
	}

	a[0]=1;

	for(i=1;i<30;i++){
		a[i]=a[i-1]*k;
	}


	long long z;

	for(i=0;i<n;i++){
		scanf("%d",&x);
		z=x;
		for(j=0;j<10;j++){
			if(z<a[j]){
				break;
			}

			int y=x%k;

			v[j][y]+=1;
			v[j][y]%=k;
			x/=k;
		}
	}

	long long net=0;

	long long l=1;




	for(i=0;i<30;i++){
		for(j=0;j<k;j++){
			if(v[i][j]!=0){
				//cout<<i<<" "<<j<<" "<<v[i][j]<<endl;

				net+=l*j;
				//break;
			}
		}

		l*=k;
	}

	//net/=(n%k);

	cout<<net<<endl;



	return 0;
}