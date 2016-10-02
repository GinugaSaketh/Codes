#include<bits/stdc++.h>

using namespace std;

string s;

vector <pair <int ,int> > v;

vector <pair<int,int> > k;

int main(){
	int n;
	cin>>n;
	cin>>s;
	int i,j;
	k.push_back(make_pair(4,2));
	k.push_back(make_pair(1,1));
	k.push_back(make_pair(1,2));
	k.push_back(make_pair(1,3));	
	k.push_back(make_pair(2,1));
	k.push_back(make_pair(2,2));
	k.push_back(make_pair(2,3));
	k.push_back(make_pair(3,1));
	k.push_back(make_pair(3,2));
	k.push_back(make_pair(3,3));

	int x,y;

	for(i=1;i<n;i++){
		x=s[i]-'0';
		y=s[i-1]-'0';

		v.push_back(make_pair(k[x].first-k[y].first,k[x].second-k[y].second));
	}
	int net=0;


/*	for(i=0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
*/
	//cout<<endl;
	for(i=0;i<=9;i++){
		//cout<<i<<endl;
		int flag=1;
		x=k[i].first;
		y=k[i].second;

		for(j=0;j<v.size();j++){
			//cout<<x<<" "<<y<<endl;
			x+=v[j].first;
			y+=v[j].second;

			if(x==4&&y==2){
				continue;
			}

			if(x>=4||x<=0||y>=4||y<=0){
				flag=0;
				break;
			}


		}
		if(flag==1){
			
			net++;
		}
		
	}

	if(net>=2){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}


	//cout<<net<<endl;


	return 0;
}