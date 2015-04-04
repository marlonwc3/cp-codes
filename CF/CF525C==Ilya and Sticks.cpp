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
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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



int cnt[1000005];
vi v, pares;

ll go(){
    ll r = 0;
    int i = pares.size() -1 , j = pares.size() - 2; 
    int k1, k2, q;
    while ( i >= 0 ) {
        while( i >= 0 && cnt[pares[i]] <= 1 ) i--;
        j = i-1;
        while( j >= 0 && cnt[pares[j]] <= 1 ) j--;
      //  printf("i: %d | j: %d\n", i, j);
        if( i < 0 ) break;
        if(cnt[pares[i]] >= 4 ) {
            k1 = cnt[pares[i]];
            q = k1/4;
            r += ll(q)*ll(pares[i])*ll(pares[i]);
            cnt[pares[i]] -= q*4;
        }
        else { 
            if ( j < 0 ) break;
            k1 = cnt[pares[i]]; k2 = cnt[pares[j]];
            q = min(k1/2, k2/2);
            r += ll(q)*ll(pares[i])*ll(pares[j]);
            cnt[pares[i]] -= q*2;
            cnt[pares[j]] -= q*2;
        }
    }
    return r;

}


int main (int argc, char const* argv[]) {
    int n,k ;
    sc1(n);
    fr(i,0,n){
        sc1(k); cnt[k]++;
        if(cnt[k] == 1 ) v.pb(k);
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i>=0; i--){
        if(cnt[v[i]]%2 == 1 && v[i-1] +1 == v[i] ) {
            cnt[v[i]]--;
            cnt[v[i-1]]++;
        }
    }
    
    
    fr(i,0,v.size()){
        if(cnt[v[i]] >= 2 ) {
            pares.pb(v[i]);
        }
    }
  //  pv(pares,x);
    ll r = 0;
    r += go();

    printf("%I64d\n", r);
   
    
    
    return 0;
}

