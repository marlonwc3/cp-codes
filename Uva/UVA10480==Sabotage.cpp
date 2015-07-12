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




const int MAX_N = 55, MAX_E = 500*6;
ll from[MAX_E], to[MAX_E], ant[MAX_E], cap[MAX_E], adj[MAX_N], inde;
ll level[MAX_N], fila[MAX_N], copy_adj[MAX_N];

inline void add(ll a,ll b, ll c){
	from[inde] = a; to[inde] = b; cap[inde] = c; ant[inde] = adj[a]; adj[a] = inde++;
	from[inde] = b; to[inde] = a; cap[inde] = 0; ant[inde] = adj[b]; adj[b] = inde++;
}

ll dfs(ll no, ll sink, ll flow){
	if(no == sink) return flow;
	for( ll& i = copy_adj[no]; ~i; i = ant[i] ){
		if(cap[i] && level[no] +1 == level[to[i]]){
			ll nflow = dfs(to[i], sink, min(cap[i], flow));
			if(nflow){
				cap[i] -= nflow; cap[i^1] += nflow;
				return nflow;
			}
		}
	}
	return 0;
}


ll bfs(ll source, ll sink){
	memset(level, -1, sizeof level);
	level[source] = 0;
	ll pos = 0, tam = 0;
	fila[tam++] = source;
	while ( pos < tam ) {
		ll now = fila[pos++];
		for( ll i = adj[now]; ~i; i = ant[i]){
			if(cap[i] && level[to[i]] == -1){
				level[to[i]] = level[now] + 1;
				fila[tam++] = to[i];
				
			}
		
		}
	}

	return level[sink] != -1;
}

ll maxflow(ll source, ll sink){
	ll mf = 0;
	while(true){
		if( bfs(source,sink) ) {
			memcpy(copy_adj, adj, sizeof adj);
			while(1){
				ll add = dfs(source, sink, linf);
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

int NEXT=0;



int N,M;
int main (int argc, char const* argv[]){
	int a ,b ,c;
	while(1){
		sc2(N,M); if(!N && !M) break;


		inde = 0;
		mst(adj, -1);
		fr(i,0,M){
			sc3(a,b,c);	
			add(a,b,c);
			add(b,a,c);
		}
		ll r=	maxflow(1,2);
		//printf("r: %d\n", r);
		
		//go(1);
		bool round = 1;
		for(int i = 1; i<=N;i++){
			for(int u = adj[i]; u>=0; u = ant[u]){
				
				if(round && level[from[u]] != -1 && level[to[u]] == -1 ) printf("%lld %lld\n", from[u], to[u]);
				round = !round;
			}
		}
		_		
		
	}
	
	
	return 0;
}











