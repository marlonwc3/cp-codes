#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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

int n, m, rep[205];

void init(){ fe(i,0,n) rep[i]=i; }
int find(int a){return rep[a] = (rep[a]==a) ? a : find(rep[a]);}
void uni(int a, int b){ rep[find(a)] = find(b); }
bool iss(int a,int b){ return find(a)==find(b); }

struct edge {
    int a, b, w;
    edge(){}
    edge(int _a, int _b, int _w){ a=_a, b=_b, w = _w;}
    bool operator < (const edge &e) const{ return w > e.w; }
};

vector<edge> ve;
vii e[205];
int kruskal(){
    fe(i,0,n) {  rep[i]=i, e[i].clear(); }  
    int a ,b, w;
    sort(ve.begin(), ve.end());
    fr(i,0,m){
        a = ve[i].a, b=ve[i].b, w = ve[i].w;
        if(iss(a,b)) continue;
        uni(a,b);
        e[a].pb(mp(b,w));
        e[b].pb(mp(a,w));
    }
}

bool mark[205];
int res;
bool dfs(int no, int f){
    mark[no]=1;
    if(no == f ) return 1;  
    int s = e[no].size();
    fr(i,0,s){
        if(mark[e[no][i].st ] ) continue;
        if(dfs( e[no][i].st, f ) ){
            res = min(res, e[no][i].nd );
            return 1;
        }
    }
    return 0;
}

map<string, int> mymap;
char str[50], str2[50]; 

int main(int argc, char const *argv[]) {
    int w,a, b, next, t = 0;
    while(1){
        sc2(n,m);
        if(!n && !m) break;
        t++;
        next = 1;
        mymap.clear();
        ve.clear();
        res = inf;
        fr(i,0,m){
            scanf("%s %s %d", str, str2, &w);
            a = mymap[str];
            if(!a) { mymap[str] = next++; a = next-1; }
            b = mymap[str2];
            if(!b) {mymap[str2] = next++; b = next-1; }
            ve.pb( edge(a,b,w) );
        }
        kruskal();
        scanf("%s %s", str, str2);
        a = mymap[str];
        if(!a) { mymap[str] = next++; a = next-1; }
        b = mymap[str2];
        if(!b) {mymap[str2] = next++; b = next-1; }        

        mst(mark, 0);
        w = dfs(a, b);
        printf("Scenario #%d\n", t);
        printf("%d tons\n", res);
        _
    }
    return 0;
}