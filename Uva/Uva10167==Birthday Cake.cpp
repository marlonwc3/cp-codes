
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
bool cmp(int a, int b) { return a>b;}


vii v;
int n;
ii solve(){
	int a=0, b=0, s=2*n, r;
	// ax + by = 0
	fr(i,-500,501){
		fr(j,-500,501){
			if(!i && !j) continue;
			a = b =0;
			fr(k,0,s){
					r = i*v[k].st + j*v[k].nd;
					a += (r < 0 );
					b += (r > 0 );
			}
			if ( a==n && b==n) {
				return mp(i,j);
			}
		}
	
	}
	
}
	

int main (int argc, char const* argv[]) {
	int s, a, b; ii res;
	while(1){
		sc1(n);
		if(!n) break;
		v.clear();	
		s = 2*n;
		fr(i,0,s){
			sc2(a,b);
			v.pb(mp(a,b));
		}
		int r =0;
		//break;
		res = solve();
		printf("%d %d\n",res.st, res.nd);
	}
	
	
	return 0;
}

















