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
#define EPS 1e-6
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


vector< pair<double,double> > vd;
double vr, vk;
double t;
double rres, kres;
double tres;
int n;
int cmp(double a, double b){
	if(fabs(a-b) < EPS ) return 0;
	return a>b ? 1 : -1;
}
double f(double r){
	double m = inf;
	fr(i,0,n){
		m = min(m, (r/vd[i].st)+ ((t-r)/vd[i].nd ));
	}
	double mw = (r/vr) + ((t-r)/vk);
	return (m - mw)*3600;
}
bool ts(){
	double lo = 0, hi = t, m1, m2, fm1, fm2; // mid ==r
	
	while( fabs(hi-lo) > EPS ) {
		m1 = lo + ((hi-lo)/3);
		m2 = hi - ((hi-lo)/3);
		fm1 = f(m1),  fm2 = f(m2);
		if( fm2 > fm1 ){
			lo = m1;
		}
		else {
			hi = m2;
		}
	}
	rres = (hi+lo)/2;
	fm1 = f(rres);
	double lol=0;
	lol = fm1;
	if( cmp(0, fm1) == 1 ) return 0;
	tres = (fm1);
	kres = t-rres;
	return 1;
}


int main (int argc, char const* argv[]) {

	double a,b;
	while( scanf("%lf", &t) == 1 ){
		vd.clear();
		sc1(n);
		n--;
		fr(i,0,n){
			scanf("%lf %lf", &a, &b);
			vd.pb(mp(a,b));
		}
		scanf("%lf %lf", &vr, &vk);
		
		
		if( ts()){
			printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", tres, rres, kres);
		}
		else printf("The cheater cannot win.\n");
		
	}
	
	
	
	return 0;
}







