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
#define EPS 1e-9
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
#define LSOne(S) (S & (-S) )
vll t;
void ft_create (int n) {  t.assign(n+5, 0); }   
ll ft_rsq(int b) {
    ll sum = 0; for(; b; b -= LSOne(b) ) sum += t[b];
    return sum;
}
int ft_rsq(int a, int b) { return ft_rsq(b) - (a==1 ? 0 : ft_rsq(a-1)); }
void ft_adjust(int k, ll v) {
    for(; k<= (int)t.size(); k+= LSOne(k)  ) t[k]+=v;
}
int main(int argc, char const *argv[]) {
    vi v1, v2;
    int n, k;
    while( sc1(n) ==1 ) {
        v1.clear();
        v2.clear();
        ft_create(n);
        fr(i,0,n){
            sc1(k); 
            v1.pb(k);
            v2.pb(k);
        }
        sort(v2.begin(), v2.end());
        fr(i,0,n){
            k = v1[i];
            v1[i] = int( lower_bound(v2.begin(), v2.end(), k) - v2.begin() ) + 1;  
        }
        ll sum =  0;
        for(int i = n-1; i >= 0 ; i--) {
            sum += ft_rsq( v1[i] );
            ft_adjust( v1[i], 1 );
        }
        printf("%lld\n", sum);
    }
    return 0;
}
