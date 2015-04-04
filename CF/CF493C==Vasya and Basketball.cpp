#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
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



int na, nb;
vi va, vb;
ii f(int v){
	int s1, s2, p;

	
	p = upper_bound(va.begin(), va.end(), v ) - va.begin() ;

	if(p >= na ){
		s1 = 2*na;
	}
	else if(p==0) s1 = 3*na;
	else {
		p--;
//		if(va[p]==v){
			s1 = (p+1)*2 + (na-p - 1)*3;
	//	}
	//	else s1 = p*2 + (na-p)*3;
	}	
//	printf("pa %d \n",p);	
	p = upper_bound(vb.begin(), vb.end(), v) - vb.begin();
	
	if(p >= nb ){
		s2 = 2*nb;
	}
	else if(p==0) s2 = 3*nb;
	else {
		p--;
		if(vb[p]==v){
			s2 = (p+1)*2 + (nb-p - 1)*3;
		}
		else s2 = p*2 + (nb-p)*3;
	}	
	//printf("pb %d \n", p);
	
	return mp(s1,s2);

}

int main (int argc, char const* argv[]) {

	int k;
	sc1(na);
	fr(i,0,na) {
		sc1(k);
		va.pb(k);	
	}
	
	sc1(nb);
	fr(i,0,nb){
		sc1(k);
		vb.pb(k);
	}
	int	 r=-inf, v,ra, rb; ii par;
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	//pv(va, x);
	//pv(vb, x);
	
	//printf(" @  Em A!\n");
	fr(i,-4, na){
		if(  i == -4 ) {
			
			v = 0;
		}
		else if (i==-3) {
			v = 2*(int(1e9) );
		}
		else if(i==-2){
			v = max( 0, va[0]-1 ) ;
		}
		else if(i==-1){
			v = max( 2*(int(1e9)), va[na-1]+1 );
		}
		else v = va[i];
		par = f(v);
		//printf("i %d | v:%d | ra %d rb %d\n", i, v, par.st ,par.nd);
		if( par.st - par.nd  > r ||  ( (par.st - par.nd  == r  )&& par.st > ra )) {
			//printf("melhor v:%d\n", v);
			ra = par.st, rb = par.nd;
			r = ra-rb;
		}
	
	}
	//printf(" @  em B!\n");
	fr(i,0,nb){
		v = vb[i];
		par = f(v);
		//printf("i %d | v:%d | ra %d rb %d\n", i, v, par.st ,par.nd);
		if( par.st - par.nd  > r ||  ( (par.st - par.nd  == r  )&& par.st > ra )) {
			//printf("melhor v:%d\n", v);
			ra = par.st, rb = par.nd;
			r = ra-rb;
		}
	}
	
	
	
	printf("%d:%d\n", ra,rb 	);

	
	
	
	return 0;
}
