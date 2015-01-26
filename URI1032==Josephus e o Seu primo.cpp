#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
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

 
bool mark[100005];
vi sieve;
void goSieve(){
    mark[0]=mark[1] = 1;
    fr(i,0,100004){
        if(mark[i]) continue;
        sieve.pb(i);
        for(ll j = ll(i)*i ; j > 0 && j < 100004; j+=i ){ mark[j] = 1;}
    }
}

int main(int argc, char const *argv[]) {
    goSieve();
    vi v;
    int n, k, id,  p;
    while(1){
        sc1(n); iz(n);
        v.clear();
        fe(i,1,n) v.pb(i);
        id = 0;
        p  = (sieve[id] - 1)%v.size();
        if(v.size()  > 1 ){ 
            do{
                v.erase( v.begin()+p );
                id++;
                p = (p - 1 + sieve[id]) % v.size();
            } while( v.size() > 1  );
        }
        p = v[0];
        printf("%d\n", p);
    }
    return 0;
}