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


vii v;
int NEXT = 1;
int pos[2005];
int r[2005];
int main (int argc, char const* argv[])
{
	int n , k; 
	sc1(n);
	fr(i,0,n){
		sc1(k);
		v.pb(mp(k,i));
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	pos[v[0].nd] = 1;
	
	fr(i,1, v.size() ){
	int	b = v[i].nd;
		if(v[i].st == v[i-1].st) {
			//printf(" %d", pos[v[i-1].nd]);
			pos[v[i].nd] = pos[v[i-1].nd];
		}
		else {
			pos[v[i].nd] = i+1;

		}
	}
	printf("%d", pos[0]);
	fr(i,1,v.size() ) printf(" %d", pos[i]);
	_
	
	
	return 0;
}

