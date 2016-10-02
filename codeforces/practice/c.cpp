#include <bits/stdc++.h>
using namespace std;

int c[31][11];
long long int p[30];
int main()
{
	int n,k;
	cin>>n>>k;
	memset(c,0,sizeof(c));
	memset(p,0,sizeof(p));
	p[0]=1;
	long long int inf=1e9;
	int m=0;
	for(int i=1;;i++)
	{
		p[i]=1LL*p[i-1]*k;
		m++;
		if(p[i]>=inf)
		break;	
	}

	for(int i=1;i<=n;i++)
	{
		int a;
		long long b;
		scanf("%d",&a);
		b=a;

		for(int j=0;j<m+1;j++)
		{

				if(b==0)
					break;
				int d=b%k;

				b=b/k;
				if(d==0)continue;
				c[j][d]=(c[j][d]+1)%k;
		}
	}
	/*for(int i=0;i<=m;i++)
	{
		for(int j=0;j<k;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}*/
	long long ans=0;
	for(int i=0;i<=m;i++)
	{
		for(long long int j=0;j<k;j++)
		{
				if(c[i][j]!=0)
				ans+=(p[i]*j);
			
		}
	}

	cout<<ans<<endl;
	return 0;
}