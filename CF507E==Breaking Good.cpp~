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
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;


int tc, n, m;
struct Node {
	int no, d, c;
	Node(){}
	Node(int _no, int _d, int _c){ no=_no, d=_d, c=_c;}
	bool operator < (const Node &no) const{
		if(d == no.d){
			return c > no.c;
		}
		return d > no.d;
	}
};

int dist[100005], res;
int queb[100005];
vii e[100005];
ii pai[100005];
void go(){
	res = inf;

	priority_queue<Node> pq;
	mst(dist, inf);
	mst(queb, inf);
	Node node;
	int no, d, c, adj, s, k, w, q;
	pai[1]=mp(-1,0);
	dist[1] = 0;
	queb[1] = m-tc;
	pq.push(Node(1, 0, m-tc));
	while(!pq.empty()){
		node = pq.top(); pq.pop();
		no = node.no, d = node.d , c = node.c;
		if(dist[no] != d ) continue;
		if(queb[no] != c) continue;
		//printf("no: %d | d: %d | c: %d\n", no, d, c);

		if(no == n) {
			res= min(res, c);
		}

		s = e[no].size();
		fr(i,0,s){
			adj = e[no][i].st,  k = (e[no][i].nd);
			if(!k) w = c + 1;
			else w = c-1;

			if(dist[adj] > d+1){	
				dist[adj] = d+1;
				queb[adj] = w;
				pai[adj] = mp(no, i);
				pq.push(Node(adj, dist[adj], w) );
			}
			else if(dist[adj] == d+1) {
				if(queb[adj] > w){
					queb[adj] = w;
					pai[adj] = mp(no, i);
					pq.push(Node(adj, dist[adj], w) );					
				}
			}
		}
	}
}

sii myset;
void getTrace(int no){
	int p = pai[no].st, pos = pai[no].nd, k;
	if(p == -1 ) return; 
	k = e[p][pos].nd;
	if(!k){
		printf("%d %d 1\n", p, no );
	}	
	myset.insert(mp(p,no));
	myset.insert(mp(no,p));

	e[p][pos].nd = 2;
	getTrace(p);
}

int main(int argc, char const *argv[]) {
	sc2(n,m);
	int a, b, k;
	fr(i,0,m){
		sc3(a,b,k);
		e[a].pb(mp(b,k));
		e[b].pb(mp(a,k));
		tc += !k;
	}


	
	go();
	if(0) fe(i,0,n){
		printf("i: %d | pai: %d, %d \n", i, pai[i].st, pai[i].nd);
	}
	//printf("Tc: %d\n", tc);
	//printf("res: %d | d: %d \n", res, dist[n] );
	printf("%d\n", res);
	getTrace(n);
	int adj;
	fe(i,1,n){
		fr(j,0,e[i].size()){
			if(e[i][j].nd==1){
				adj = e[i][j].st;
				ii p1 = mp(i, adj);
				ii p2 = mp(adj, i);
				if(myset.count(p1) || myset.count(p2)  ) continue;
				myset.insert(p1);
				myset.insert(p2);
				printf("%d %d 0\n", i, e[i][j].st );
			}
		}
	}


	return 0;
}
