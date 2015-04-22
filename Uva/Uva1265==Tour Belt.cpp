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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

struct Edge{
	int a, b, w;
	Edge(){}
	Edge(int _a, int _b, int _w) {a=_a,b=_b,w=_w;}
	bool operator < (const Edge &e) const { return w > e.w; }
	bool operator == (const Edge &e) const { return w == e.w && a==e.a && b==e.b; }
	void pf(){ printf("[Edge | a: %d | b: %d | w: %d]\n", a, b, w); }
};
#define MAX_N 5001
int rep[MAX_N + 10];
int qtdRep[MAX_N + 10];
int MAIOR[MAX_N + 10][MAX_N + 10];
int MENOR[MAX_N + 10][MAX_N + 10];

void init ( int n  ){
	fe(i,0,n){
		rep[i] = i; qtdRep[i] = 1;
		fe(j,0,n) {
			MAIOR[i][j] = 0;
			MENOR[i][j] = inf;
		}
	}
}
int find(int a ){
	return (rep[a] == a)?a : rep[a] = find(rep[a]);
}

void uni(int a,int b){
	int ra = find(a), rb = find(b);
	rep[ra] = rb;
	qtdRep[rb] += qtdRep[ra];
	qtdRep[ra] = 0;
}
bool iss(int a,int b) {return find(a) == find(b); }

vector<Edge> edges;
ll SUM;
int N;
void go(){
	sort(edges.begin(), edges.end());
	Edge edge;
	int ra, rb, w;
	SUM = 0;
	int dentro, fora;
	fr(i,0,edges.size()) {
		edge = edges[i]; ra = find(edge.a), rb= find(edge.b), w =edge.w;
		if(ra == rb) continue;
		uni(ra, rb);
		dentro = inf, fora = 0;
		fe(j,1,N){
			MAIOR[j][rb] = MAIOR[rb][j] = max(MAIOR[j][rb], MAIOR[j][ra]);
			MENOR[j][rb] = MENOR[rb][j] = min(MENOR[j][rb], MENOR[j][ra]);
			
			if(iss(j, rb) ) {
				dentro = min(dentro, MENOR[j][rb]);
			}
			else {
				fora = max(fora, MAIOR[j][rb] );
			}
		}
		if( dentro > fora) {
			SUM += qtdRep[rb];
		}
	
	
	}


}


int main (int argc, char const* argv[]){
	int T, M, a, b, w;
	sc1(T);
	while(T--){
		sc2(N,M);
		init(N);
		edges.clear();
		fr(i,0,M){
			sc3(a,b,w);
			MAIOR[a][b] = MAIOR[b][a] = MENOR[a][b] = MENOR[b][a] = w;
			edges.pb(Edge(a,b,w) );
		}
		go();
		printf("%lld\n", SUM);
	
	
	
	
	
	
	}
	
	return 0;
}
























