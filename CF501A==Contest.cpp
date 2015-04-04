#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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

int cmp(double a, double b) {
	if(fabs(a-b) <= EPS ) return 0;
	return (a>b) ? 1 : -1;

}

int main(int argc, char const *argv[]) {
	
	double a, b, c, d;
	scanf("%lf %lf %lf %lf\n", &a, &b, &c, &d);
	//printf("%d %d %d %d\n", a, b , c, d);
	double e = (3*a)/10.0;

	int w = a/250;
	a = a - ( w*c);
	//printf("1 a: %lf | e: %lf\n", a, e);
	if( cmp(e, a) == 1 ) a = e;

	//printf("2 a: %lf\n", a);
	e = (3*b)/10.0;

	b = b - ((b/250)*d);
	//printf("1 b: %lf\n", b);
	if(cmp(e,b) == 1) b = e;
	//printf("2 b: %lf\n", b);
	a = cmp(b,a);
	if(a==1) {
		printf("Vasya\n");
	}
	else if(a == -1){
		printf("Misha\n");
	}
	else printf("Tie\n");



	return 0;
}
