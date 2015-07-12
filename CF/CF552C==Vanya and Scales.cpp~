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





int main (int argc, char const* argv[])
{
	int W, M;
	sc2(W,M);
	if( M < W ) {
		if(M==1 || M == W-1) printf("YES\n");
		else printf("NO\n");
	
	}
	else{
		bool ok = 1;
		while(1){
			if(M==1 || M == 0 ) break;
			if(M % W == 0) {
				M/=W;
			}
			else if( (M-1) % W == 0){
				M = (M-1)/W;
			}
			else if( (M+1)%W == 0 ) {
				M = (M+1)/W;
			}
			else{
				ok = 0; break;
			}
		
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
		
	
	
	
	}
	
	
	return 0;
}






