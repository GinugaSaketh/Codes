#include<iostream>
#include<set>
#include<vector>

using namespace std;

set <pair<int,int> > s;

int a[100005][2];

int chk[100005][2];



int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int i;
	cin>>n;

	for(i=0;i<=100005;i++)
	{
		chk[i][0]=0;
		chk[i][1]=0;
	}

	cin>>a[0][0];

	chk[0][0]=1;
	chk[0][0]=1;


	s.insert(make_pair(a[0][0],0));

	set <pair<int,int> >::iterator itu;
	set <pair<int,int> >::iterator itl;
	for(i=1;i<n;i++){
		cin>>a[i][0];
		itu=s.upper_bound(make_pair(a[i][0],0));
		itl=s.lower_bound(make_pair(a[i][0],0));
		if(itl==s.end()){
			itl--;
			chk[itl->second][1]=0;
			chk[i][0]=1;
			chk[i][1]=1;
			a[i][1]=itl->first;
			s.insert(make_pair(a[i][0],i));
			continue;
		}

		if(itl==s.begin()){
			chk[itl->second][0]=0;
			chk[i][0]=1;
			chk[i][1]=1;
			a[i][1]=itl->first;
			s.insert(make_pair(a[i][0],i));
			continue;
		}


		itl--;

		//cout<<*itl<<" "<<*itu<<endl;

		if(chk[itu->second][0]==1){
			chk[itu->second][0]=0;
			chk[i][0]=1;
			chk[i][1]=1;
			a[i][1]=itu->first;
			s.insert(make_pair(a[i][0],i));
		}else if(chk[itl->second][1]==1){
			chk[itl->second][1]=0;
			chk[i][0]=1;
			chk[i][1]=1;
			a[i][1]=itl->first;
			s.insert(make_pair(a[i][0],i));
		}
	}

	for(i=1;i<n;i++){
		cout<<a[i][1]<<" ";
	}cout<<endl;





	return 0;
}