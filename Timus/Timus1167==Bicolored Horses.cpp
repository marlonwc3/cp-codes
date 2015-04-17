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

#define MAX_N 505
int N, K;
int arr[MAX_N];

ll pd[MAX_N][MAX_N];
int PASSO, pd_ok[MAX_N][MAX_N];

ll go(int k, int p){
    if(k >= K ){
        if( p != N ) return inf;
        return 0;
    }
    if( p >= N ) return inf;
    if(pd_ok[k][p] == PASSO ) return pd[k][p];
    ll r = inf;
    ll c1 = 0, c2 = 0;
    fr(i,p,N){
        c1 += arr[i]==0;
        c2 += arr[i]==1;
        r = min(r, go(k+1, i+1) + c1*c2);
    }
    pd_ok[k][p] = PASSO;
    pd[k][p] = r;
    return r;
}



int main (int argc, char const* argv[]){
    int a;
    PASSO = 0;
    ll r;
    while( sc2(N,K) ==2 ){
        PASSO++;
        fr(i,0,N){
            scanf("%1d", &a);
            arr[i] = a;
        }
        r = go(0, 0);
        printf("%lld\n", r);
    }
    
    
    return 0;
}



























