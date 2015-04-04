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

const ll MOD = 1300031;

ll fexp(ll a, ll b){
	if(!b) return 1;
	if(b==1) return a;
	ll r = 1;
	for(ll k = a%MOD, j=1;  j <= b  ;  k = ((k%MOD)*k)%MOD, j<<=1){
		if( b & j ) r = ((r%MOD)*k)%MOD;
	}
	return r%MOD;
}

ll fact[2000004];
	
	
	
ll cmb(ll n, ll p){
	ll a = fact[n];
	ll b = (fact[n-p]*fact[p])%MOD;
	b = fexp(b, MOD-2);
	return (a * b)%MOD;
}


int main (int argc, char const* argv[]) {	
	fact[0]=fact[1] = 1;
	fe(i,2,1999999) fact[i] = ((i%MOD)*fact[i-1])%MOD;

	int t;
	sc1(t);
	ll n, c;
	while(t--){
		scanf("%lld %lld", &n, &c);
		n = cmb(n-1+c , c);
		printf("%lld\n", n);
		
	
	}	
	
		
	return 0;
}












