#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;


int main (int argc, char const* argv[]) {
    int t, k, n; 
    vi v1, v2;
    sc1(t);
    while(t--){
        v1.clear(), v2.clear();
        sc1(n);
        fr(i,0,n){
            sc1(k); v1.pb(k);
        }
        fr(i,0,n){
            sc1(k); v2.pb(k);
        }       
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        ll a,b,sum = 0;
        fr(i,0,n){
        
            a = v1[i], b = v2[i];
            sum += a*b;
        }
        
        printf("%lld\n", sum);
        
    }
    
    
    
    return 0;
}
