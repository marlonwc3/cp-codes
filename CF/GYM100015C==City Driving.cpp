#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second  
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
#define clr(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;  // ou <climits>
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
 
struct Edge{
    int a, b, c, w;
    Edge(){}
    Edge(int _a){ a=_a; }
    Edge(int _a, int _b, int _w ) { a=_a, b=_b, w=_w;  c=0; }
    void pf(){
        printf("[Edge | a: %d | b: %d | c: %d | w: %d \n", a, b, c, w);
    }
};
 
const int MAX_N = 100000;
const int log_MAX_N = 17;
int log_N, root;
int rep[MAX_N + 5];
int mark[MAX_N + 5], PASSO= 0;
int mark2[MAX_N+5], PASSO2=0;
int freq[2*MAX_N + 5];
int onde[MAX_N + 5]; 
int A[MAX_N][log_MAX_N];  
int L[MAX_N + 2];  
vector<Edge> edgeList[MAX_N + 5];
vector<Edge> e[MAX_N + 5];
int dfs_parent[MAX_N + 5],  dfs_num[MAX_N + 5], dfs_low[MAX_N + 5];



const bool PRINT_EDGE = false; 

void init(int N){ fe(i,0,N+1)rep[i] = i; }
int find(int a ){ return (rep[a] == a) ? a : (rep[a] = find(rep[a])  );  }
bool iss(int a,int b){ return find(a) == find(b); }
void uni(int a,int b){ rep[find(a)] = find(b); }
 

