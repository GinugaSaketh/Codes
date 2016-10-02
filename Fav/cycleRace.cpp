   // Comvex Hull Trick
   // https://www.codechef.com/JAN16/problems/CYCLRACE/


    #include<iostream>
    #include<vector>
    #include<set>
    #include<string>
    #include<map>
    #include<algorithm>
     
    double inf=1000000005;
     
     
     
    using namespace std;
     
    int main(){
    	long long n,q,i;
    	cin>>n>>q;
    	int type;
    	long long cyc,newspeed;
    	double time;
    	vector < pair<long long ,long long > > cyclist(50005);
    	
    	//handle n==1;
    	
    	//increasing slope............
    	
    	
    	
    	double start_time[50005];
    	set < pair<double,long long > > time_set;
    	
    	
    	
    	set <pair<pair<pair<long long,long long >,long long>,double > > dyset;
    	//                          m,c           index      start_time
    	 
    	for(i=1;i<=n;i++){
    		(cyclist[i]).first=0;
    		(cyclist[i]).second=0;
    		pair<pair<pair<long long ,long long >,long long>,double > tmp;
    		
    		tmp.second=0;
    		(tmp.first).second=i;
    		(tmp.first).first=cyclist[i];
    		
    		
    		pair <double,long long > tp;		
    		
    		
    		
    		start_time[i]=0;
    		tp.second=i;
    		tp.first=0;
    		time_set.insert(tp);
    		
    		
    		
     
    		
    		dyset.insert(tmp);
    		
    	}
    	
    	while(q--){
    		cin>>type;
    		if(type==1){
    			
    			cin>>time>>cyc>>newspeed;
    			
    			pair<pair<pair<long long ,long long >,long long >,double > temp;
    			temp.second=start_time[cyc];
    			(temp.first).second=cyc;
    		    (temp.first).first=cyclist[cyc];
    			//int chk=0;
    			
    			pair<double,long long > tpp;
    			tpp.first=start_time[cyc];
    			tpp.second=cyc;
    			time_set.erase(tpp);
    			
    			
    			dyset.erase(temp);
    			
    			(cyclist[cyc]).second+=((cyclist[cyc]).first-newspeed)*time;
    			(cyclist[cyc]).first=newspeed;
    			
    			temp.second=0;
    			(temp.first).second=cyc;
    		    (temp.first).first=cyclist[cyc];
    			
    			start_time[(temp.first).second]=0;
    			
    			tpp.first=0;
    			time_set.insert(tpp);
    			
    			dyset.insert(temp);
    			
    			set <pair<pair<pair<long long ,long long  >,long long >,double > > ::iterator itup;
    			itup=dyset.upper_bound(temp);
    			
    			set <pair<pair<pair<long long ,long long  >,long long >,double > > ::iterator itlow;
    			itlow=dyset.lower_bound(temp);
    			
    			
    			int check_inset=1;
    			
    			
    			//check if in set, else erase;
    			//itup same slope -> not a valid candidate;
    			//observe algo change in block 3
    			
    			if(itup!=dyset.end()){
    				if((((itup->first).first).first)==((temp.first).first).first){
    					check_inset=0;
    					pair<double,long long > tpm;
    					tpm.second=(temp.first).second;
    					tpm.first=start_time[(temp.first).second];
    					time_set.erase(tpm);
    					
    					
    					
    					start_time[(temp.first).second]=inf;
    					tpm.first=inf;
    					time_set.insert(tpm);
    					
    					dyset.erase(temp);
    					
    				}
    			}
    			
    			
    			
    			
    			
    			if(itlow!=dyset.begin()&&check_inset==1){
    				itlow--;
    				if((((itlow->first).first).first)!=((temp.first).first).first&&itup!=dyset.end()){
    					double time_piv,time_comp; 
    					
    					time_piv=((((itlow->first).first).second-((itup->first).first).second)*1.0)/((((itup->first).first).first)-(((itlow->first).first).first));
    					
    					time_comp=((((itup->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itup->first).first).first));
    						
    					if(time_comp>time_piv){
    						check_inset=1;
    					}else{
    						check_inset=0;
    						pair<double,long long > t;
    						t.first=start_time[(temp.first).second];
    						t.second=(temp.first).second;
    						time_set.erase(t);
    						
    						start_time[(temp.first).second]=inf;
    						t.first=inf;
    						time_set.insert(t);
    						
    						
    						dyset.erase(temp);
    					
    					}
    				
    				}/*else{
    						
    						start_time[(itlow->first).second]=inf;
    						dyset.erase(*itlow);
    						
    				}*/
    				
    				
    			}else if(check_inset=1){
    				itup=dyset.upper_bound(temp);
    				
    				if(itup!=dyset.end()){
    					double time_of_inter;
    					time_of_inter=((((itlow->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itlow->first).first).first));
    					
    					if(time_of_inter>0){
    						check_inset=1;
    					}else{
    						check_inset=0;
    						
    						pair<pair<pair<long long ,long long >,long long >,double > line=*itup;
    						
    						line.second=0;
    						
    						pair<double,long long > y;
    						pair<double,long long > y1;
    						y1.second=(itup->first).second;
    						y1.first=start_time[(itup->first).second];
    						
    						y.first=start_time[(temp.first).second];
    						y.second=(temp.first).second;
    						time_set.erase(y);
    						time_set.erase(y1);
    												
    						start_time[(temp.first).second]=inf;
    						y.first=inf;
    						
    					    time_set.insert(y);
    						y1.first=0;
    						time_set.insert(y1);
    						
    						dyset.erase(temp);
    						dyset.erase(*itup);
    						dyset.insert(line);
    						
    						
    						
    					}
    					
    					
    					
    				}
    				
    				
    				
    			}
    			
    			
    			
    			
    			
    			
    			
    			//if(*itlow==temp)itlow--;
    			
    			//itlow--;
    			
    			
    			//cout<<(((itlow->first).first).first)<<"   "<<(((itlow->first).first).second)<<"   "<<(((itlow->first).second))<<"   "<<(((itlow->second)))<<endl;
    			
    			
    			
    		    //set <pair<pair<pair<long long ,long long >,long long >,double > > ::iterator it;
    			
         		
    			
    			itup=dyset.upper_bound(temp);
    			itlow=dyset.lower_bound(temp);
    			
    			
    			if(check_inset==1){
    				
    				if(temp==*itlow)itlow--;
    				
    			    while(itlow!=dyset.begin()&&temp!=*dyset.begin()){
    			    	
    			    	
    			    	
    			    	if(temp==*itlow){
    			    		itlow--;continue;
    					}
    					double check_time=(itlow->second);
    					double cal_time=0;
    					
    					pair< double,long long > r;
    					r.second=(temp.first).second;
    					r.first=start_time[(temp.first).second];
    					time_set.erase(r);
    					
    					start_time[(temp.first).second]=0;
    					r.first=0;
    					time_set.insert(r);
    					
    					//cout<<"fszgdz "<<(((itlow->first).second))<<endl; 
    					
    					if(((((temp.first).first).first)-(((itlow->first).first).first)))
    				    {
    						cal_time=((((itlow->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itlow->first).first).first));
    					}else{
    						
    						pair <double,long long > lk;
    						lk.first=start_time[(((itlow->first).second))];	
    						lk.second=(((itlow->first).second));
    						time_set.erase(lk);
    						start_time[(((itlow->first).second))]=inf;/////////
    						lk.first=inf;
    						time_set.insert(lk);
    						
    						dyset.erase(*itlow);
    						itlow=dyset.lower_bound(temp);
    						if(temp==*itlow)itlow--;
    						continue;
    					}
    					if(cal_time>check_time){
    						dyset.erase(temp);
    						
    						//cout<<cal_time<<endl;
    						pair<double,long long> qa;
    						qa.first=start_time[(temp.first).second];
    						qa.second=(temp.first).second;
    						time_set.erase(qa);
    						
    						temp.second=cal_time;
    						dyset.insert(temp);
    						start_time[(temp.first).second]=cal_time;
    						qa.first=temp.second;
    						time_set.insert(qa);
    						
    						break;
    					}else{
    						pair<double,long long > kj;
    						kj.first=start_time[(((itlow->first).second))];
    						kj.second=(((itlow->first).second));
    						time_set.erase(kj);
    						start_time[(((itlow->first).second))]=inf;
    						kj.first=inf;
    						time_set.insert(kj);
    						
    						dyset.erase(*itlow);
    						itlow=dyset.lower_bound(temp);
    						if(temp==*itlow)itlow--;
    						
    					}
    				}
    				if(temp!=*dyset.begin()&&itlow==dyset.begin()){
    					
    					double check_time=(itlow->second);
    					double cal_time=0;
    					start_time[(temp.first).second]=0;
    					if(((((temp.first).first).first)-(((itlow->first).first).first)))
    				    {
    						cal_time=((((itlow->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itlow->first).first).first));
    					}else{
    						
    						pair<double,long long > jh;
    						jh.first=start_time[(((itlow->first).second))];
    						jh.second=(((itlow->first).second));
    						time_set.erase(jh);
    						start_time[(((itlow->first).second))]=inf;
    						jh.first=inf;
    						time_set.insert(jh);
    						
    						dyset.erase(*itlow);
    						itlow=dyset.lower_bound(temp);
    						if(temp==*itlow)itlow--;
    						//continue;
    					}
    					if(cal_time>check_time){
    						pair<double,long long > hg;
    						hg.first=start_time[(temp.first).second];
    						hg.second=(temp.first).second;
    						time_set.erase(hg);
    						
    						dyset.erase(temp);
    						temp.second=cal_time;
    						hg.first=temp.second;
    						time_set.insert(hg);
    						
    						dyset.insert(temp);
    						
    						start_time[(temp.first).second]=cal_time;
    						
    						//break;
    					}else{
    						pair<double,long long > gf;
    						gf.first=start_time[(((itlow->first).second))];
    						gf.second=(((itlow->first).second));
    						time_set.erase(gf);
    						
    						start_time[(((itlow->first).second))]=inf;
    						gf.first=inf;
    						time_set.insert(gf);
    						
    						dyset.erase(*itlow);
    						//itlow=dyset.lower_bound(temp);
    						//if(temp==*itlow)itlow--;
    						
    					}
    					
    					
    				}
    				//////////////////////////////////////// inside loop check_inset=1;
    				
    				if(itup!=dyset.end()){
    					
    					//here itup is next line
    					
    					itup++;
    					
    					//here itup is next ka next line
    					
    					// contiguous removing loop
    					while(itup!=dyset.end()){      //itup is next ka next
    						
    						
    						
    						
    						
    						pair<pair<pair<long long ,long long >,long long >,double > line_nn=*itup;
    						
    						itup--;
    						
    						//itup is next
    						
    						
    						double inter_time;
    						
    						inter_time=((((itup->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itup->first).first).first));
    						
    						if(inter_time>(line_nn.second)){
    							pair <double,long long > fd;
    							fd.first=start_time[((itup->first).second)];
    							fd.second=((itup->first).second);
    							time_set.erase(fd);
    							
    							start_time[((itup->first).second)]=inf;
    							fd.second=inf;
    							time_set.insert(fd);
    							
    							dyset.erase(*itup);
    							itup=dyset.upper_bound(temp);//itup is next line ,here we know that itup!=dyset.end()
    							itup++;//itup is next ka next.
    							
    							
    							continue;
    							
    						}else{
    							line_nn=*itup;//her dont line_nn is next ,but not next ka next
    							pair<double,long long > ds;
    							ds.first=start_time[(line_nn.first).second];
    							ds.second=(line_nn.first).second;
    							time_set.erase(ds);
    							line_nn.second=inter_time;
    							start_time[(line_nn.first).second]=inter_time;
    							ds.first=line_nn.second;
    							time_set.insert(ds);
    							
    							dyset.erase(*itup);
    							dyset.insert(line_nn);
    							itup=dyset.upper_bound(temp);//itup is next line
    							itup++;//itup is next ka next line.
    							
    							break;
    							
    							
    						}
    						
    						
    						
    						
    						
    						
    						
    						
    						
    						
    						 
    						
    					}
    					
    					//if next ka next nahi hai update start time of next
    					
    					if(itup==dyset.end()){     //itup is next ka next line
    						
    						itup--;
    						
    						//itup is next line
    						
    						pair<pair<pair<long long ,long long >,long long >,double > line_n=*itup;
    						
    						double time_inter;
    						
    						time_inter=((((itup->first).first).second-((temp.first).first).second)*1.0)/((((temp.first).first).first)-(((itup->first).first).first));
    						
    						line_n.second=time_inter;
    						
    						pair<double,long long > sa;
    						sa.first=start_time[(line_n.first).second];
    						sa.second=(line_n.first).second;
    						time_set.erase(sa);
    						
    						dyset.erase(*itup);
    						sa.first=line_n.second;
    						time_set.insert(sa);
    						
    						start_time[(line_n.first).second]=((line_n.second));
    						dyset.insert(line_n);
    						
    						
    						
    					}
    					
    					
    					
    					
    					
    					
    					
    				}
    								
    				
    				
    				
    				
    				
    				
    			}
    			
    			
    			
    		
    			/*cout<<"////////////////////////"<<endl;
    			for(it=dyset.begin();it!=dyset.end();it++){
    				cout<<(((it->first).first).first)<<"   "<<(((it->first).first).second)<<"   "<<(((it->first).second))<<"   "<<(((it->second)))<<endl;
    				//         slope                                    y -intercept                      index                     time
    			}*/
    			
    			
    			
    			
    			
    		}else {
    			cin>>time;
    			pair <double,long long> a;
    			a.first=time;
    			a.second=inf;
    			time_set.insert(a);
    			//cout<<"//////////////////////////////////"<<endl;
    			
    			//set < pair<double,long long > > ::iterator ity;
    			set < pair<double,long long > > ::iterator itl;
    			itl=time_set.lower_bound(a);
    			if(itl!=time_set.begin()&&*itl==a)itl--;
    			
    			/*for(ity=time_set.begin();ity!=time_set.end();ity++){
    				cout<<ity->first<<"   ";
    			}
    			cout<<endl;
    			*/
    			long long index=(itl->second);
    			
    			long long ans;
    			ans=((cyclist[index]).first)*time+(cyclist[index]).second;
    			
    			//cout<<"ans is::::::::::::::"<<ans<<endl;
    			cout<<ans<<endl;
    			time_set.erase(a);
    		}
        }
    	
    	return 0;
    }
     