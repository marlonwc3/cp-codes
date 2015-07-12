#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%I64d", &a)
#define sc2(a,b) scanf("%I64d %I64d", &a, &b)
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
typedef pair<ll,ll> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

// return a % b (positive value)
ll mod(ll a, ll b) {
  return ((a%b)+b)%b;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {  
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a/b;
    ll t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}
// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b.  Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  On failure, M = -1.
ii chinese_remainder_theorem(ll x, ll a, ll y, ll b) {
  ll s, t;
  ll d = extended_euclid(x, y, s, t);
  if (a%d != b%d) return make_pair(0, -1);
  return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}

const int MAX_N = 1000010;


ll H1, A1, X1, Y1, H2, A2, X2, Y2, M;
const ll MAGIC = 1e7;
int m1[MAX_N], m2[MAX_N];
int main (int argc, char const* argv[]){
	mst(m1, -1); 
	mst(m2, -1);
	sc1(M);
	sc2(H1, A1);
	sc2(X1, Y1);
	sc2(H2, A2);
	vi v1, v2;
	sc2(X2,Y2);
	ll p1 = 0, p2 = 0, p = 0, l1 , l2;
	while(1){
		//printf("H1: %d\n", H1);
		if(m1[H1] != -1) {
			p1 = m1[H1]; break;
		}
		m1[H1] = p++; 
		v1.pb(H1);
		H1 = (X1*H1 + Y1)%M;
	}
	//_
	p = 0;
	while(1){
		//printf("H2: %d\n", H2);
		if(m2[H2] != -1 ) {
			p2 = m2[H2]; break;
		}
		m2[H2] = p++; 
		v2.pb(H2);
		H2 = (X2*H2 + Y2)%M;
	}	
	//_
	l1 = v1.size(), l2 = v2.size();
	//printf("p1: %I64d | p2: %I64d  |  l1: %I64d | l2: %I64d \n", p1, p2, l1, l2);

	//pv(v1,x); _ pv(v2,x);
	bool ok =0;
	ll r = 0;  
	ll i =0, j = 0;

	while( ( (p2 > p1) ? (j < p2) : ( i < p1) ) ) {
		if(v1[i] == A1 && v2[j] == A2) {
			ok = 1; break;
		}	
		r++, i++, j++;
		if(i >= l1 ) i = p1; 
		if(j >= l2 ) j = p2;
	}
		
	//printf("i: %I64d | j: %I64d | ok: %I64d \n", i, j, ok);

	if(!ok){
		ll x1 =-1,x2=-1;
		ll cl1 = l1 - p1, cl2 = l2 - p2; 
		fr(x,p1,l1)  if(v1[x] == A1) { x1 = x; break;	}
		fr(x,p2,l2)  if(v2[x] == A2) { x2 = x; break;	}
		if(x1 == -1 || x2 == -1) goto label;
	//	printf("p1: %I64d | x1: %I64d | l1: %I64d | i: %I64d | cl1: %I64d | -> %I64d \n", p1, x1, l1, i, cl1, mod(x1-i, cl1));
	//	printf("p2: %I64d | x2: %I64d | l2: %I64d | j: %I64d | cl2: %I64d | -> %I64d \n", p2, x2, l2, j, cl2, mod(x2-j, cl2));		
		ii p = chinese_remainder_theorem(cl1, mod(x1-i, cl1),cl2, mod(x2-j, cl2)) ;
	//	printf("p: %I64d | %d\n", p.st, p.nd);
		if(p.nd != -1) {
			ok = 1; r = p.st;
			r += max(p1,p2);
		}
	}
	label:;
	if(!ok) printf("-1\n");
	else printf("%I64d\n", r);
	
	
}	


