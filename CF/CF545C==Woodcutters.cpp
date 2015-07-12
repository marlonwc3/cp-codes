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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

ll h[100010];
int x[100010];
vector<pair<int, ll> >  v;
int N;

int pd_ok[100010][4], pd[100010][4], PASSO;

int go(int p, ll k){
	if(p >= N ) return 0;
	//printf("p: %d | k: %I64d\n", p, k);

	bool left = x[p] - h[p] > k ;
	if(pd_ok[p][left] == PASSO ){
		return pd[p][left];
	}
	int r = 0, r2, pos;
	if(!left){
		pos = upper_bound(x, x+N, x[p] + h[p]) - x;
		if( pos == p+1) {
			r = 1 + go(p+1, x[p] + h[p]); 
		}
		

		r2 = go(p+1, x[p]);
		
		
		
		r = max(r, r2);
	}
	else{
		//printf("pra esquerda %d\n", p);
		r = 1 + go(p+1, x[p]);
	}
	//printf("p: %d | k: %I64d | r: %d | h[p]: %d | x[p]: %d | h+x: %d \n", p, k  , r, h[p] , x[p] , h[p]+x[p] );
	pd_ok[p][left] = PASSO;
	pd[p][left] = r;
	return r;
}



int main (int argc, char const* argv[]){
	PASSO = 1;
	int a;
	ll b;
	sc1(N);
	fr(i,0,N){
		scanf("%d %I64d", &a, &b);  //  MUDAR;
		v.pb(mp(a,b));
	
	}
	sort(v.begin(), v.end());
	fr(i,0,N){
		x[i] = v[i].st, h[i] =v[i].nd;
	}
	int r = go(0, -linf);
	printf("%d\n", r);
		
	return 0;
}
