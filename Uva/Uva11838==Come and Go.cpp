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
int n, m;
vi e[2135];
bool mark[2135];

void dfs(int a){
    mark[a]=1;
    int s = e[a].size();
    fr(i,0,s){
        if(!mark[e[a][i]]){
            dfs(e[a][i]);
        }
    }
}

int main (int argc, char const* argv[]) {
    int a,b,c;
    while(1){
        sc2(n,m);
        if(!n && !m) break;
        fe(i,0,n+2){ e[i].clear(); }
        mst(mark, 0);
        fr(i,0,m){
            sc3(a,b,c);
            e[a].pb(b);
            if(c==2){
               e[b].pb(a);
            }
        }
        bool res = 1;
        fe(i,1,n){
            mst(mark, 0);
            dfs(i);
            bool ok=1;
            fe(i,1,n){
                ok = ok && mark[i];
                if(!ok) break;
            }          
            if(!ok){res=0; break;}
        }        

        printf("%d\n", res);
    
        
    
    } 
    
        
    
    
    
    return 0;
}



