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

int n, m;


int arr[10005];
int arr2[10005];
int main (int argc, char const* argv[]) {
int k;
int l;
int x;
    vi v;
    while(1){
        sc2(n,m); if(!n && !m) break;
        sc1(l);
        sc1(k);
        mst(arr, 0);
        mst(arr2, 0);
        v.clear();
        bool ok = 0;
        int qt;
        fr(i,0,k) {
            sc1(x); arr[x]++; arr2[x]++;
            if(arr[x] == 1 ) v.pb(x);
        }
        sort(v.begin(), v.end());
        int y;
        int cont = 0;
        if((100*n)%l == 0 ){
            qt = (100*n)/l;
          //  printf("precisa de %d\n", n);
            for(int i = v.size()-1; qt > 0 && i>= 0; i--){
                x = v[i];
                if(arr[x]<=0) continue;
                y = m - x;
                if(x ==y && arr[x] < 2 ) continue ;
                else if( y && ( y < 0 || arr[y] <= 0) ) continue;
                qt--;
                arr[x]--; 
                cont++;
                //printf("usou %d e %d\n", x, y);
                if(y) {arr[y]--; cont++; }
                i++;
            }
            if( qt <= 0 ){ ok = 1; 
          //  printf("ok 1\n"); 
            }
        }
        
        if(!ok){
            cont = 0;
            if((m*100)%l == 0 ){
                qt = (100*m)/l;
                for(int i = v.size()-1; qt > 0 && i>= 0; i--){
                    x = v[i];
                    if(arr2[x]<=0) continue;
                    y = n - x;
                       if(x ==y && arr2[x] < 2 ) continue ;
                    if( y && ( y < 0 || arr2[y] <= 0) ) continue;
                    qt--;
                    arr2[x]--; cont++;
                    if(y) { arr2[y]--; cont++; }
                    i++;
                }
                if( qt <= 0 ){
                 ok = 1; 
               //  printf("ok 2\n");
                  }
            }
            
        }
        
        if(ok) printf("%d\n", cont);
        else printf("impossivel\n");
        
    }
    
    
    return 0;
}











