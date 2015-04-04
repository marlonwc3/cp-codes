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

bool mark[2*(1000005)];
vll primes;
void go(){
	mark[0] = mark[1] = 1;
	fe(i,2, 2*(1000001) ){
		if(mark[i]) continue;
		primes.pb(i);
		for( ll j = i*i; j <= 2*(1000001) && j > 0; j+=i ){
			mark[j] = 1;	
		}
	}
	
}

ll freq[2*(1000005)];

ll numDiv(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while( N != 1  && (PF*PF <=N) ){
		ll power = 0;
		while ( N % PF  == 0 ) {  N/=PF; power++; }
		ans *= (power +1 );
		PF = primes[++PF_idx];
	}
	
	if ( N != 1){
	
		ans *= 2;
	}
	return ans;
}


ll get(ll a, ll b){
	return freq[b] - freq[a-1];
}


int main (int argc, char const* argv[]) {
 	go();
	ll k;
	ll maior = 0;
	fe(i,2, 2*(1000001) ){
		k = numDiv(i);
		freq[i] += freq[i-1];
		if( !mark[k] ){
			freq[i]++;
		}
	}
	ll n;
	while(scanf("%lld", &n) == 1 ) {
		n = get(2, n);
		printf("%lld\n", n);
	
	}



	
	return 0;
}














