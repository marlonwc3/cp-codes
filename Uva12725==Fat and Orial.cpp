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

int cmp(double a, double b =0.0){
	if(fabs(a-b) <= EPS ) return 0;
	return (a>b) ? 1 : -1;
}


int main (int argc, char const* argv[]){
	double n, m;
	int a,b;
	int caso;
	sc1(caso);
	fe(t,1,caso){
		scanf("%lf %lf %d %d", &n, &m, &a, &b);
		double y = (a+b)*m - a*n;
		//printf("n %lf m %lf | a %d b %d\n", n, m, a, b);
		//printf("y %lf\n", y);
		y = y/b;
		//printf("y %lf\n", y);
		if( cmp(y, 0) == -1  || cmp(y, 10) == 1 ){
			printf("Case #%d: Impossible\n", t);
		}
		else printf("Case #%d: %.2lf\n", t, y);
		
	
	
	}
	
	
	
	return 0;
}



















