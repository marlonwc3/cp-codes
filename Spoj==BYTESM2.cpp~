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

int n,m;
ll grid[120][120];

ll pd[120][120];

ll bt(int r, int c){
	if( r < 0 || r >= n || c <0 ||  c >= m ) return 0;
	if(pd[r][c] != -1 ) return pd[r][c];
	ll res = grid[r][c];
	ll v = -linf;
	v = max(v, bt(r+1, c-1));
	v = max(v, bt(r+1, c));
	v = max(v, bt(r+1, c+1));		
	return pd[r][c] = res + v;

}


int main (int argc, char const* argv[]) {
	int t;
	sc1(t);
/*

OI DUHAN E LUCAS 
NAUM ESTOU FILANDO SAFADOS

*/
	while(t--){
		sc2(n,m);
		mst(pd,-1);
		fr(i,0,n){
			fr(j,0,m){
				scanf("%lld", &grid[i][j]);
			}
		}	
		ll res = -linf;
		fr(i,0,m){
			res = max(res, bt(0, i) );
		}
		printf("%lld\n", res);
	
	
	}
	
	
	
	return 0;
}

