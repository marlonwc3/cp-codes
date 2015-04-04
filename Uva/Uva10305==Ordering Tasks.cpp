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

int g[120], n, m ;
vi e[120]; 
queue<int> q;
vi topo;
void go(){
	q = queue<int>();
	fr(i,1,n+1){
		if(!g[i]) q.push(i);
	}
	int a,b, s;
	while(!q.empty()){
		a = q.front(); q.pop();
		s = e[a].size();
		topo.pb(a);
		fr(i,0,s){
			b = e[a][i];
			if(g[b]==0) continue;
			g[b]--;
			if(!g[b]) q.push(b);
		}
	}
}


int main (int argc, char const* argv[]) {
	int a, b;
	while(1){
		sc2(n,m); if(!n && !m) break;
		fr(i,0,n+5) {e[i].clear(); g[i]=0;}
		topo.clear();
		fr(i,0,m){
			sc2(a,b);
			e[a].pb(b);
			g[b]++;
		}
		go();
		printf("%d", topo[0]);
		fr(i,1,n) printf(" %d", topo[i] );
		_
	}
	return 0;
}







