#include<bits/stdc++.h>

using namespace std;

//vector< pair<<int,int>,int>> a;

map<pair<long long ,long long> ,long long > mp;



int main(){

	int q_;

	cin>>q_;

	int i;

	long long c,v,u,w;
	long long  k;

	long long p,q,r;

	for(i=0;i<q_;i++){
		cin>>c;

		if(c==1){
			cin>>v>>u>>w;
			//a.push_back(make_pair(make_pair(u,v),w));

			int h1,h2;
			if(u>v){
				k=u;
				u=v;
				v=k;
			}


			h1=(int)log2(u);
			h2=(int)log2(v);

			
			while(h2!=h1){

				mp[make_pair(v,v/2LL)]+=w;
				h2--;
				v/=2LL;
			}


			while(u!=v){
				mp[make_pair(v,v/2LL)]+=w;
				mp[make_pair(u,u/2LL)]+=w;
				u/=2LL;
				v/=2LL;
			}


		}else{
			cin>>u>>v;
			long long net=0;


			int j;


			int h1,h2;
			if(u>v){
				k=u;
				u=v;
				v=k;
			}


			h1=(int)log2(u);
			h2=(int)log2(v);

			
			while(h2!=h1){
				net+=mp[make_pair(v,v/2LL)];
				h2--;
				v/=2;
			}


			while(u!=v){
				net+=mp[make_pair(v,v/2LL)];
				net+=mp[make_pair(u,u/2LL)];
				u/=2LL;
				v/=2LL;
			}

			cout<<net<<endl;
			
		}

	}






	return 0;
}

