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

vi e[305];
int mark[305];

bool dfs(int no, int pai){
	bool ok = 1;
	int adj;	
	fr(i,0,3){
		 adj = e[no][i];
		 if( adj == pai ) continue;
		 if(mark[adj] == 0 ) {
		 	mark[adj] =  ( mark[no] == 1 ) ? 2 : 1;
		 	ok = ok && dfs(adj, no);
		 } 
		 if( mark[adj] == mark[no] ) return 0;
	}
	return ok;
}


int main (int argc, char const* argv[]) {
	int v, a, b;
	while(1){
		sc1(v); iz(v);
		fr(i,0,v+3){
			mark[i]=0;
			e[i].clear();
		}
		while(1){
			sc2(a,b);
			if(!a && !b) break;
			e[a].pb(b);
			e[b].pb(a);
		}
		bool ok = 1;
		bool allMark = 0;
		
		while(!allMark) { 
			allMark=1;
			for(int i=1; i<=v; i++){
				if (!mark[i] ) { 
					mark[i]=1; ok = ok && dfs(i,-1);
					allMark=0;
				}  
			}
		}
		
		if(ok) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}







