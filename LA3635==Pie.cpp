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
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii; 
typedef set<int> si;
typedef pair<char, int> ci; 
typedef long double lb;

int n, f;
double vol[10006];
double mp;

bool can(double v){
	int cnt = 0;
	int k;
	fr(i,0,n){
		k = int(vol[i]/v);
		cnt += k;
	}
	return cnt>=(f+1);
}

double bs(){
	double hi=mp, lo=0, mid = (hi+lo)/2.0;
	while(fabs(hi-lo) > 1e-3){
		mid = (hi+lo)/2.0;
		if(can(mid)) {
			lo = mid;
		}
		else hi = mid;
	}
	return mid;
}


int main (int argc, char const* argv[]) {
	int t;
	double v;
	sc1(t);
	while(t--){
		mst(vol,0);
		mp =0 ;
		sc2(n,f);
		fr(i,0,n){
			scanf("%lf", &v);	
			vol[i] = PI*v*v; // pi*r²
			if(vol[i] > mp ) mp = vol[i];
		}
		v = bs();
		printf("%.4lf\n", v);
	
	}
	
	
	return 0;
}





























