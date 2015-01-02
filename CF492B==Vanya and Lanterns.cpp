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

bool cmp(double a, double b){
    if(fabs(a-b) <= 1e-9 ) return 0;
    return a>b?1:-1;
}

vi v;
int main (int argc, char const* argv[]) {
    int n, l, k;
    sc2(n,l);
    
    fr(i,0,n){
        sc1(k);
        v.pb(k);
    }
    int d = 0;
    sort(v.begin(), v.end());

    fr(i,0,n-1){
        d = max(d, abs(v[i+1] - v[i])  );
          //  printf("d-> %d\n", d);
    }

    int d1 = v[0];
    int d2 = l - v[v.size()-1];
   // printf("d1 d2 - >%d %d\n", d1, d2);
    
    d1 = max(d1, d2);
    double dif1 = d1+0.0;
    double dif =  d/2.0 ;
    
//    printf("dif1 -> %lf | dif: %lf\n", dif1, dif);
    if( dif1 > dif ) {
        dif = dif1;
    }
    
    
    
    printf("%.10lf\n", dif);     
    
    return 0;
}
