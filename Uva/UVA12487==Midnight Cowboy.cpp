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
#define oi(x) cout <<"Oi [" << x << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef   long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const int MAX_N =  100;
vi e[MAX_N + 5];
int N, A, B, C;
bool mark[MAX_N+5];
ii res;
int lv = -1 ;
ii go(int a, int l = 0) {
	mark[a] = 1; 
	if(a == B) return mp(0,-1);
	if(a == C) return mp(-1, 0);
	int b;
	ii r = mp(-1,-1);
	ii p;
	fr(i,0,e[a].size()){
		b = e[a][i]; 
		if(mark[b]) continue;
		p = go(b, l+1);
		if(p.st >= 0 ) {
			r.st = p.st + 1;
		}
		if(p.nd >= 0 ) {
			r.nd = p.nd + 1;
		}
	}
	if(l > lv && r.st >= 0 && r.nd >= 0 ) {
		lv = l ;
		res = r;
	}
	return r;
}




int main (int argc, char const* argv[]){

	
	int a, b;
	
	while(sc4(N,A,B,C) == 4 ) {
		fe(i,0,N) e[i].clear();
		mst(mark,0);
		lv = -1;
		fr(i,0,N-1){
			sc2(a,b);
			e[a].pb(b);
			e[b].pb(a);
		}
		mst(mark, 0);
		ii p = go(A);

		if(p.nd < 0 ) printf("1.000000\n");
		else if( p.st < 0 ) printf("0.000000\n"); 
		else{
			int dif = abs(1 - min(p.st, p.nd) );
			p.st -= dif, p.nd -= dif;

			double r2 = 1.0 - ( res.st / (res.st + res.nd + 0.0)  )	;

			printf("%.6lf\n", r2);			

			
		
		}
		
		
	}
	
	
	
	return 0;
}

























