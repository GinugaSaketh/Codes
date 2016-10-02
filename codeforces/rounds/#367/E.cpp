#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
	
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	while(n--)
	{
		int sum=0;
		bool posi=false;
		for(int i=1;i<=m;i++)
		{
			int t;
			scanf("%d",&t);
			sum+=t;
			if(t<=2)
				posi=true;
		}
		if(posi)continue;
		v.push_back(sum);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		if(k==1)
		{
			if(i==0)
			{
				ans=0;
				break;
			}
			if(v[i-1]==v[i])
			{
				ans=v[i];
				break;
			}
			ans=0;
			break;
		}
		k--;
	}
	/*if(k>v.size())
	{
		cout<<0<<endl;
		return 0;
	}*/
	cout<<ans<<endl;
	return 0;
}