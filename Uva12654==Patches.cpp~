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
//#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll , ll> pll;

ll v[1005];
int PASSO;
ll pd[1005];
int pd_ok[1005];

ll t1, t2;
int N,L;
int mod(int b){
	return b%N < 0 ?  (b%N )+N : b%N;
}
ll go(int p){
	if(p>=N) return 0;
	if(pd_ok[p] == PASSO) return pd[p];
	ll r = inf;
	ll k = v[p], d;
	int next;
	
	next = upper_bound(v, v+N, k+t1) - v;
	r = min(r, t1 + go(next) );
	
	next = upper_bound(v, v+N, k+t2) - v;
	r = min(r, t2 + go(next) );
		
	pd_ok[p]= PASSO;
	pd[p]=r;	
	return r;
}

int main (int argc, char const* argv[]){
	PASSO = 0;
	while (scanf("%d %d %lld %lld", &N, &L, &t1, &t2) == 4 ){
		fr(i,0,N){
			scanf("%lld", &v[i]);
		}
		sort(v, v+N);
		PASSO++;
		ll r = go(0);
		printf("%lld\n", r);
	}

	
	return 0;
}












