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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int N,M;
bool val(int x, int y){
	if( x < 0 || x >= N || y < 0 || y >= M) return 0;
	return 1;
}


set<string> s;
char grid[60][60];
bool mark[200];
int main (int argc, char const* argv[]){

	sc2(N,M);
	ll ans = 0;
	fr(i,0,N) scanf("%s", grid[i]);
	fr(i,0,N) fr(j,0,M){
		if(i + 1 < N && j +1 < M ){
			mst(mark, 0);
			mark[grid[i][j]] = 1; 
			mark[grid[i+1][j]] = 1; 
			mark[grid[i][j+1]] = 1; 
			mark[grid[i+1][j+1]] = 1; 									
			if(mark['f'] && mark['a'] && mark['c'] && mark['e'] ) ans++;
			
		}
	
	}
	
	
	
	
	printf("%I64d\n", ans);
	
	
	return 0;
}









