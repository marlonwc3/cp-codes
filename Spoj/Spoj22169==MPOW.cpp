#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
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
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;

int m;
const int MOD = 1000000007;
typedef vector<vector<ll> >  vvl;
vvl mult(vvl a, vvl b){
	ll sum;
	vvl c;
	fr(i,0,m){
		c.pb(vector<ll>() );
		fr(j,0,m){
			sum = 0;	
			fr(k,0,m){
				sum  =  (sum + ( a[i][k]*b[k][j] )%MOD)%MOD; 			
			}
			c[i].pb( sum ) ;
		}
	}
	return c;
}

vvl fexp(vvl a, int n){
	vvl c;
	if(!n) {
		fr(i,0,m){
			c.pb(vector<ll>());
			fr(j,0,m){
				c[i].pb( i==j );
			}
		}		
		return c;
	}
	if(n==1) return a;
	c = fexp(a, n/2);
	c = mult(c,c);
	if(n%2 == 1 ) c = mult(a , c);
	return c;
}

int main (int argc, char const* argv[]) {
	int t, k, n;
	sc1(t);
	vvl c;
	while(t--){
		sc2(m,n);
		c.clear();
		fr(i,0,m){
			c.pb(vector<ll>());
			fr(j,0,m){
				sc1(k);
				c[i].pb(k);
			}
		}
		c = fexp(c, n);
		fr(i,0,m){
			fr(j,0,m){
				printf("%lld", c[i][j] );
				if(j!=m-1) printf(" ");
			}
			_
		}	
	}

	return 0;
}




