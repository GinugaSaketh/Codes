// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
 
// M is number of applicants and N is number of jobs
#define M 6
#define N 1000
 
vector <vector <int> > bpGraph;

vector <vector <int> > w;


vector <int > p;

int v[1001];
int a[1005];


// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm( int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v= 0; v < bpGraph[u].size(); v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (!seen[v])
        {
            seen[v] = true; // Mark v as visited
 
            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] 
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < bpGraph.size(); u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
 
// Driver program to test above functions
int main()
{
    int i,j;

    for(i=0;i<=1000;i++){
        v[i]=1;
    }    

    for(i=2;i<=1000;i++){
        if(v[i]==1){
            p.push_back(i);

            for(j=2;i*j<=1000;j++){
                v[i*j]=0;
            }
        }
    }
    int k=0;
    v[0]=v[1]=-1;
    for(i=2;i<=1000;i++){
        if(v[i]==0){
            v[i]=-1;
        }else{
            v[i]=k;
            k++;
        }
    }

    w.resize(1005);

    for(i=1;i<=1000;i++){
        for(j=0;j<p.size();j++){
            if(i%j==0){
                w[i].push_back(j);
            }
        }
    }

    //bpGraph 0 == p 0
    bpGraph.resize(p.size());

    int t,l,n;

    cin>>t;

    for(l=0;l<t;l++){

        cin>>n;
        
        for(i=0;i<p.size();i++){
            bpGraph[i].resize(0);
        }

        int one=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1){
                one++;
                continue;
            }
            for(j=0;j<w[a[i]].size();j++){
                bpGraph[w[a[i]][j]].push_back(a[i]);
            }

        }


        int ans=maxBPM()+one;

        cout<<ans<<endl;

    }

    return 0;
}