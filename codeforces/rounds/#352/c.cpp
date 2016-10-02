#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;

#define ll long long
#define x first
#define y second
#define lf long double


pair<lf,lf> a,b,t;

vector <pair<lf,lf> > pts;

//vector <lf> dt;
vector <lf > da;
vector <lf> db;



int main(){
	cin>>a.x>>a.y>>b.x>>b.y>>t.x>>t.y;

	int n;
	cin>>n;

	int i;
	int q,w;
	for(i=0;i<n;i++){
		scanf("%d %d",&q,&w);
		lf e=(lf)q;
		lf r=(lf)w;
		pts.push_back(make_pair(e,r));
	}
	lf net=0;

	for(i=0;i<n;i++){
		lf d=sqrt((pts[i].x-t.x)*(pts[i].x-t.x)+(pts[i].y-t.y)*(pts[i].y-t.y));
		net+=2.0*d;

		lf d1=sqrt((pts[i].x-a.x)*(pts[i].x-a.x)+(pts[i].y-a.y)*(pts[i].y-a.y));
		d1-=d;
		da.push_back(d1);
		lf d2=sqrt((pts[i].x-b.x)*(pts[i].x-b.x)+(pts[i].y-b.y)*(pts[i].y-b.y));
		d2-=d;
		db.push_back(d2);
	}

	int ma1=0,mb1=0;

	for(i=1;i<n;i++){
		if(da[i]<da[ma1]){
			ma1=i;
		}
		if(db[i]<db[mb1]){
			mb1=i;
		}
	   //]cout<<da[i]<<" "<<db[i]<<endl;

	}
	//cout<<net<<" "<<ma1<<" "<<mb1<<endl;
	if(ma1!=mb1){
		if(da[ma1]<0&&db[mb1]<0){
			net+=da[ma1]+db[mb1];

		}else{
			lf o=min(da[ma1],db[mb1]);
			net+=o;
		}

		cout<<setprecision(25)<<net<<endl;

	}else{
		if(n==1){
			lf o=min(da[ma1],db[mb1]);
			net+=o;
			cout<<setprecision(25)<<net<<endl;
		}else{
			int ma2,mb2;
			ma2=mb2=(ma1+1)%2;
			for(i=0;i<n;i++){
				if(i==ma1)continue;

				if(da[i]<da[ma2]){
					ma2=i;
				}
				if(db[i]<db[mb2]){
					mb2=i;
				}
			}
			//cout<<ma2<<" "<<mb2<<endl;
			
			
			if(min(da[ma2],db[mb2])>=0){
				net+=min(da[ma1],db[mb1]);
			}else{
				lf o=min(da[ma1],db[mb1]);
				o=min(o,da[ma1]+db[mb2]);
				o=min(o,db[mb1]+da[ma2]);
				net+=o;


			}


			cout<<setprecision(25)<<net<<endl;


		}



	}




	return 0;
}