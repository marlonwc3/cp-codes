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

int mdc(int a, int b) {return (!b) ? a : mdc(b, a%b);}
int mmc(int a,int b) { return (a*b)/mdc(a,b); }

struct fract {
	int p, q;
	fract(){};
	fract(int _p, int _q) { p=_p, q=_q;	 }
	void pf(){
		printf("%d/%d\n", p,q);
	}	
	fract operator - (const fract &f) const {
		int m = mmc(f.q, q);
		fract r = fract( ( p*(m/q) ) - ( f.p *(m/f.q) ) , m );
		m = mdc( abs( r.p ) ,abs( r.q) );
		r.p/=m; r.q/=m;
		if(r.q < 0) {
			r.q*=-1;
			r.p*=-1;
		}
		return r;
	}
	fract operator + (const fract &f) const {
		return fract(p+f.p , q + f.q);
	}
	bool operator == (const fract &f) const{
		return (p==f.p)&&(q==f.q);
	}
	bool operator > (const fract &f) const{
		if(!q) return 0;
		if(!f.q) return 1;
		fract r = fract(p,q);
		 r = r-f;
		return ( r.p > 0  );
	}
};
string str;
fract f;
void go(fract f1, fract f2){
	fract f3 = f1+f2;
	if(f3 == f ) return;
	if(f > f3 ) {
		str+= "R";
		go (f3, f2);
	}
	else {
		str+="L";
		go(f1, f3);
	}
}


int main (int argc, char const* argv[]) {
	int p,q;
	fract f1 = fract(0,1);
	fract f2 = fract(1,0);
	while(1){
		sc2(p,q);
		if(p==1 && q==1) break;
		f = fract(p,q);
		str = "";
		go(f1,f2);
		printf("%s\n", str.c_str() );
	}
	
	return 0;
}
















