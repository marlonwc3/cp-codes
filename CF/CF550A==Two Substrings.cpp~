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

string str;
vi v1, v2;
int main (int argc, char *argv[]) {
	getline(cin, str);
	int l = str.length();
	for(int i = 0; i < l; i++){
		if(i + 1 < l ){
			if(str[i] == 'A' && str[i+1] == 'B' ) {
				v1.pb(i);
			}
		}
	//	ABC
	//	0 1 2 
	}
	for(int i = 0; i < l; i++){
		if(i + 1 < l ){
			if(str[i] == 'B' && str[i+1] == 'A' ) {
				v2.pb(i);
			}
		}
	}	
	bool ok = 0;
	if(!v1.empty() && !v2.empty() ) {
		int d = abs ( v2.back() - v1[0] );
		if( d >= 2) ok = 1;
		
		 d = abs(v2[0] - v1.back() );
			if( d >= 2) ok = 1;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	
	
	
	
	
	
	
	
	
	return 0;
}





