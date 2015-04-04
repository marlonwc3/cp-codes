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


vii e[100005];
bool amg[100005];
int n, f;

typedef pair<ll, bool> llb;
ll maior;
llb  go(int no, int pai, ll cnt){
    int s = e[no].size(), adj, w;
    bool ok = amg[no];
    if(ok){
        maior = max(maior, cnt);
    }
    
    //printf(" @ no: %d | amg: %d\n", no, ok);    
    ll res = 0;
    fr(i,0,s){
        adj = e[no][i].st, w = e[no][i].nd;
        if(adj == pai ) continue;
        llb ret = go(adj, no, cnt + w);
        if(ret.nd){
            ok = 1;
            res += ret.st + w;
        }
    }
   // printf("no %d | res: %lld | ok: %d\n", no, res, ok);
    return mp(res, ok);
}




int main (int argc, char const* argv[]){
    int a ,b, w;
    while(sc2(n,f)==2){
        fe(i,0,n) e[i].clear();
        mst(amg, 0);
        fr(i,0,n-1){
            sc3(a,b,w);
            e[a].pb(mp(b,w));
            e[b].pb(mp(a,w));
        }
        fr(i,0,f){
            sc1(a);
            amg[a] = 1;
        }
        maior = 0;
        llb res = go(1, -1, 0);
        //printf("maior %lld\n", maior);
        res.st -= maior;
        printf("%lld\n", res.st);
        
    }
    return 0;
}









