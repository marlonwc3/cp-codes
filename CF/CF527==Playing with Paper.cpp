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

ll f(ll a, ll b) {
	if(a <= 0 || b <= 0 ) return 0;
	//printf("a: %I64d | b: %I64d\n", a, b);
	if(a==b){
	//	printf("iguais\n");
	 	return 1;
	 }
	ll c = min(a,b), d = max(a,b);
	ll r = d/c;
	//printf("res a: %I64d | b: %I64d --> %I64d\n", a, b, r);
	r += f(c, d%(c));
	return r;
	
}


int main (int argc, char const* argv[]) {
	if(0) fe(i,1,10){
		fe(j,i,10){
		//	printf("f(%d, %d): %I64d\n", i, j, f(i,j) );
		}
	}
	ll a,b;
	scanf("%I64d %I64d", &a, &b);
	printf("%I64d\n", f(a,b) );
	return 0;
}



