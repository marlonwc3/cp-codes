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
 
vi e[1005];
vii v;
int n;
 
int dist(ii a, ii b){
        return (a.st - b.st)*(a.st - b.st) + (a.nd - b.nd)*(a.nd - b.nd);
}
 
int cnt;
bool mark[1005];
void dfs(int no){
        mark[no]=1;
        cnt++;
        int s = e[no].size();
        fr(i,0,s){
                if(mark[ e[no][i] ]) continue;
                dfs(e[no][i]);
        }
}
 
int main(int argc, char const *argv[]) {
        int x, y;// xi, yi;
        while(1){
                sc1(n); iz(n);
                v.clear();
                fr(i,0,n){
                        sc2(x,y);
                        e[i].clear();
                        v.pb(mp(y,x));
                }              
                int d1, d2, d, k1, k2;
                ii p1, p2;
                fr(i,0,n){
                        d1 = d2 = inf;
                        bool ok=0;
                        fr(j,0,n){
                                if(i==j) continue;
                                d = dist(v[i], v[j]);
                                ok = 0 ;
                                if( d < d1 ){
                                        d1 = d, p1 = v[j], k1 = j, ok = 1;
                                }
                                else if( d == d1){
                                        if(v[j].nd < p1.nd) d1 = d, p1 = v[j], k1 = j, ok = 1;
                                        else if( v[j].nd == p1.nd && v[j].st > p1.st) d1 = d, p1 = v[j], k1 = j, ok = 1;
                                }
 
                                if( d < d2 && !ok ){
                                        d2 = d, p2 = v[j], k2 = j;
                                }
                                else if( d == d2 && !ok ){
                                        if(v[j].nd < p2.nd) d2 = d, p2 = v[j], k2 = j;
                                        else if( v[j].nd == p2.nd && v[j].st > p2.st) d2 = d, p2 = v[j], k2 = j;
                                }
                        }
                        if(d1 < inf ) e[i].pb( k1 );
                        if(d2 < inf ) e[i].pb( k2 );                   
                }
                cnt = 0;
                mst(mark, 0);
                dfs(0);
                if(cnt == n) printf("All stations are reachable.\n");
                else printf("There are stations that are unreachable.\n");
        }
        return 0;
}
