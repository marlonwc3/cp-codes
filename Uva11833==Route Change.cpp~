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

struct Node{
	int no, d;
	Node(){}
	Node(int _no, int _d){ no=_no, d=_d;}
	bool operator < (const Node &n) const{
		return d > n.d;
	}	
};

vi e[300];
map<ii, int> mw;
int dist[300];
int n, m, c;
int res;

/*
SE PASSAR EU XOXI
TO LGD NA SUA DUHAN
parem de me espionar

*/
void go(int k){
	priority_queue<Node> pq;
	mst(dist, inf);
	int no, adj, s, d, w;
	Node node;
	dist[k] = 0;
	pq.push(Node(k, 0));
	res = inf;
	while(!pq.empty()){
		node = pq.top(); pq.pop();
		no = node.no, d = node.d;
		if( no == c-1 ){
			res = min(res, d);
			break;
		}
		else if( no < c-1 ){
			adj = no+1;
			int p  = lower_bound(e[no].begin(), e[no].end(), adj) - e[no].begin();
			w = mw[mp(no, adj)];
			if( dist[adj] > dist[no] + w ){
				dist[adj] = dist[no]+w;
				pq.push(Node(adj, dist[adj]));
			}
			
		} 
		else{
			s = e[no].size();
			fr(i,0,s){
				adj = e[no][i];
				w = mw[mp(no, adj)];
				if( dist[adj] > dist[no] + w ){
					dist[adj] = dist[no]+w;
					pq.push(Node(adj, dist[adj]));
				}
			
			}
		}
		
		
	}
	


}



int main (int argc, char const* argv[]) {
	int k;
	int a, b, w;
	while(1){
		sc4(n, m, c, k);
		if(!n && !k && !c && !k) break;
		mw.clear();
		fe(i,0,n) e[i].clear();
		fr(i,0,m){
			sc3(a,b,w);
			e[a].pb(b);
			mw[mp(a,b)] = w;
			
			e[b].pb(a);
			mw[mp(b,a)] = w;
			
		}
	
		go(k);
		printf("%d\n", res);
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}











