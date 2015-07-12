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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const int MAX_N = 5015, MAX_E = 30000;
int from[MAX_E], to[MAX_E], ant[MAX_E], cap[MAX_E], adj[MAX_N], inde;
int level[MAX_N], fila[MAX_N], copy_adj[MAX_N];

inline void add(int a,int b, int c){
	from[inde] = a; to[inde] = b; cap[inde] = c; ant[inde] = adj[a]; adj[a] = inde++;
	from[inde] = b; to[inde] = a; cap[inde] = 0; ant[inde] = adj[b]; adj[b] = inde++;
}

int dfs(int no, int sink, int flow){
	if(no == sink) return flow;
	for( int& i = copy_adj[no]; ~i; i = ant[i] ){
		if(cap[i] && level[no] +1 == level[to[i]]){
			int nflow = dfs(to[i], sink, min(cap[i], flow));
			if(nflow){
				cap[i] -= nflow; cap[i^1] += nflow;
				return nflow;
			}
		}
	}
	return 0;
}


int bfs(int source, int sink){
	memset(level, -1, sizeof level);
	level[source] = 0;
	int pos = 0, tam = 0;
	fila[tam++] = source;
	while ( pos < tam ) {
		int now = fila[pos++];
		for( int i = adj[now]; ~i; i = ant[i]){
			if(cap[i] && level[to[i]] == -1){
				level[to[i]] = level[now] + 1;
				fila[tam++] = to[i];
				
			}
		
		}
		
	
	}

	return level[sink] != -1;
}

int maxflow(int source, int sink){
	int mf = 0;
	while(true){
		if( bfs(source,sink) ) {
			memcpy(copy_adj, adj, sizeof adj);
			while(1){
				int add = dfs(source, sink, 1 << 30);
				if( add ) mf += add;
				else break;
			}
		
		}
		else {
			break;
		}
	
	
	}

	return mf;
}

const int des[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0} };

int source, sink; 
/*
	inde = 0;
	mst(adj, -1);
*/
ii mat[55][55];
int N, M, K;
bool border(int x, int y){
	return x == 1 || x == N || y == 1 || y == M;
}

int ja[55][55], PASSO = 0;

int main (int argc, char *argv[]){
	int x, y, dx, dy;
	int caso, next;
	
	sc1(caso);
	while(caso--){
		PASSO++;
		inde = 0;
		mst(adj, -1);
		next  = 1;
		sc3(N,M,K);
		bool ok  =  K <= N*M;
		if(ok){
			fe(i,1,N) fe(j,1,M){
				mat[i][j] = mp(next, next+1);
				add(next, next+1, 1);
				next+=2;
			}		
			source = next+1; sink = source+1;
			fe(i,1,N){
				fe(j,1,M){
					fr(k,0,4){
						dx = i + des[k][0]; dy = j + des[k][1];
						if( dx <= 0 || dx > N || dy <= 0 || dy > M ) continue;
						add(mat[i][j].nd, mat[dx][dy].st, 1 );
					}
					if(border(i,j)){
						add(mat[i][j].nd, sink, 1);
					}
				}
			}
		}

		fr(i,0,K){
			sc2(x, y);
			if(ja[x][y] == PASSO ) ok = 0;
			ja[x][y] = PASSO;
			add(source, mat[x][y].st, 1);
		}
		int r = -inf;
		if(ok) r = maxflow(source, sink);
		if(r >= K) printf("possible\n");
		else printf("not possible\n");
	
	
	}
	
	
	
	return 0;
}














