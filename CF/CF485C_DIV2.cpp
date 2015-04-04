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

int contBits(ll n){
	ll cont = 0;
	for(ll i=0; i < 64; i++	){
		cont+= ( n & (  ll(1) <<i)   ) && ll(1) ;    
	}
	return cont;

}

ll l, r;

ll foo(){
	ll pos = 0, res =l;
	int contL = contBits(l);
	while( 1 ) {
		if ( res >= l ) break;
		res |=  ll(1) << pos;
		if(res < 0 ) {
			return res-1;		}
		pos++;
	}
	if(  res > r ) {
		int b = contBits(r);
		if ( contL >= b) return l;
		return r;
	}
	ll aux;
	while( 1 ){ 
		aux = res | ( ll(1) << pos);
		if( aux < 0)  {
			aux--; 
			if( r != aux  ) return res;
			return aux;
		} 
		else if (  aux > r )  break;
		res = aux;		
		pos++;
	}
	if( contBits(res) <= contL   ) return l;
	return res;
}


int main (int argc, char const* argv[]) {

	int n;
	sc1(n);
	while(n--) {
		scanf("%I64d %I64d", &l, &r);	
		l = foo();
		printf("%I64d\n", l);
	}
	

	
	return 0;
}


























