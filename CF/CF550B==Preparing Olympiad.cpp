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

ll L, R , X, N;

ll arr[30];
ll r = 0;
vi v;

int pd[1<<16];


void go(int p, ll lo, ll hi , ll k, ll cnt, int mask){
	if( cnt >= 2 && abs(hi - lo ) >= X && k >= L && k <= R ) {
		if(pd[mask] == 0 ){
		r++;
		}
		pd[mask] = 1;
		//pv(v,x);
	}
	if ( p >= N) return;
	
	v.pb(p);
	go(p+1, min(lo,arr[p]) , max(hi, arr[p]) , k + arr[p], cnt+1, mask | (1 << p) );
	
	v.pop_back();
	go(p+1, lo, hi, k, cnt, mask);
	
	

}



int main (int argc, char const* argv[]){
	scanf("%lld %lld %lld %lld", &N, &L, &R,&X);
	fr(i,0,N){ scanf("%lld", &arr[i]); }
	sort(arr, arr+N);
	//fr(i,0,N) printf("%lld ", arr[i]);
	//_  _
	go(0,inf, -inf, 0, 0, 0);
	printf("%lld\n", r);
	
	return 0;
}
