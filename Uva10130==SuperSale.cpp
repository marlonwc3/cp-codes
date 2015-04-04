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


int val[1010], peso[1010];
ll pd[1010][100];
int n;
ll bt(int p, int q){
	if( q < 0 ) return -linf;
	if(p >= n ) return 0;
	if(pd[p][q] != -1 ) return pd[p][q];
	ll r = -linf;
	r = max(r, bt(p+1, q) );	
	r = max(r, val[p] + bt(p+1, q - peso[p])  );
	return pd[p][q] = r;
}


int main (int argc, char const* argv[]) {
	int t;
	int g, k;	
	sc1(t);
	while(t--){
		sc1(n);
		mst(pd, -1);		
		fr(i,0,n){
			sc2(val[i], peso[i] );
		}

		sc1(g);
		ll res = 0, r;
		fr(i,0,g){
			sc1(k);			
			r = bt(0 , k);
			if( r < 0 ) r =0;
//				printf("r: %lld\n", r);
			res += r;
		}
		printf("%lld\n", res);
	
	}
	
	
	
	return 0;
}














