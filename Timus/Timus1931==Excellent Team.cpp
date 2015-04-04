#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
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

ll a, b;
vi v;
int arr[100005];
int main (int argc, char const* argv[]){ 
    int n, k;
    sc1(n);
    fr(i,0,n){
        sc1(k);
        v.pb(k);
    }
    
    
    int m = 0, pos =0, i, j, cnt;
    i = 0;
    while( i < n ) {
        j = i+1;
        cnt = arr[i];
        while(1){
            if( j>=n){
                cnt += j-i-1;         
                if(cnt > m ){
                    m = cnt;
                    pos = i;
                }
                i = j; break;
            }
            arr[j]++;
            arr[i]++;
            if(v[j] >= v[i] ) {j++;continue;}
            if( v[j] < v[i]) {
                cnt += j-i;         
                if(cnt > m ){
                    m = cnt;
                    pos = i;
                }
                i = j; break;
            }
            
        }
    
    }
    
    pos++;
    printf("%d\n", pos);
    
    return 0;
}
