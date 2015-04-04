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
 
 
int p,q,r,s,t,u;
 
/*
       p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
        where 0 <= x <= 1.
*/
double f(double x){
        return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
 
int cmp(double a, double b=0){
        if( fabs(a-b) <= EPS )  return 0;
        return (a>b)?1:-1;
}
 
bool ok;
 
double bs(double hi, double lo){
        if( cmp(lo, hi) == 1  ) return 0;
        double mid = (hi+lo)/2;
        double y = f(mid);
        if(cmp(y)==0) { ok =1; return mid; }
        if(cmp(y) == 1) lo = mid;
        else hi = mid;
 
 
        return bs(hi,lo);
}      
 
 
 
int main(int argc, char const *argv[]) {
        double res;
        int r1, r2;
        while( scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6 ){
                ok = 0;
                r1 = cmp( f(0) );
                r2 = cmp( f(1) );
                if ((r1==1 && r2 == 1) || (r1==-1 && r2 == -1)  ){
                        printf("No solution\n");
                }
                else{
                        res = bs(1,0);
                        if(ok) printf("%.4lf\n", res);
                        else printf("No solution\n");
                }
        }
        return 0;
}
