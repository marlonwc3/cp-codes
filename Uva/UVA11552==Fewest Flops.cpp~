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

set<char> todos[1005];
int LIMIT;

int pd_ok[1005]['z' + 10], pd[1005]['z' + 10], PASSO;

int go(int p, char c){
    if(p >= LIMIT) return 0;
    if(pd_ok[p][c] == PASSO ) return pd[p][c];
    int s = todos[p].size();
    int r = todos[p].count(c) ? s-1 : s, r2 = inf;
    if( todos[p].size() == 1 && (*todos[p].begin())==c ){ 
        r = go(p+1, c);
    }
    else{
        for(set<char>::iterator it = todos[p].begin(); it != todos[p].end(); it++){
            if(*it == c) continue;
            r2 = min(r2, go(p+1, *it));
        }
        r += r2;
    }
    pd_ok[p][c] = PASSO;
    pd[p][c] = r;
    return r;
}


char str[1005];
int main (int argc, char const* argv[]){
    PASSO = 0;
    int caso;
    sc1(caso);
    
    int k, len;
    while(caso--){
        PASSO++;
        scanf("%d %s", &k ,str);
        len = strlen(str);
        LIMIT = len/k;
        fe(i,0,LIMIT+1) todos[i].clear();
        int p = 0;
        fr(i,0,LIMIT){
            int j = p;
            for(; j < p+k; j++){
             //   printf( "%d ", j);
                todos[i].insert(str[j]);
            }
           // _
            p= j;
        }
        
        int r = go(0, 0);
        printf("%d\n", r);
    
    }
    
    
    return 0;
}










