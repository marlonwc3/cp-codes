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
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const int MAX_N = 1000;
bool mark[MAX_N+ 10];
vi primes;
void go(){
	mark[0] = mark[1] = 1;
	for(int i = 2; i <= MAX_N; i++){
		if(mark[i]) continue;
		primes.pb(i);
		for(ll j= ll(i)*ll(i); j <= MAX_N; j+=i){
			mark[j] = 1;
		}
	}
}

ll fat[60];
bool FUDEU = 0;

ll cmb(ll n, ll k){
	ll a = n-k;
	if( a > k) swap(a,k);
	ll r = 1;
	while(n > k) {
		
		r *=n; n--;
		//if( r < 0 ){ FUDEU = 1; return 1; }
	}
	ll x = fat[a];
	
	//if ( x <= 0) { FUDEU = 1;return 1; }
		
	return r/x;
	
}

int get(int n){
	int id = 0; ll pf = primes[0];
	int res = 0 ;
	while( pf * pf <= n ){
		int cnt = 0;
		while( n % pf == 0 ){
			cnt++;
			n/=pf;
		}
		if(cnt > 0 ) res++;
		if(cnt >= 2 ) return 1;
		id++; pf = primes[id];
	}
	if(n != 1 ){
		res++;
	}
	return res;

}



int main (int argc, char const* argv[]){
	go();

	fat[0] = fat[1] = 1;
	fe(i,2,50) {fat[i] = i*fat[i-1];
//		if(fat[i] < fat[i-1]) printf("fudeu em %d\n", i); 
//		if(fat[i] < fat[i-1]) pritnf
	}
	
	ll K, S;
	while(	scanf("%llu %llu", &K, &S) ==2 ) {	
	FUDEU = 0;
	ll r = 0;
	for(int i=2; i<=S; i++){

		if(S/i < K) break;
		if(mark[i]) {  // true == primo
			int qtd = get(i);
			r -= (qtd -1)*cmb(S/i, K);
			
		}
		else{		
			r += cmb(S/i, K);
		}
		//printf("fudeu aqui i: %d \n", i);
		
		
		
		//if( r < 0 || r >= 10000) { FUDEU = 1; break; }
//		if(FUDEU) break;
	
	
	}
		if( r < 0 || r >= 10000) { FUDEU = 1; }	
	if(FUDEU) printf("10000\n");
	else printf("%llu\n", r);
	}
	
	
	return 0;
}



