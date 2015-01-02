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
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;


int n,m;
struct edge{
	int a, b;
	double w;
	edge(){}
	edge(int _a, int _b, double _w){
		a=_a, b=_b, w=_w;
	}
	bool operator < (const edge &e) const{
		return w < e.w;
	}
};
vector<edge> ve;
int rep[120];
void init(int k){ fr(i,0,k+2) rep[i]=i;}
int find(int a) { return rep[a]= (rep[a]==a)?a : find(rep[a]);  }
bool iss(int a, int b) { return find(a)==find(b); }
void uni(int a, int b ) {  rep[find(a)] = find(b);  }

vector<pair<int, double> > e[105];

void kruskal(){
	init(m);
	sort(ve.begin(), ve.end());
	int s = ve.size(), a,b;
	double w;
	fr(i,0,s){
		a = ve[i].a, b = ve[i].b, w = ve[i].w;
		if(iss(a,b)) continue;
		uni(a,b);
		e[a].pb( mp(b,w) );
		e[b].pb( mp(a,w) );
	}
}

bool mark[105];
double res;
bool dfs(int no, int f){
	if(no==f) return 1;
	int s = e[no].size(), adj;
	mark[no]=1;
	fr(i,0,s){
		adj = e[no][i].st;
		if(mark[adj]) continue;
		if(dfs(adj, f)){
			res = max(res, e[no][i].nd );
			return 1;
		}
	}
	return 0;
}

double dist(int a, int b, int c, int d){
	return sqrt(  (a-c)*(a-c) + (b-d)*(b-d)  );
}

int main (int argc, char const* argv[]) {
	vi v;
	vii p;
	int x, y , x1, y1, x2, y2;
	double d;
	while(1){
		sc2(n,m);
		if(n==-1 && m==-1) break;
		ve.clear();
		mst(mark, 0);		
		fr(i,0,m+2) e[i].clear();
		v.clear();
		p.clear();
		res = 0;
		fr(i,0,n){
			sc1(x);
			v.pb(x);
		}
		sc4(x1, y1, x2, y2);
		p.pb( mp(x1,y1) );
		p.pb( mp(x2,y2) );
		fr(i,0,m-2){
			sc2(x,y);
			p.pb(mp(x,y));
		}
		fr(i,0,m){
			x1 = p[i].st, y1 = p[i].nd;
			fr(j,i+1, m){
				x2 = p[j].st, y2 = p[j].nd;
				d = dist(x1,y1, x2, y2);
				ve.pb( edge(i,j, d) );
			}
		}
		kruskal();
		dfs(0,1);
		int cnt = 0;
		
		fr(i,0,n){
			if( (v[i]+0.0) < res  ) cnt++;
		}
		bool ok = cnt >  (n/2); 
		if(ok) printf("valid\n"); 
		else printf("NOT valid\n");
	}
	
	return 0;
}


