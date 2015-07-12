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

char grid[105][105];
int main (int argc, char *argv[]) {
	int N, M;
	sc2(N,M);
	fr(i,0,N) scanf("%s", grid[i] );

	fr(i,0,N){
		for(int j =  (i%2 == 0) ? 0 : 1 ; j <  M; j += 2 ) {
			if(grid[i][j] == '.') grid[i][j] = 'B';
		}
	
	}
	fr(i,0,N){
		for(int j =  (i%2 == 0) ? 1 : 0 ; j <  M; j += 2 ) {
			if(grid[i][j] == '.') grid[i][j] = 'W';
		}
	
	}	
	fr(i,0,N) printf("%s\n", grid[i]) ;
	
	
	
	
	return 0;
}


