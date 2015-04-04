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

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = inf;

struct Edge{
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index): from(from), to(to), cap(cap), flow(flow), index(index){}
	
};


struct Dinic{
	int N;
	vector<vector<Edge> > G;
	vector<Edge *> dad;
	vi Q;
	Dinic(int N): N(N), G(N), dad(N), Q(N) {}
	void add(int from, int to, int cap){
		G[from].pb(Edge(from, to, cap, 0, G[to].size()));
		if(from==to) G[from].back().index++;
		G[to].pb(Edge(to, from, 0, 0, G[from].size() -1 ) );
	}
	
	long long BlockingFlow(int s, int t){
		fill(dad.begin(), dad.end(), (Edge *) NULL );
		dad[s] = &G[0][0] -1;
		int head = 0, tail = 0;
		//printf("CHEOU 1\n");
		Q[tail++] = s;
		while( head < tail ) {
			int x = Q[head++];
			for(int i = 0; i < G[x].size(); i++){
				Edge &e = G[x][i];
				if(!dad[e.to] && e.cap - e.flow > 0 ) {
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			
			}
		
		}
		//printf("CHEOU 1\n");
		
		if(!dad[t]) return 0;
		
		long long totflow = 0;
		for(int  i = 0; i < G[t].size(); i++){
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for(Edge *e = start; amt  && e != dad[s]; e = dad[e->from]){
				if(!e) { amt = 0; break; }
				amt = min(amt, e->cap - e->flow);
			}
			if(amt == 0) continue;
			for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]){
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		
		return totflow;
	}
	
	long long getmaxflow(int s, int t){
		ll totflow = 0;
		//printf("pegando %d -> %d\n", s, t);
		while( ll flow = BlockingFlow(s,t) ) {
			totflow += flow;
			//printf("deu flow %lld\n", flow);
		}
		return totflow;
	}
	
	
};







bool find(int i, const  VVI &w, VI &mr, VI &mc, VI &seen){
	fr(j, 0, w[i].size()){
		if(w[i][j] && !seen[j]) {
			seen[j] = true;
			if( mc[j] <0 || find(mc[j], w ,mr, mc , seen) ) {
				mr[i] = j;
				mc[j] = i;
				return true;
			}
		}
	
	}

	return false;
}

int match(const VVI &w, VI &mr, VI &mc){
	mr = VI(w.size(), -1);
	mc = VI(w[0].size(), -1);
	int ct = 0;
	fr(i,0,w.size()){
		VI seen(w[0].size());
		if(find(i,w,mr, mc, seen)) ct++;
	}
	return ct;
}


int main (int argc, char const* argv[]) {
	int n,m;
	vvi v;
	int src, dst, k, s;
	int OFS;
	int caso = 0;
	int w, a, b;
	while( sc3(n,m,k) == 3 ) {
		//printf("n: %d m %d k %d\n", n,m,k );
		src = n+m+6; 
		dst = n+m+8;
		caso++;
		//printf("oi3 \n");
		Dinic d = Dinic(n+m+13);
		//printf("oi4 \n");
		fe(i,1,n){
			sc1(w);
			//printf("adicionadno %d %d %d\n", i, dst, w);
			d.add(i, dst, w);
			
		}
		//printf("oi2 \n");
		OFS = n+1;
		fr(i,0,k){
			sc2(a,b);
			d.add(b+OFS, a, 1);
			
		
		}
		fe(i,1,m){
			d.add(src, i+OFS, 1);
		}
		//printf("oi\n");
		ll lol = d.getmaxflow(src, dst);
		printf("Instancia %d\n%lld\n", caso, lol);
	}
	
	
	return 0;
}










