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
 
bool mark[1084];
vi sieve;
void goSieve(){
        mark[0]=mark[1]=1;
        fr(i,0,1083){
                if(mark[i]) continue;
                sieve.pb(i);
                for(ll j = ll(i)*i; j > 0 && j < 1083; j+=i ) mark[j]=1;
        }
}
 
vii factors;
void getFactors(int n){
        factors.clear();
        int id = 0 , pf = sieve[0], cnt;
        while( n != 1 && ll(pf)*pf <= n  ){
                cnt = 0;
                while( n%pf == 0 ){ cnt++; n/=pf; }
                if(cnt) factors.pb(mp(pf, cnt));
                id++; pf = sieve[id];
        }
        if(n!=1) { factors.pb(mp(n,1)) ; }
}
 
int get(int n, int p){
        int k = p, sum = 0;
        while( k<=n){
                sum += n/k;
                k*=p;
        }
        return sum;
}
 
int main(int argc, char const *argv[]) {
        goSieve();
        int n,b ,p , cnt, r, ra, rb;
        while(sc2(n,b)==2) {
                getFactors(b);
                ra = inf;
                fr(i,0,factors.size() ){
                        p = factors[i].st, cnt = factors[i].nd;
                        r = get(n,p);
                        if( r < cnt) { ra =0 ; break; }
                        ra = min(ra, r/cnt);
                }
                double s = 1;
                fe(i, 1, n){
                        s += log10(i)/log10(b);
                }
                rb  = s;
                printf("%d %d\n", ra, rb);
 
        }
        return 0;
}
