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
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


ll A, B, N;
ll l, t, m;

ll L;
bool f(ll r) {
	ll q = (r -l ) + 1;
	ll mreal = min(m, q);
	//if(q == 0 ) printf("q 0\n");
	ll last = L +(q-1)*B;
	if(t < last ) return 0;
	ll sum = ((L + last)*q)/2;
	//if(q) sum = ((L + last)*q)/2;
	//printf("F --> A1: %I64d | AN: %I64d | q: %I64d | l:%I64d |  r: %I64d | sum: %I64d | mreal: %I64d | res: %I64d \n", L, last, q, l, r, sum, mreal, ((sum+mreal-1)/mreal)); 
	return ((sum+mreal-1)/mreal) <= t;
}

ll bs(ll a, ll b ){
	if( a + 1 >= b ) return -1;
	//printf("a: %I64d | b: %I64d | mid: %I64d \n" , a, b, (a+b)/2 );
	ll mid = (a+b)/2;
	if(f(mid))return max(mid, bs(mid, b));
	return bs(a, mid);
	

}



int main (int argc, char const* argv[]){
	scanf("%I64d %I64d %I64d", &A, &B, &N) ;

//ll L;	
	//printf("A: %I64d | B: %I64d\n", A, B);
	ll r;
	//printf("seg \n");
	//for(int i = A; i < 30; i+=B) printf("%d ", i);
	//_
	fr(i,0,N){
		scanf("%I64d %I64d %I64d", &l, &t, &m);
		L = A + (l-1)*B;
		//printf("L: %I64d\n", L);
		//printf("-> %d\n", f(2) );
		//_
		r = bs(l-1, ll(1) << 31 );	
		printf("%I64d\n", r);
		
	
	}
	
	return 0;
}


