#include <bits/stdc++.h>
using namespace std;
#define time ti
string s1,e1;
#define ll long long
struct time
{
	ll int hh,mm,ss;
}s,e;

int main()
{
	cin>>s1>>e1;
	s.hh=(s1[0]-'0')*10+(s1[1]-'0');
	s.mm=(s1[3]-'0')*10+(s1[4]-'0');
	s.ss=(s1[6]-'0')*10+(s1[7]-'0');
	if(s.hh==12&&s1[8]=='A')
		s.hh=0;
	else if(s.hh==12&&s1[8]=='P')
		s.hh=12;
	else if(s1[8]=='P')
		s.hh+=12;
	e.hh=(e1[0]-'0')*10+(e1[1]-'0');
	e.mm=(e1[3]-'0')*10+(e1[4]-'0');
	e.ss=(e1[6]-'0')*10+(e1[7]-'0');
	if(e.hh==12&&e1[8]=='A')
		e.hh=0;
	else if(e.hh==12&&e1[8]=='P')
		e.hh=12;
	else if(e1[8]=='P')
		e.hh+=12;
	ll int t=s.hh*3600LL+s.mm*60LL+s.ss;
	t*=-1LL;

	t+=(e.hh*3600LL+e.mm*60LL+e.ss);
	if(t<=0)
		t+=(24*3600LL);
	int h=t/3600;
	t=t%3600;
	int m=t/60;
	t=t%60;
	int ss=t;
	//cout<<h<<":"<<m<<":"<<ss<<endl;	
	if(h<10)
		cout<<"0"<<h<<":";

	else cout<<h<<":";
	if(m<10)
		cout<<"0"<<m<<":";
	else cout<<m<<":";
	if(t<10)
		cout<<"0"<<t<<endl;
	else cout<<t<<endl;
	return 0;
}