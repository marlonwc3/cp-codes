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


int n, m, rep[105];
void init(){ fe(i,0,n) rep[i]=i; }
int find(int a){return rep[a] = (rep[a]==a) ? a: find(rep[a]); }
void uni(int a, int b){ rep[find(a)] = find(b); }
bool iss(int a, int b) { return find(a)==find(b); }

struct edge {
    int a, b, w, mark;
    edge(){mark=0;}
    edge(int _a, int _b, int _w){a=_a, b=_b, w=_w, mark=0;}
    bool operator < (const edge &e) const{ return w < e.w; }
};
vector<edge> ve;
vi pos;
int kruskal(bool first){
    init();
    int a, b, w, sum=0, mark;
    fr(i,0,m){
        a = ve[i].a, b = ve[i].b, w = ve[i].w, mark = ve[i].mark;
        if(!first && mark) continue;
        if( iss(a,b) ) continue;
        uni(a,b);
        sum += w;
        if(first) pos.pb(i);
    }
    return sum;
}

bool conex(){
    bool ok  = 1;
    fe(i,2,n) if(!iss(1, i)) return 0;
    return 1;
}

int main(int argc, char const *argv[]) {
    int caso, a, b, w; 
    sc1(caso);
    fe(t, 1, caso){
        pos.clear();
        sc2(n,m);
        ve.clear();
        fr(i,0,m){
            sc3(a,b,w);
            ve.pb(edge(a,b,w));
        }
        sort(ve.begin(), ve.end());
        w = kruskal(1);
        printf("Case #%d : ", t);
        if(!conex())  printf("No way\n");
        else{
            w = inf;
            bool ok = 0;
            fr(i,0,pos.size()){
                ve[ pos[i] ].mark = 1;
                b = kruskal(0);
                if( conex()  ) {
                    ok = 1;
                    w = min( w, b );
                }
                ve[ pos[i] ].mark = 0;
            }
            if(!ok) printf("No second way\n");
            else printf("%d\n", w);
        }
    }
    return 0;
}