int dfsNumberCounter, dfsRoot, rootChildren;
void go(int u) {
        dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
        int v;
        for (int j = 0; j < (int)edgeList[u].size(); j++) {
                v = edgeList[u][j].a;
                if (dfs_num[v] == 0){
                        dfs_parent[v] = u;
                        if (u == dfsRoot) rootChildren++;
                        go(v);
                        if (dfs_low[v] > dfs_num[u]){  
                            edgeList[u][j].b = 0;
                            edgeList[v][edgeList[u][j].c].b = 0;
                            if( PRINT_EDGE)   printf(" Edge (%d, %d) is a bridge\n", u, v);
                        }
                        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                }
                else if (v != dfs_parent[u])
                        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
}
int N;
void getBridges(){
        dfsNumberCounter = 0;  
        fr(i,0,N ){
                if(dfs_num[i] == 0 ) {
                        dfsRoot = i; rootChildren = 0;
                        go(i);
                }
        }
}
int mc;
int first, last;   
void dfsBuild(int a, int c=0, int w=0){
    mark[a] = PASSO;
    freq[c] = w;
    onde[a] = c; 
    if(c > mc ) {
        last = a;
        mc = c; 
    }
    fr(i,0,edgeList[a].size() ) {
        if(edgeList[a][i].b  && mark[edgeList[a][i].a] != PASSO )  {
            if(!c) first = a; 
            uni(a, edgeList[a][i].a );
            dfsBuild(edgeList[a][i].a, c+1, w + edgeList[a][i].w);
        }
    }
}
int rDif; 

int cicleDist(int a, int b ){ 
    if(onde[b] < onde[a] ) swap(a,b); 
    return min( abs(freq[onde[b]] - freq[onde[a]]),  abs(freq[onde[a] + mc] - freq[onde[b]]) );
}

int lb(unsigned int n){
    if(n==0) return -1;
    int p = 0;
    if (n >= 1<<16) { n >>= 16; p += 16; }
    if (n >= 1<< 8) { n >>=  8; p +=  8; }
    if (n >= 1<< 4) { n >>=  4; p +=  4; }
    if (n >= 1<< 2) { n >>=  2; p +=  2; }
    if (n >= 1<< 1) {           p +=  1; }
    return p;
}
void DFS(int i, int l){
    L[i] = l;
    for(int j = 0; j <  edgeList[i].size(); j++){ 
        DFS(edgeList[i][j].a, l+1);
    }
}
int LCA(int p, int q){
    if(L[p] < L[q])
    swap(p, q);
    for(int i = log_N; i >= 0; i--)
    if(L[p] - (1<<i) >= L[q])
        p = A[p][i];
    if(p == q) return p;
    for(int i = log_N; i >= 0; i--)
    if(A[p][i] != -1 && A[p][i] != A[q][i]){
        p = A[p][i];
        q = A[q][i];
    }
    return A[p][0];
}



int buildTree(int a,int p=-1){  
    A[a][0] = p; 
    mark2[a] = PASSO2;
    if(p!=-1 && !iss(a,p) ){
        if(mark[p] != PASSO ) {
            edgeList[p].clear();
            mark[p] = PASSO;
        }
        edgeList[p].pb(Edge(a));
    }
    else {root = a; }
    int b;
    fr(i,0,e[a].size() ) {
        b = e[a][i].a; 
        if(b != p && mark2[b] != PASSO2 ) buildTree(b, a);
    }

}
void preprocessLCA() {
	mst(L, 0);
    log_N=lb(N);
    PASSO2++;
    PASSO++;
    buildTree(rDif); 
    for(int j = 1; j <= log_N; j++)
    for(int i = 0; i < N; i++)
        if(A[i][j-1] != -1) A[i][j] = A[A[i][j-1]][j-1];
        else A[i][j] = -1;
    DFS(root, 0);
}

Edge lastEdge;
int getEdge(int a, int lca){
    if(a == lca) return 0;
    mark[a] = PASSO;
    int b;
    int sum = 0 ; 
    fr(i,0,e[a].size() ) {
        b = e[a][i].a;
        if(mark[b] == PASSO || L[b] > L[a] ) continue; 
        sum = e[a][i].w + getEdge(b, lca); 
        if(b == lca) {
            lastEdge = e[a][i]; 
        }
        return sum;
        
    }
    return 0;
    
}
int main (int argc, char const* argv[]){
    int a, b, w, Q;
    int lca, ans ;
    int c1, c2, r1, r2, r3; 
    while(1){
        sc1(N); iz(N);
        
        log_N = log(N)/log(2);
        init(N);
        fe(i,0,N) {
            dfs_num[i] = dfs_low[i] = 0;
            dfs_parent[i] = -1;
            edgeList[i].clear(); e[i].clear();
        }
        fr(i,0,N){
            sc3(a,b,w);
            edgeList[a].pb(Edge(b,1,w) );
            edgeList[b].pb(Edge(a,1,w) );
            edgeList[a].back().c = edgeList[b].size() - 1;
            edgeList[b].back().c = edgeList[a].size() - 1;
        }
        getBridges();
        PASSO++;
        mc = 0;
        fr(i,0,N){
            if(mark[i] != PASSO) { 
                dfsBuild(i);
            }
        }
        fr(i,0,N){
                a = find(i); 
                if(i != a ) rDif = a; 
                fr(j,0,edgeList[i].size() ) {
                        if(edgeList[i][j].b) continue; 
                        w = edgeList[i][j].w; 
                        b = find(edgeList[i][j].a);
                        e[a].pb(Edge(b,0,w)); e[a].back().c = edgeList[i][j].a;
                }      
        }
        fr(i,0,edgeList[last].size() )  if(edgeList[last][i].a == first ) {w = edgeList[last][i].w; break; }
        mc++;
        onde[first] = mc; 
        fe(i,0,N){
            edgeList[i].clear(); 
        }
        freq[mc] = freq[mc-1] + w;
        fr(i,mc+1, 2*mc +1 ) {
            freq[i] = freq[i-1] + freq[i-mc]-freq[i-mc-1]; 
        }
        preprocessLCA(); 
       sc1(Q);  
       fe(i,0,N) edgeList[i].clear(); 
        while(Q--){
            sc2(a,b);
            if(iss(a,b) ) {
                ans = cicleDist(a,b);
            }
            else{ 
                lca = LCA(a,b); lca = (lca==-1) ? rDif : lca;
                ans =  0;
                if(!iss(a, rDif) ){
		            PASSO++;
		            r1 = getEdge(a, lca);
		            c1 = lastEdge.c; 
		        } 
                else { r1 = 0; c1 = a; }
                
                if(!iss(b, rDif)  ){ 
		            PASSO++; 
		            r2 = getEdge(b, lca);
		            c2 = lastEdge.c; 
                } 
                else {r2 = 0; c2 = b;  } 
                ans += r1 + r2;
                if(lca == rDif ) {
                    r3 = cicleDist(c1, c2);	 
                }
                else r3 = 0; 
                ans += r3;
            } 
         	printf("%d\n", ans ); 
        }
    }
    return 0;
}
