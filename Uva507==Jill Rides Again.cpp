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

struct lol{
	int a, b, w;
	lol(){}
	lol(int _a, int _b, int _w){ a=_a, b=_b, w=_w;}
	bool operator > (const lol &l) const{ 
		if(w == l.w){
			if( (b-a) == (l.b - l.a) ){
				return a < l.a;
			}
			return (b-a)  > (l.b - l.a);
		}
		return w > l.w;
	}
};

int  n;


int main (int argc, char const* argv[]) {
	int caso, a, b, sum, k;
	lol l, r;
	sc1(caso);
	fe(t,1,caso){
		sc1(n);
		sum = 0;
		a = 1;
		r = lol(inf, 0, -1);
		//_
		//printf("n: %d\n", n);
		fr(i,1,n){
			sc1(k);
			//printf("k: %d\n", k);
			if( sum + k < 0 ){
				sum = 0; 
				a = i+1;
				continue;
			}
			sum+=k;
			l = lol(a, i+1, sum);
			if ( l > r ) r = l;
		}
		if( r.w > 0 ) {
			printf("The nicest part of route %d is between stops %d and %d\n", t, r.a, r.b);
		}
		else printf("Route %d has no nice parts\n", t);
		
	
	}
		
	
	
	
	return 0;
}



















