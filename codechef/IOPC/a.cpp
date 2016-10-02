#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		//cout<<"OK"<<endl; 
		int mat[9][9];

		int i,j,k,l,m;

		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				cin>>mat[i][j];
			}
		}
		

		int chk[10];
		for(i=1;i<=9;i++){
			chk[i]=0;
		}

		int flag=1;

		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(chk[mat[i][j]]==i){
					chk[mat[i][j]]++;
				}else{
					flag=0;
					break;
				}
			}
		}
		
		for(i=1;i<=9;i++){
			chk[i]=0;
		}

		if(flag==1){
			for(j=0;j<9;j++){
				for(i=0;i<9;i++){
					if(chk[mat[i][j]]==j){
						chk[mat[i][j]]++;
					}else{
						flag=0;
						break;
					}
				}
			}	
			if(flag==1){
				
				for(i=1;i<=9;i++){
					chk[i]=0;
				}

				m=0;


				for(i=0;i<9;i=i+3){
					for(j=0;j<9;j=j+3){
						for(k=0;k<3;k++){
							for(l=0;l<3;l++){
								if(chk[mat[i+k][j+l]]==m){
									chk[mat[i+k][j+l]]++;
								}else{
									flag=0;
									break;
								}
							}
							if(flag==0){
								break;
							}
						}
						if(flag==0){
							break;
						}
						m++;
					}
					if(flag==0){
						break;
					}
				}
			}
			
		}

		if(flag==1){
			cout<<"Its A Sudoku"<<endl;
		}else{
			cout<<"Not A Sudoku"<<endl;
		}
		

	}



	return 0;
}