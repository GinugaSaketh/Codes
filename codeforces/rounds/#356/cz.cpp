#include<bits/stdc++.h>

using namespace std;

string s;

vector <int > p;

int a[105];


int main(){

	int i,j;
	for(i=0;i<105;i++)
	{
		a[i]=1;
	}

	for(i=2;i<=100;i++){
		if(a[i]==1){
			p.push_back(i);
			int l=2;
			for(j=l*i;j<=100;j=l*i){
				a[j]=0;
				l++;
			}
		}
	}

	/*for(i=0;i<prime.size();i++){
		cout<<p[i]<<" ";
	}cout<<endl;
	*/
	//cout<<p[14]<<endl;

	int net=0;

	for(i=0;i<15;i++){

		printf("%d\n",p[i]);
		fflush(stdout);

		//scanf("%s",s);
		cin>>s;

		if(s[0]=='y'){
			net++;

			if(p[i]<=7){

				int q=p[i]*p[i];
				printf("%d\n",q);
				fflush(stdout);

				//scanf("%s",s);
				cin>>s;

				if(s[0]=='y'){
					net++;
				}



			}


		}

	}

	if(net<2){
		printf("prime\n");;
		fflush(stdout);
	}else{
		printf("composite\n");
		fflush(stdout);
	}




}