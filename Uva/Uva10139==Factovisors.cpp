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
 
vll sieve;
bool mark[100005];
void goSieve(){
        mark[0]=mark[1] = 1;
        fr(i,0,100004){
                if(mark[i]) continue;
                sieve.pb(ll(i));
                for(ll j=ll(i)*i; j < 100004 && j > 0 ; j+=i){ mark[j]=1;}
        }
}
 
 
ll n, k;
vector< pair<ll, ll> >  factors;
void go(){
        ll aux = k;
        factors.clear();
        int id = 0, pf = sieve[0];
        while( k != 1 && ll(pf)*pf <=  ll(k) ){
                ll cnt = 0;
                while( k%pf ==0 ) { cnt++; k/=pf; }
                if(cnt) factors.pb(mp(pf, cnt));
                id++; pf = sieve[id];
        }
        if(k!=1) factors.pb(mp(k,1));
        k = aux;
}
 
ll get(ll w){
        ll sum = 0;
        ll d = w;
        while( d <= n){
                sum += n/d;
                d*=w;
        }
        return sum;
}
 
 
int main(int argc, char const *argv[]) {
        goSieve();
        ll pf; ll cnt, r;
        bool ok;
        while(scanf("%lld %lld", &n, &k)==2){
                if(!k) {
                        printf("%lld does not divide %lld!\n", k, n);
                }
                else {
                        go();
                        ok = 1;
                        fr(i,0,factors.size()){
                                pf = factors[i].st, cnt = factors[i].nd;
                                //printf("pf: %lld | cnt: %lld\n", pf, cnt);
                                r = get(pf);
                                if( r < cnt) { ok =0; break;}
                        }
                        if(ok) printf("%lld divides %lld!\n",k , n);
                        else printf("%lld does not divide %lld!\n", k, n);
                }
        }
 
 
        return 0;
}
