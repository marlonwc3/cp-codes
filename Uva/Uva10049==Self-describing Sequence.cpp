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
typedef pair<char, int> ci;


vector<pair<ll, ll> > v;

ll bs(ll lo,ll hi, ll k){
	if(lo+1 >= hi) return inf;
	ll mid = (lo+hi)/2;
	if( k >=  v[mid].st && k <= v[mid].nd) return mid;
	if( k < v[mid].st ) return min( mid, bs(lo , mid, k) );
	return bs(mid, hi, k);
}

vll seq;

const ll LIMIT = 2*ll(1e9) + 5;

int main (int argc, char const* argv[]){
	v.pb(mp(1,1));
	v.pb(mp(2,3));
	ll p;
	ll NEXT = 4;
	ll it = 3;
	ll k;
	
	while( NEXT <= LIMIT  ){

		p = bs(-1, v.size(), it);
		p++;
		//printf("NEXT: %d | p: %d\n", NEXT, p);	
		v.pb(mp(NEXT, NEXT+p -1));
		NEXT+=p;
		it++;
	}
	if(0) fr(i,0,5){
		printf("i:%d | (%lld -> %lld)\n", i, v[i].st, v[i].nd);
	}
	
	while( 1 ){
		scanf("%lld", &k); iz(k);
		p = bs(-1, v.size(), k);
		p++;
		//printf("k: %lld | p --> %d\n", k, p+1 );
		printf("%lld\n", p);
	} 	
	/*
	1 2 2 3 3 4 4 4  
	1 2 3 4 5 6 7 8
	
	1: 1 1
	2: 2 3
	3:
	
	*/ 
	
	
	return 0;
}














