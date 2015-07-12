#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <string>
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
#define EPS 1e-8
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;

#define addEdge(a,b) to[z] = b; ant[z] = adj[a]; adj[a] = z++
#define addEdgeC(a,b,c) from[z] = a; to[z] = b; ant[z] = adj[a]; adj[a] = z; cost[z] = c; z++
#define rp(a,b) fr(a,0,b)
#define MP make_pair
#define F first
#define S second
const int infinity = 0x3f3f3f3f;
const long long longInfinity = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<int,int> pii;
typedef pair<pii,int> trii;
typedef long long ll;
typedef priority_queue<pii, vector<pii>, greater<pii> > HeapPii;

typedef long long ll;
typedef pair<int, int> ii;



vector<double> v;

int cmp(double a, double b = 0.0) {
    if(fabs(a-b) <= EPS) return 0;
       return (a>b) ? 1 : -1;
}

bool ok(double a ,double b, double c){
    if( cmp(b+c, a) ==1 ) return 1;
    return 0;
}

double area(double a,double b,double c){
    double s = (a+b+c)/2;
    
    return sqrt(s*(s-a)*(s-b)*(s-c));

}
double mymax(double a, double b){
    if(cmp(a,b) == 1 ) return a;
    return b;      
    
}
int main (int argc, char const* argv[]){
    int T;
    sc1(T);
    int n;
    double k;
    while(T--){
        v.clear();
        sc1(n);
        fr(i,0,n){
            scanf("%lf", &k);
            v.pb(k);
        }
        double res = 0, r;
        sort(v.begin(), v.end());
        for(int i = v.size()-1; i>= 2; i--) {
          if(ok(v[i], v[i-1], v[i-2] ) ) {
            
            r = area(v[i], v[i-1], v[i-2] );
            res = mymax(res, r);
          //  break; 
          } 
            
            
        }
        printf("%.2lf\n", res);
        
        
        
    }
        
    
        
    
    
    return 0;
}









