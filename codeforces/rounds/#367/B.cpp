#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ld c,dc,t,dt,n;
int main()
{
	cin>>c>>n>>dc>>dt;
	ld a=(100.0-dt)/100.0;
	ld l=log(a);
	ld ans=(-1.0/l)-(c/dc);
	if(ans<0)
	{
		cout<<0<<" "<<(int)n<<endl;
		return 0;
	}
	ld p=(int)ans;
	p+=1;
	if(p-ans<(ans-p+1))
		cout<<(int)p<<" "<<(int)(n-p)<<endl;
	else cout<<(int)(p-1)<<" "<<(int)(n-p+1)<<endl;
	return 0;
}