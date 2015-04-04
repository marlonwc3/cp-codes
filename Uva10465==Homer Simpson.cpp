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
typedef pair<ll , ll> pll;

pair<ll, ll> mymax(pair<ll, ll> a, pair<ll, ll> b, bool pode ) {
	if(!pode){
		if(a.st == b.st ) return (a.nd < b.nd )? a :b;
		return a.st > b.st ? a : b;
	}
	else{
		if(a.nd == b.nd ) return a.st > b.st ? a : b;
		return (a.nd < b.nd )? a :b;
	}
}
ll n, m, k;	
pll go(bool pode){
	int a = 0, b;
	ll sobrou;
	pll res = mp(-inf, inf);
	while( a*n <= k ){
		b = (k - a*n)/m;
		sobrou = k - (a*n + b*m); 
		if(!pode){
			if(sobrou) goto label;
			//printf("a: %d | b: %d\n", a, b);
			res = mymax(res, mp(a+b, inf) , pode );
		}
		else{
			res = mymax(res, mp(a+b, sobrou) , pode);
		
		}
		
		label:;
		a++;
	}
	return res;


}



int main (int argc, char const* argv[]) {
	pair<ll , ll> res;
	

	while(scanf("%lld %lld %lld", &n, &m, &k) == 3 ){
		res = go(0);
		if(res.st <= -inf ) {
			res = go(1);
			printf("%lld %lld\n", res.st, res.nd);	
		}
		else {
			printf("%lld\n", res.st);
		}
	}
	
	return 0;
}













