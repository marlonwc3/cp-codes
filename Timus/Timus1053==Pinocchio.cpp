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
typedef  unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);

vll v;
int main (int argc, char const* argv[]){
	int n; ll k, menor = linf;
	bool ok = 0;
	sc1(n);
	fr(i,0,n){
		scanf("%llu", &k);
		if(k > 0 ) {
			ok = 1;
			menor = min(menor, k);
			v.pb(k);
		}
	}
	vll v2;
	//pv(v,x);
	if(!ok) menor = -1;
	ll novo = -1;
	//printf("menor: %lld\n", menor);
	while(menor != -1 && v.size() > 1){
		//pv(v,x);
		
		v2.clear();
		novo = linf;
		ok = 0;
		//printf("menor: %lld\n", menor);
		fr(i,0,v.size()){
			k = v[i] % menor;
		//	printf("k: %lld\n", k);
			if(k){
				//printf("oie\n");
				
				ok = 1;
				novo = min(novo, k);
				v2.pb(k);
			}
		}
		//pv(v2,x);
		v2.pb(menor);
		v = v2;
		
		if(ok) menor = novo;
		else menor = -1;
	}
	//printf("final\n");
	//pv(v,x);
	//printf("v[0]: %lld\n", v[0]);
	
	if(v.size() <= 0 ) {
		printf("IMPOSSIBLE\n");
	}
	else{
		printf("%llu\n", v[0]);
	}
		
		
		


	return 0;
}
