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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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


int dist(ii a, ii b) { 
	return ( (a.st - b.st)*(a.st - b.st) + (a.nd - b.nd)*(a.nd -b.nd) );
}
int rep[205], N;
void init(){ fe(i,0,N+1) rep[i] = i; }
int find(int a){return (rep[a]==a) ? a : rep[a] = find(rep[a]);   }
void uni(int a, int b ){ rep[find(a)] = find(b); }
bool iss(int a, int b ){return find(a) == find(b); }

struct Edge{
	//int a, b; double w;
	int a, b; int w;
	Edge(){}
	//Edge(int _a, int _b, double _w){a=_a, b=_b, w=_w;}
	Edge(int _a, int _b, int _w){a=_a, b=_b, w=_w;}
	bool operator < (const Edge &e) const {
		return w < e.w;
		//if(fabs(w-e.w) <= EPS ) return 0;
		//return w  < e.w; 
	}
};
vector<Edge> edges;
int menor;
void go(){
	sort(edges.begin(), edges.end());
	menor = 0;
	int a, b; 
	fr(i,0,edges.size()){
		if(iss(0,1)) break;
		a = edges[i].a, b=edges[i].b;
	//	printf("a: %d | b: %d\n", a ,b );
		if(iss(a,b)) continue;
	//	printf("uniu | w: %lf\n", edges[i].w);
		uni(a,b);
		menor = max(menor,edges[i].w);
	
	
	}
	

}
ii todos[205];
vi v;
int main (int argc, char const* argv[]){
	int a, b;
	int t  =0 ;
	while( 1) {
		sc1(N); iz(N);
		t++;
		init();
		edges.clear();
		fr(i,0,N){
			sc2(a,b); todos[i] = mp(a,b);
			fr(j,0,i){
				edges.pb(Edge(j, i, dist(todos[j], todos[i] ) ));
			}
		}
		
		go();
//		printf("%d\n", menor);
		double r = sqrt(menor);
		printf("Scenario #%d\n", t);
		printf("Frog Distance = %.3lf\n", r);
		_
		
		
	}
	
	return 0;
}





