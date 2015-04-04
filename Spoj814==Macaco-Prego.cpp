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
#define fe(i,a,b) for(int i=a; i <= b; i++)
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
typedef pair<char, int> ci;
typedef long double lb;
#define LSOne(S) ( S & (-S))


bool in(int a, int b, int c){
    return a >= b && a <= c;
}

int main (int argc, char const* argv[]) {
    int n;
    int a1, b1, c1, d1;
    int a2, b2, c2, d2, a3, b3, c3, d3;
    int t = 0;
    while(1){
        sc1(n); iz(n);
        t++;
        sc4(a1,b1, c1,d1);
        n--;
        bool ok = 1;
        
        while(n--){
            sc4(a2, b2, c2, d2);
            c3 = min(c1, c2);
            d3 = max(d1, d2);
            
            a3 = max(a1, a2);
            b3 = min(b1, b2);

            bool bottom =   in(c3, a2, c2 ) && in(c3, a1, c1) && in(d3, d2, b2)  && in(d3, d1, b1) ;
            bool top =   in(a3, a2, c2 ) && in(a3, a1, c1) && in(b3, d2, b2)  && in(b3, d1, b1) ;
           // printf("a1: %d | b1: %d | c1: %d | d1 : %d | bott %d | top %d\n", a1, b1, c1, d1, bottom, top);
           // printf("%d %d %d %d\n", a3, b3, c3, d3);
                        
            if (!bottom || !top) { // bottom
               ok = 0; 
            }
            else {
                a1 = a3, b1 = b3, c1 = c3, d1 = d3;
            }
            
            
            
        }
        if(!ok) printf("Teste %d\nnenhum\n", t);
        else printf("Teste %d\n%d %d %d %d\n",t, a1, b1, c1, d1);
        _
    
    
    
    }    
    
    
    
    return 0;
}

