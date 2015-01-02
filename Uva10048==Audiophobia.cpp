#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-5
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


int rep[1000];
int init(int n){ fr(i,0,n+2) rep[i]=i; }
int find(int a){ return rep[a] = (rep[a]==a) ? a: find(rep[a]); }
void uni(int a, int b){ rep[find(a)] = find(b); }
bool iss(int a, int b){ return find(a)==find(b); }

struct edge {
	int a, b, w;
	edge(){}
	edge(int _a, int _b, int _w){ a=_a, b=_b, w=_w;}
	bool operator < (const edge &e) const{ return w < e.w;}
}; 
vector<edge> ve;

int c;
int r;
vii e[200];

void kruskal(){
	init(c);
	sort(ve.begin(), ve.end());
	fr(i,0,c+2) e[i].clear();
	int a, b, w, s = ve.size();
	fr(i,0,s){
		a = ve[i].a, b= ve[i].b, w = ve[i].w;
		if(iss(a,b)) continue;
		uni(a,b);	
		e[a].pb(mp(b,w));
		e[b].pb(mp(a,w) );
	}
}

bool mark[105];
bool dfs(int no, int f){
	if(no == f) return 1;
	mark[no]=1;
	int s = e[no].size();
	fr(i,0,s){
		if(mark[e[no][i].st]) continue;
		if(dfs(e[no][i].st, f)){
			r = max(r, e[no][i].nd);
			return 1;
		}
	}
	return 0;
}


int main (int argc, char const* argv[]) {
	int s, q, a, b, w  , t =0 ;
	bool first = 1;
	while(1){
		sc3(c, s, q); if(!c && !s && !q) break;
		t++;
		if(!first) printf("\n");
		ve.clear();
		fr(i,0,s){
			sc3(a,b,w);
			ve.pb(edge(a,b,w));
		}
		kruskal();
		printf("Case #%d\n", t);
		fr(i,0,q){		
			sc2(a,b);
			r = 0;
			mst(mark, 0 );
			if( dfs(a,b) ){
				printf("%d\n", r);
			}
			else printf("no path\n");
		}
		
		first = 0;
	}
	
	return 0;
}
