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

int n;
vi e[205];
int mark[205];
bool dfs(int no){
	int s = e[no].size(), cor = mark[no], adj;
	bool ok;
	fr(i,0,s){
		adj = e[no][i];
		if(mark[adj] == cor) return 0;
		if(mark[adj]==0){
			mark[adj] = (cor==1) ? 2 : 1;
			ok = dfs(adj);
			if(!ok) return 0;
		}
	}
	return 1;
}

int main (int argc, char const* argv[]) {
	int l, a,b;
	bool ok;
	while(1){
		sc1(n); iz(n);
		fr(i,0,n+2) e[i].clear();
		mst(mark, 0);
		sc1(l);
		fr(i,0,l){
			sc2(a,b);
			e[a].pb(b);
			e[b].pb(a);
		}
		mark[0]=1;
		ok = dfs(0);
		
		if(ok) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	
	
	
	
	return 0;
}



















