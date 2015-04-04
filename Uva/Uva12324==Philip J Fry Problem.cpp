#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;


ii t[105];
int n;
int pd[105][1005];
int bt(int p, int k){ // k== num total de esferas
	if(p==n) return 0;
	if(pd[p][k] != -1 ) return pd[p][k];
	int time = t[p].st, w = t[p].nd;
	int r = time + bt( p+1,  k+w);		
	if(k >0 ){
		r = min(r, (time)/2  + bt(p+1, k-1+w)   );
	}
	return pd[p][k]=r;
}

int main (int argc, char const* argv[]) {
	int a, b;
	while(1){
		sc1(n); iz(n);
		mst(pd, -1);
		fr(i,0,n){
			sc2(a,b);
			t[i] = mp(a,b);
		}
		
		a = bt(0, 0);
		printf("%d\n", a);
	}
	
	
	return 0;
}





