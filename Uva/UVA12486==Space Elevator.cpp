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
#define oi(x) cout <<"Oi [" << x << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef   unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int LEN;
char num[20];
ll PASSO=0, pd_ok[20][3][3];
ll pd[20][3][3];

ll go(int p, bool ta, bool tem){
	if(p >= LEN) return 1;
	if(pd_ok[p][ta][tem] == PASSO) return pd[p][ta][tem];
	ll r= 0;
	for(int i = 0; i<= ((ta) ? 9 : (num[p]-'0')); i++ ){
		if(i==4 || (tem && i==3) ) continue; 
		r += go(p+1, ta | (i < (num[p]-'0')), i==1 );
		assert(r > 0 );
	}
	pd_ok[p][ta][tem] = PASSO;
	pd[p][ta][tem] = r; 
	return r;
}


void to(ll N){
	LEN = 0;
	while(N){
		num[LEN++] = (N%10) + '0' ;
		N/=10;
	}
	reverse(num, num+LEN);
}
ll W;
ll bs ( ){ 
	ll lo = 0, hi = ULLONG_MAX, mid, fm, aux; 
	ll res = ULLONG_MAX;
	while(1){
		if( (lo+1) >= hi ) break;
		mid = lo + (hi-lo)/2; aux = mid;
		to(mid);
		PASSO++;
		fm = go(0,0,0) -1;
		assert(fm > 0 ); 
		if(fm > W ) hi = mid;
		else if( fm < W) lo = mid;
		else {
			res = min(res, mid);
			hi = mid;
		}	
	}
	return res;
}


int main (int argc, char const* argv[]){
	while(scanf("%llu", &W ) == 1){
		ll r = bs();
		printf("%llu\n", r);
	
	}
	
	
	
	return 0;
}













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
#define oi(x) cout <<"Oi [" << x << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef   unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int LEN;
char num[20];
ll PASSO=0, pd_ok[20][3][3];
ll pd[20][3][3];

ll go(int p, bool ta, bool tem){
	if(p >= LEN) return 1;
	if(pd_ok[p][ta][tem] == PASSO) return pd[p][ta][tem];
	ll r= 0;
	for(int i = 0; i<= ((ta) ? 9 : (num[p]-'0')); i++ ){
		if(i==4 || (tem && i==3) ) continue; 
		r += go(p+1, ta | (i < (num[p]-'0')), i==1 );
		assert(r > 0 );
	}
	pd_ok[p][ta][tem] = PASSO;
	pd[p][ta][tem] = r; 
	return r;
}


void to(ll N){
	LEN = 0;
	while(N){
		num[LEN++] = (N%10) + '0' ;
		N/=10;
	}
	reverse(num, num+LEN);
}
ll W;
ll bs ( ){ 
	ll lo = 0, hi = ULLONG_MAX, mid, fm, aux; 
	ll res = ULLONG_MAX;
	while(1){
		if( (lo+1) >= hi ) break;
		mid = lo + (hi-lo)/2; aux = mid;
		to(mid);
		PASSO++;
		fm = go(0,0,0) -1;
		assert(fm > 0 ); 
		if(fm > W ) hi = mid;
		else if( fm < W) lo = mid;
		else {
			res = min(res, mid);
			hi = mid;
		}	
	}
	return res;
}


int main (int argc, char const* argv[]){
	while(scanf("%llu", &W ) == 1){
		ll r = bs();
		printf("%llu\n", r);
	
	}
	
	
	
	return 0;
}














