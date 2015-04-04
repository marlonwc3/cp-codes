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

int grid[515][515];
int n,m;
int main (int argc, char const* argv[]) {

	int q, l, u, r, a, b;
	while(1){
		int maior = 0, p, pant=inf;
		sc2(n,m); if(!n && !m) break;
		fr(i,0,n) fr(j,0,m) sc1(grid[i][j]);
		sc1(q);
		while(q--){
			sc2(l,u);
			maior = 0;
			pant = inf;
			fr(i,0,n){
				b = lower_bound(grid[i] , grid[i]+m, l) - grid[i];
				if( b >= m || b >= pant) continue;
				a = i;
				r= 0;
				pant = min(pant, b);				
				while( a < n && b < m && grid[a][b] >= l && grid[a][b] <= u) {
					r++;
					a++, b++;
				}
				maior = max(maior, r);

				
			}
			printf("%d\n", maior);
			
		}
		
		printf("-\n");
		
	
	}
	
	
	
	
	
	return 0;
}






















