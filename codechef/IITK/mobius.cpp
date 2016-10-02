    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int,int> ii;
    typedef pair<ll,ll> pll;
     
    #define TRACE
    #ifdef TRACE
    template<class T, class U>
    ostream& operator<<(ostream& out, const pair<T,U>& a){out<<"["<<a.first<<" "<<a.second<<"]";return out;}
    template<class T>
    ostream& operator<<(ostream& out, const vector<T>& a){out<<"[ ";for(auto &it:a)out<<it<<" ";out<<"]";return out;}
    template<class T>
    ostream& operator<<(ostream& out, const set<T>& a){out<<"[ ";for(auto &it:a)out<<it<<" ";out<<"]";return out;}
    template<class T,class U>
    ostream& operator<<(ostream& out, const map<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
    #define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
    #define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    } 
    #else
    #define pr(...)
    #define pra(a,n)
    #endif
    #define fill(a,x) memset(a,x,sizeof(a)) 
    #define all(x) (x).begin(), (x).end()
    #define sz(a) int((a).size()) 
    #define pb push_back 
    #define F first
    #define S second
    #define FOR(i,a,b) for(int i = a; i<=b; ++i)
    #define NFOR(i,a,b) for(int i = a; i>=b; --i)
    #define NOFLUSH ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
     
    const ll INF = 1e18;
    const int mod = 1e9+7;
    const int N = 1e5+10; 
    const int M = 1e6;
    const double eps = 1e-9;
     
    ll expo(ll a,ll b,ll c = mod){
        if(!b)return 1;
        ll temp = expo(a,b/2,c);
        temp = (temp*temp)%c;
        if(b&1)temp = (temp*a)%c;
        return temp; 
    }
    vector<bool> isprime;
    vector<int> primes;
    void sieve(int n){
      if((int)isprime.size() >= n+1) return;
      isprime.assign(n+1, true);
      isprime[0] = isprime[1] = false;
      int sqrtn = (int)(sqrt(n * 1.) + .5);
      for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
        for(int j = i * i; j <= n; j += i)
          isprime[j] = false;
      }
      primes.clear();
      for(int i = 2; i <= n; i ++) if(isprime[i])
        primes.push_back(i);
    }
     
    vector<int> mobiusMu;
    void calcMobiusMu() {
      int n = (int)isprime.size() - 1;
      mobiusMu.assign(n+1, 1);
      for(int i = 2; i <= n; i ++) if(isprime[i]) {
        if((ll)i * i <= n) {
          for(int j = i * i; j <= n; j += i * i)
            mobiusMu[j] = 0;
        }
        for(int j = i; j <= n; j += i)
          mobiusMu[j] *= -1;
      }
    }
    ll a[N],fr[M+1];
    int main(){
      
      clock_t tm = clock();
      NOFLUSH;
      int __t = 1;
      //cin >> __t;
      FOR(_t,1,__t){
          int n;
          cin >> n;
          fill(fr,0);
          FOR(i,0,n-1){
            cin >> a[i];
            fr[a[i]]++;
          }
          sieve(M);
          calcMobiusMu();
          ll ans = 1LL*n*(n-1)/2;
          FOR(g,1,M){
            ll x = 0;
            for(int j=g;j<=M;j+=g){
              x += fr[j];
            }
            ll y = 1LL*x*(x-1)/2;
            ans -= mobiusMu[g]*y;
          }
          cout << ans << "\n";
      }
      tm = clock()-tm ;
      //cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
      return 0;
    }