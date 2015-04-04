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


int arr[10005];
bool mycmp(int a, int b){
    return a>b;
}
vi v;
int main (int argc, char const* argv[]) {
    int caso;
    sc1(caso);
    int n, x, w;

    fe(t,1,caso){
        sc2(n, x);
        mst(arr, 0);
        v.clear();     
        fr(i,0,n){
            sc1(w);
            arr[w]++;
            if(arr[w] == 1 ) v.pb(w);
        }
        sort(v.begin(), v.end());
        int res = 0;
        int tem = x;
        int cnt = 0;
        int y, lol, p;

        int i =0;
       // pv(v,o);
        while( i < v.size() ) {
            w = v[i];
          //  printf("w: %d\n", w);
            if(arr[w] <= 0 ) {
                i++; continue;
            }
            arr[w]--;
            y = x - w;
           // printf("botando %d sobrou %d\n", w, y);            
            p = lower_bound(v.begin(), v.end(), y) - v.begin() ;
            if( p >= v.size() ) p--;
            while ( p >= 0 )  {
                lol = v[p]; 
                if(lol <= y && arr[lol] > 0) {
                    arr[lol]--;
             //       printf("botou tb %d\n", lol );
                    break;
                }
                
                p--;
            } 
            
            res++;
        }

        printf("Case #%d: %d\n", t, res);
    }    
        
    
    
    
    return 0;
}




