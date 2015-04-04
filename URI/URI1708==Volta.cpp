#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b)  if(!b) {break;}
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a,b) memset(a, b, sizeof (a))
#define fr(i,a,b) for(int i = (a); i < (b); i++)
#define fe(i,a,b) for(int i = (a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a,i) for(int i =0; i < (a.size()); i++ ) { printf("%d ", a[i]); if(i != a.size() -1) printf(" "); }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;






int main (int argc, char const* argv[]) {
	int a, b, c, d, k;
	ll x, y;
	while(sc2(a,b)==2){
		int cnt = 1;
		while(1){
			x = cnt*a;
			y = cnt*b;
			if( abs(x-y) >= a || abs(x-y) >= b) {
				break;
			}
			cnt++;
				
			
		}
		printf("%d\n", (cnt+1) );
		
		
		
		
		
	
	
	}
	
	
	return 0;
}
