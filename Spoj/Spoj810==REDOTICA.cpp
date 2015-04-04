#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


struct Edge {
	int a, b, w;
	Edge(){}
	Edge(int _a, int _b, int _w){ a=_a; b = _b; w = _w; }
	bool operator < (const Edge &e) const{ return w > e.w; }
};
typedef priority_queue<Edge> pq;

pq q;
bool mark[105][105];
int rep[105], n, m;
void init(){ for(int i=0 ; i <= n; i++ ) rep[i]=i; }
int find(int a) { return rep[a] =  (rep[a]==a) ? a : find(rep[a]);   }
void uni(int a, int b){ rep[find(b)] = find(a); }
bool is(int a, int b){ return find(a) == find(b);}

vector<Edge> ve;
void kruskall(){
//	int cont =0 ;
	Edge e;
	ve.clear();
	mst(mark,0);
	init();
	while(!q.empty() ) {
		e = q.top(); q.pop();
		if ( is(e.a, e.b)  )   continue;
		if( mark[e.a][e.b] || mark[e.b][e.a] ) continue;
		uni(e.a, e.b);
		mark[e.a][e.b] = mark[e.b][e.a] = 1;	
		ve.pb(e);	
	//	cont += e.w;
	}
//	printf("cont -> %d\n", cont);
}






int main (int argc, char const* argv[]) {
	int a, b, w , t = 0;
	while(1){
		t++;
		sc2(n,m);
		if(!n && !m) break;
		fr(i, 0, m){	
			sc3(a,b,w);
			q.push(Edge(min(a,b),max(a,b) ,w));
		}
		
		kruskall();
		
		printf("Teste %d\n", t);
		w = ve.size();
		fr(i,0,w){
			a = ve[i].a; b = ve[i].b;
			printf("%d %d\n", a , b);
		}
		_
	}
	
	
	return 0;
}












