#include<iostream>
#include<set>


using namespace std;

int net[5005];
int a[5005];

int main(){
	int n;
	cin>>n;
	int i;
	for(i=0;i<=5005;i++){
		net[i]=0;
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	int j,k;
	set<pair<int ,int > > ::iterator it;
	for(i=1;i<=n;i++){
		set <pair<int,int> > s;
		int f[5005];
		for(k=0;k<5005;k++){
			f[k]=0;
		}
		for(j=i;j<=n;j++){
			f[a[j]]++;
			if(f[a[j]]==1){
				s.insert(make_pair(f[a[j]],-a[j]));
			}else{
				s.erase(make_pair(f[a[j]]-1,-a[j]));
				s.insert(make_pair(f[a[j]],-a[j]));
			}
			it=s.end();
			it--;
			int x=-((*it).second);
			//cout<<i<<" "<<j<<" "<<x<<endl;
			/*if(i==2&&j==4){
				for(it=s.begin();it!=s.end();it++){
					cout<<(it->first)<<" "<<(it->second)<<endl;
				}
			}*/
			net[x]++;
		}
	}
	for(i=1;i<=n;i++){
		cout<<net[i]<<" ";
	}cout<<endl;




	return 0;
}