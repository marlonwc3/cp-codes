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
 
bool mark[10005];
vi sieve;
void goSieve(){
        mark[0]=mark[1] = 1;
        fr(i,0,10004){
                if(mark[i]) continue;
                sieve.pb(i);
                for(ll j = ll(i)*i ; j > 0 && j < 10004; j+=i ){ mark[j] = 1;}
        }
}
 
vii factors1, factors2;
void getFactors(int n, bool a){
        if(a) factors1.clear();
        else factors2.clear();
        int id =0, pf = sieve[0], cnt;
        while( n != 1 && ll(pf)*pf <= n )        {
                cnt = 0;
                while( n % pf == 0 ) { n/=pf; cnt++;  }
                if(cnt) {
                        if(a) factors1.pb(mp(pf, cnt));
                        else factors2.pb(mp(pf, cnt));
                }
                id++; pf = sieve[id];
        }
        if(n!=1) {
                if(a) factors1.pb(mp(n, 1));
                else factors2.pb(mp(n, 1));
        }
}
 
int fexp(int a, int b){
        if( b<=1) return (!b) ? 1: a;
        int r = fexp(a, b/2); r*=r;
        if(b%2 == 1) r*=a;
        return r;
}
 
int main(int argc, char const *argv[]) {
        goSieve();
        int t, a, b,  c;
        int id1 = 0, id2 = 0, k1, p1, k2, p2;
        sc1(t);
        while(t--){
                sc2(a,c);
                if( c%a != 0){
                        printf("NO SOLUTION\n");
                }
                else{
                        getFactors(a,1);
                        getFactors(c,0);
                        id1=id2=0;
                        b = 1;
                        while( id1 < factors1.size() && id2 < factors2.size() ){
                                k1 = factors1[id1].st, p1 = factors1[id1].nd;
                                k2 = factors2[id2].st, p2 = factors2[id2].nd;
                                if( k1 != k2){
                                        b *= fexp(k2, p2); id2++;
                                }
                                else {
                                        if(p1 != p2)  b *= fexp(k2, p2);
                                        id2++; id1++;
                                }
                        }
                        while( id2 < factors2.size() ){
                                k2 = factors2[id2].st, p2 = factors2[id2].nd;
                                b*= fexp(k2, p2); id2++;
                        }
                        printf("%d\n", b);
                }
        }
 
 
        return 0;
}
