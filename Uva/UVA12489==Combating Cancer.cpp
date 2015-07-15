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

const int MAX_N = 10000;
int g1[MAX_N + 5];
int g2[MAX_N + 5];

int NEXT = 0;
ii e1[2*MAX_N + 5];
ii e2[2*MAX_N + 5];
int N;

bool mycmp1(ii a, ii b){
	if(g1[a.st] == g1[b.st] ) return g1[a.nd] < g1[b.nd];
	return g1[a.st] < g1[b.st]; 
}
bool mycmp2(ii a, ii b){
	if(g2[a.st] == g2[b.st] ) return g2[a.nd] < g2[b.nd];
	return g2[a.st] < g2[b.st]; 
}

int main (int argc, char const* argv[]){
	int a, b, c, d;
	while(sc1(N) == 1 ){
		mst(g1, 0);
		mst(g2, 0);
		NEXT = 0;
		fr(i,0,N-1){
			sc2(a,b);
			g1[a]++; g1[b]++;
			e1[NEXT++] = mp(a,b);
			e1[NEXT++] = mp(b,a);
		}
		NEXT = 0;		
		fr(i,0,N-1){
			sc2(a,b);
			g2[a]++; g2[b]++;
			e2[NEXT++] = mp(a,b);
			e2[NEXT++] = mp(b,a);
		}		
		sort(e1, e1+NEXT,mycmp1);
		sort(e2, e2+NEXT,mycmp2);
		bool ok = 1;
		fr(i,0,NEXT){
			a = g1[e1[i].st], b = g1[e1[i].nd];
			c = g2[e2[i].st], d = g2[e2[i].nd];
			if(a!= c || b != d ) {ok=0; break; }
		}	
		if(ok) printf("S\n");
		else printf("N\n");
	
	}
	
	
	
	return 0;
}


























