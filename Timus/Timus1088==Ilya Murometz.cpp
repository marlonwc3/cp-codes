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
typedef unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

string s1, s2;

void go(int l, int r, int x, int c, int p, string &s){
	if(c >= p ) return;
	if(l >= r ) return;
	int mid = (l+r)/2;
	if( x >= l && x <= mid) { 
	s.pb('L'); 
	 go(l, mid, x, c+1, p, s); }
	else {
		s.pb('R');
		go(mid+1, r, x, c+1, p, s);
	}
	
}	


int main (int argc, char const* argv[])
{
	int D, E, F, Dp, Ep, H;
	scanf("%d %d %d %d %d %d", &D, &E, &F, &Dp, &Ep, &H);
	go(1, 1<<F, Ep, 0, F-E, s1);
	go(1, 1<<F, Dp, 0, F-D, s2);	
//	printf("s1: %s\ns2: %s\n", s1.c_str(), s2.c_str() ) ;
	int k = 0, l1 = s1.length(), l2  = s2.length() ;
	int id = 0;

	while( id < l1 && id < l2 && s1[id] == s2[id] ){
		id++;

	}
	k = l1 - id + l2 - id;
//	printf("k: %d\n", k);
	if(k <= H ) printf("YES\n");
	else printf("NO\n");
	
	
	
	
	
	return 0;
}
