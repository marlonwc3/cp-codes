
#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


int main (int argc, char const* argv[]) {
	
	int n;
	lld a,b, c,d ;
	double res;

	bool minus;
	sc1(n);
	while(n--){	
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		c-=a;
		if(!c){ printf("0\n"); continue;}
		d-=b;
		res = (d+0.0)/(c+0.0);
		if(res<0){
			res*=-1;
			minus=1;
		} else minus=0;
		
		d = trunc(res);
		c = lld(res*100L)%100;
		if(minus) printf("-");
		printf("%lld,", d);
		if( c < 10 ) printf("0");
		printf("%lld\n",c);
	}
	return 0;
}






