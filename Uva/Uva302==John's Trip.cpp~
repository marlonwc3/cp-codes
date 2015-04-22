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

#define MAX_N 100 //  @@@@@@@@@ MUDARS

struct Edge{
	int a, b, c;
	Edge(){}
	Edge(int _a, int _b, int _c){
		a=_a,b=_b,c=_c;
	}
	bool operator < (const Edge &e) const {
		return c < e.c;
	}
};
vector<Edge> e[MAX_N];

list<int> cyc;
void go(list<int>::iterator i, int u ) {
	for(int  j = 0; j < (int)e[u].size(); j++){ 
		Edge v = e[u][j];
		if(v.b){
			e[u][j].b = 0;
			for(int k = 0; k < e[v.a].size(); k++ ){ 
				Edge uu = e[v.a][k];
				if(uu.a == u && uu.b ) {
					e[v.a][k].b = 0;
					break;
				}
			}
			go(cyc.insert(i,v.c), v.a );
		}
	}
}



int main (int argc, char const* argv[]){
	int a, b, c;
	int menor;
	
	while( 1) { 
		fe(i,0,44)e[i].clear();
		menor = inf;
		sc2(a,b); if(!a && !b) break;
		menor=min(menor,a); menor=min(menor,b);
	
		sc1(c);
		e[a].pb(Edge(b,1,c));
		e[b].pb(Edge(a,1,c));
		
		while(1){
			sc2(a,b); if(!a && !b) break;
		//	menor=min(menor,a); menor=min(menor,b);			
			sc1(c);
			e[a].pb(Edge(b,1,c));
			e[b].pb(Edge(a,1,c));					
		}
		fe(i,0,44) sort(e[i].begin(), e[i].end());
		
		bool ok=1;
		fe(i,0,44){
			if(!ok) break;
			ok&= (e[i].size() % 2 == 0);
		}
		
		if(ok){
			cyc.clear();
			go(cyc.begin(), menor );
			int s = cyc.size();
			//printf("s: %d\n", s);
			list<int>::reverse_iterator it = cyc.rbegin();
			printf("%d", *(it++) );
			for(; it!=cyc.rend(); it++){
				printf(" %d", *it);
			}
			_
		}
		else printf("Round trip does not exist.\n");
		_
		
	}
	


	return 0;
}




