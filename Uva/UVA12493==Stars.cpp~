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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
#define clr(a, b) memset(a, b, sizeof(a)) // tati 

using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);


const int limit = 66340;
bool mark[limit+10];
vi primes;
void sieve(){
	mark[0] = mark[1] = 1;
	fe(i,2,limit){
		if(mark[i]) continue;
		primes.pb(i);
		for(ll j = ll(i)*ll(i); j>0 && j <= limit; j+= i ) mark[j] = 1;
	}
}

ll go(ll N){
	ll id = 0, PF = primes[0], ans= N;
	while( PF*PF <= N ){
		if(N%PF==0) ans -= ans/PF;
		while(N%PF == 0) N/=PF;
		PF = primes[++id];
		

	}
	if(N!=1) ans -= ans/N;
	
	return ans;
}



int main (int argc, char const* argv[]){
	sieve();
	ll N;
	
	while(scanf("%lld", &N) == 1){
	

		ll w = go(N);
		w/=2;
		printf("%lld\n", w);
	}
	
	
	return 0;
}
