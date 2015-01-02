#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;

struct node {
	int n, d;
	node(){}
	node(int _n, int _d){ n=_n; d=_d; }
	bool operator < (const node &n) const{ return d < n.d;}
};
typedef priority_queue<node> pqn;

vii nos[40];
pqn q;
char arr[40][15];

int dist[40];

int foo(int ini){
	mst(dist, inf);
	dist[ini]=0;
	q.push(node(ini, 0));	
	int s, adj, w, no, d;
	node k;
	while(!q.empty()){
		k = q.top(); q.pop();
		no = k.n; d=k.d;
		if(dist[no]!=d) continue;
		s = nos[no].size();
		fr(i,0,s){
			adj = nos[no][i].first;
			w = nos[no][i].second;
			if(dist[adj] > d + w){
				dist[adj] = d +w;
				q.push(node(adj, dist[adj]));
			}
		}
	}
}	

int n, m;

void clear(){
	fr(i,0,n){
		nos[i].clear();
	}
}

int main (int argc, char const* argv[]) {
	
	int a, b, w;
	char str[15];
	int t = 0;
	while(1){
		t++;
		sc2(n, m);
		if(!n && !m) break;
		//pf(n) pf(m) _
		clear();
		fr(i,0,n) { scanf("%s", arr[i]);  }
		fr(i,0,m){
			sc3(a,b,w);
			a--; b--;
			nos[a].pb(mp(b,w));
			nos[b].pb(mp(a,w));
		}	
		
		int d=inf, sum=0, res=0;	
		fr(i,0,n){
			foo(i);
			sum=0;
			fr(j,0,n) {
				if(j==i) continue;
				sum+=dist[j];
			}
			if(sum < d) {
				res = i; d=sum;
			}
		}
		printf("Case #%d : %s\n", t, arr[res]);
	}
	return 0;
}










