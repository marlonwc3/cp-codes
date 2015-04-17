#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;

ll D;
ll a1;
bool f(ll n ){
   ll k = (( a1 + (a1 + n-1 )  )*n) /2;
   if ( k < D ) return 0;
   return 1;
}

ll bs(ll lo, ll hi){
   // printf("lo: %lld | hi: %lld\n", lo, hi);
    if ( lo +1 >= hi ) return inf;
    ll mid = (lo+hi)/2;
   // printf("mid: %lld | f(mid): %d\n", mid, f(mid));
    if(f(mid)) return min(mid, bs(lo,mid));
    return bs(mid, hi);
}


ll fexp(ll a,ll b){
    if(!b) return 1;
    if(b==1) return a;
    ll r = fexp(a, b/2);
    r*=r;
    if(b%2 == 1 ) r*=a;
    return r;
}

int main (int argc, char const* argv[]){
    while( scanf("%lld %lld", &a1, &D)== 2 ){
    
        
        ll r;
      //  r = f(3);
     //   printf("r: %lld\n", r);
       // break;
        ll limit = fexp(10, 8);
        r = bs(0, limit );
        ll x = a1 + r-1;
        printf("%lld\n", x);
    //    printf("r: %lld\n", r);
        
        
    }
    
    
    
    
    
    
    
    return 0;
}












