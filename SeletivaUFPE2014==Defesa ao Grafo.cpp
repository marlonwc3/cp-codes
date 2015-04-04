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

struct Node {
	int no; ll w;
	Node(){}
	Node(int _no, ll _w){ no=_no; w=_w;}
	bool operator < (const Node &no) const{ return w > no.w;}
};

int n,m,f;

vi e[1005];
ll d[1005];



ll dist[1005];
void go(int no){
	Node node;
	int s, adj; ll w;
	priority_queue<Node> pq;
	fe(i,0,n) dist[i] = linf;
	pq.push(Node(no, 0) );
	dist[no] = 0;
	while(!pq.empty()){
		node = pq.top(); pq.pop();
		no = node.no; w = node.w;
		if(dist[no] != w ) continue;
		s = e[no].size();
		fr(i,0,s){
			adj = e[no][i];
			if(dist[adj] > w + d[adj]) {
				dist[adj] = w + d[adj];
				pq.push(Node(adj, dist[adj]) );
			}
			
		}
	
	
	}
	
}

int h[10005];
int ki[10005];


int main (int argc, char const* argv[]) {
	int caso, f, a, b;
	int k, hp;
	sc1(caso);
	fe(t,1,caso){
		sc3(n, m , f);
		fe(i,0,n) e[i].clear();
		fr(i,0,m){
			sc2(a,b); a--; b--;
			e[a].pb(b); e[b].pb(a);
		}
		fr(i,0,n) scanf("%lld", &d[i]);
		int q;
		sc1(q);
		f--;
		go(f);
		if(0)fr(i,0,n){
			printf("d(%d, %lld)\n", i, dist[i]);
		}
		ll total;
		int res = 0;
		fr(i,0,q){
			sc2(k , hp); k--;
			total = dist[k];
		//	printf("hp: %d | k: %d | total: %lld \n ", hp, k , total);
			
			if(hp > total)	{
				res++;
			}		
		}
		printf("Caso #%d: %d\n", t, res);

		
		
		
		
		
	
	}
	
	
	
	return 0;
}











