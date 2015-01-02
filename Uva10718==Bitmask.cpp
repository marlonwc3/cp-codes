#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-6
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

typedef unsigned int ui;
const ui um = 1;	
int main (int argc, char const* argv[]) {
	ui n, l, u, m;
	while( scanf("%u %u %u", &n, &l, &u) == 3 ) {
		int sig;
		fe(i,0,31){
			if(  u & (um << i)  )  sig = i;
		}
		m = 0;		
		for(int i = sig; i>=0 ; i--){
			if( ( m | (um << i) ) > u ) continue;
			if(  ( m| (um << i)  ) <= l  ) {
				m = ( m| (um << i)  );
			}
			else if( !(n&(um<<i))  ){ 
				m = ( m| (um << i)  );
			}
		}
		printf("%u\n", m);
	}	
	return 0;
}














