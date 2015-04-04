#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int total;
int s1, s2;
int const MOD =  1000000007;

ll mem_free[4005][4005];
ll bt_free(int p, int x){
    if( (p-1-x) >= x ) return 0;
    if(p > total ) {
        return ( (x == s1) && ((p-1-x) == s2 )  );
    }
    if(mem_free[p][x]!=-1) return mem_free[p][x];
    ll r1 = ( bt_free(p+1, x) ) % MOD ;
    ll r2 = (bt_free(p+1, x+1) ) % MOD;
    return  mem_free[p][x] = (r1+r2)%MOD;
}

ll mem_full[4005][4005][3];
ll bt_full(int p, int x){
    int ele = p-1-x;
    if(ele != s2 && ( x > ele ) ) return 0;
    if( p > total ){
        if( (x == s1) && (ele == s2 )  ){
            return 1;
        }
        return 0;
    }   
    if(mem_full[p][x][ ele == s2 ] != -1) return mem_full[p][x][ ele == s2 ];
    ll r1 = bt_full(p+1, x+1) % MOD; 
    ll r2 = bt_full(p+1,  x) % MOD ;
    return  mem_full[p][x][ ele == s2 ] = (r1+r2)%MOD;
}   


int main(int argc, char const *argv[]) {
    int caso; ll r1, r2;
    sc1(caso);
    fe(t,1,caso){
        scanf("%d-%d", &s1, &s2);
        mst(mem_free,-1);
        mst(mem_full, -1);
        total = s1+s2;
        r1 = bt_free(2, 1);
        r2 = bt_full(1, 0);
        printf("Case #%d: %I64d %I64d\n", t, r1, r2 );
    }


    return 0;
}