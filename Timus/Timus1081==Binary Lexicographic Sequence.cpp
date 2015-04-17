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


vll fibs;

string f(int p, int k) {
    //printf("p: %d | k: %d | f: %d \n", p, k , fibs[p] );
    if(p==0){
        return k==1 ? "0" : "1";
    }
    if ( k <= fibs[p-1] ) {
        return "0" + f(p-1, k);
    }
    else {
        return "1" + f(p-1, k - fibs[p-1]);
    }
    

}


int main (int argc, char const* argv[]){
    fibs.pb(2);
    fibs.pb(3);
    fr(i,2,50) { fibs.pb( fibs[i-1] + fibs[i-2] ); }
    
    ll N, K;
    scanf("%lld %lld", &N, &K); 
    
    if( fibs[N-1]< K ) {
        printf("-1\n");    
    }
    else  {
    
        string str = f(N-1, K);
        printf("%s\n", str.c_str() );
    } 
    
    return 0;
}




















