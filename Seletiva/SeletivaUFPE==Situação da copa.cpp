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

ll q, d, n;
vll v;

ll teto(ll a, ll b){
	return (a+b-1)/b;
}

bool f(ll m){
	ll am = m;
	ll k;
	fr(i,0,n){
		k = v[i];
		//printf("k antes : %d | m: %d \n", k, m);			
		k -= am*q;
		if( k <= 0 ) continue;
		if(!d) return 0;
		ll cnt = teto(k, d);
		if( cnt > m ) return 0;
		m -= cnt;
	}
	return 1;
}

ll bs(ll lo, ll hi){
	if( lo + 1 >= hi ) return inf;
	ll mid = (hi+lo)/2;
	if( f(mid) ) {
		return min(mid,  bs(lo, mid) ) ;
	}	
	return bs(mid, hi);
}





bool mycmp(ll a, ll b ){ return a > b; }
int main (int argc, char const* argv[]) {

	
	int caso;
	ll p;
	sc1(caso);
	fe(t,1,caso){
		scanf("%lld %lld %lld", &n, &p, &q);
		v.clear();
		d = p-q;
		fr(i,0,n){
			scanf("%lld", &p);
			v.pb(p);
		}

		sort(v.begin(), v.end(), mycmp);
		ll hi = teto(v[0], q);
		//pv(v,x);
		//printf("d: %d\n", d);		
		//printf("ok: %d\n", f(3));
		
		p = bs(0, hi+50);
		
		printf("Caso #%d: %lld\n", t, p);
		
		//break;
	}
	
	
	return 0;
}






