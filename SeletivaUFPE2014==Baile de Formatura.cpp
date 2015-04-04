#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=(a); i <(b); i++)
#define st first
#define nd second 
#define fe(i,a,b) for(int i=(a); i <=(b); i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool mark[100050];
vi primes;

void sieve(){
	mark[0]=mark[1] = 1;
	fe(i,0,100000){
		if(mark[i]) continue;
		primes.pb(i);
		for(ll j = ll(i)*ll(i); j>=0 && j <= 100000; j+=i){
			mark[j]=1;
		}
	
	}
}

vii factors;

void go(ll n){
	factors.clear();
	ll pf = primes[0]; 
	int id = 0;
	int cnt;
	while( n != 1 && pf*pf <= n ){
		cnt =0 ;
		while( n%pf == 0){ n/=pf; cnt++; }
		if(cnt) factors.pb(mp(pf, cnt));
		id++; pf = primes[id];
	}
	if(n!=1){
		factors.pb(mp(n,1));
	}

}



ll fexp(ll a, ll b){
	if(!b) return 1;
	if(b==1) return a;
	ll r = fexp(a, b/2);
	r*=r;
	if(b%2==1) r*=a;
	return r;
}


int main (int argc, char const* argv[]) {
	sieve();
	//fr(i,0,5) printf("%d ", primes[i] );
	//_	
	
	
	int caso;
	sc1(caso);
	ll n;
	fe(t,1,caso){
		scanf("%lld", &n);
		go(n);
		ll r = 1;
		fr(i,0,factors.size()){
			r*= fexp(factors[i].st, factors[i].nd + (factors[i].nd%2 == 1)  );
		}
		printf("Caso #%d: %lld\n", t, r);

		
	}
	
	
	
	
	
	
	return 0;
}

