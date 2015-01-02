#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
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


/* se a definição de "reachable" for apeans a partir de um nó chegar em 1 nó com ou sem arestas, você pode botar o mark antes
	se a definição de reachable d eum nó p pra um q for existir um conjunto não nulo de arestas entre p e q, o mark deve ser depois
	para garantir que você só vai marcar se existir 1 aresta que chega!	
*/
vi e[105];
bool mark[105];
void dfs(int no){
	//mark[no] = 1;
	int s = e[no].size(), adj;
	fr(i,0,s){
		adj = e[no][i];
		if(mark[adj]) continue;
		mark[adj] = 1;
		dfs(adj);
	}
}

vi res;
int main (int argc, char const* argv[]) {
	int n, a, b, k;
	while(1){
		sc1(n); iz(n);
		fr(i,0,n+2) e[i].clear();
		while(1){
			sc1(a); iz(a);
			while(1){
				sc1(b); iz(b);
				e[a].pb(b);
			}
		}
			
		sc1(k);
		int cont;
		while(k--){
			sc1(a);
			mst(mark, 0);
			res.clear();
			
			dfs(a);
			fr(i,1,n+1){
				if(!mark[i]) res.pb(i);
			}
			cont = res.size(); 
			printf("%d", cont);
			fr(i,0,cont){	
				a = res[i];
				printf(" %d", a);
			}
			_
		}
	
	}
	
	
	
	return 0;
}
