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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


vii v1;
vii v2;
int N;


int main (int argc, char *argv[]){
	sc1(N);
	int a,b;
	fr(i,0,N){
		sc2(a,b);
		if(a < 0 ) v1.pb(mp(a,b));
		else v2.pb(mp(a,b));
	}
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll ans = 0, r = 0;
	// left first
	bool dir; int p1, p2;
	
	dir = 1; // left
	p1 = 0 ;
	p2 = 0;
	r = 0;
	//pv(v1,x);
	while(1){
		if( dir && p1 >= v1.size() ) break;
		else if( !dir && p2 >= v2.size() ) break;
		if(dir) {
			r += v1[p1++].nd; 

			
		}
		else {
			r += v2[p2++].nd;
		}
			dir = !dir;	
	}
	
	ans = max(ans, r);
	
	r = 0;
	dir = 0; // left
	p1 = 0 ;
	p2 = 0;
	
	while(1){
		if( dir && p1 >= v1.size() ) break;
		else if( !dir && p2 >= v2.size() ) break;
		if(dir) {
			r += v1[p1++].nd; 

			
		}
		else {
			r += v2[p2++].nd;
		}
			dir = !dir;	
	}	
	ans = max(ans, r);
	printf("%I64d\n", ans);	
	
	return 0;
}

