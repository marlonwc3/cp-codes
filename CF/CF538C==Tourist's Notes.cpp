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
#define rp(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define re(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

#define se if
#define printa printf
#define muito 0x3f3f3f3f



deque<ii> v;
int main (int argc, char const* argv[]){
	int n,m, a, b, r=0, d, x;
	sc2(n,m);
	
	bool ok = 1;
	rp(i,0,m){
		sc2(a,b);
		v.pb(mp(a,b));	
	}
	
	int d1 = (v[0].st - 1), d2 = n - v.back().st; 
	v.push_front(mp(1, v[0].nd + d1 ));
	v.push_back(mp(n, v.back().nd + d2 ));	
	//pvp(v,x);
	
	rp(i,1,v.size()){
		d = v[i].st - v[i-1].st;
		x = abs(v[i].nd-v[i-1].nd);
	//	printa("d: %d | x: %d\n", d, x);
		se(x > d) {ok=0; break;}
		int sobra = d-x;
		int maior = max(v[i].nd, v[i-1].nd);
		r = max(r, maior  + (sobra/2));
		
		
	
	}
	
	
	

	se(ok) printa("%d\n", r);
	else printa("IMPOSSIBLE\n");

	
	
	return 0;
}

