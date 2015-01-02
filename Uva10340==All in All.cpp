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

string a, b;
int  la, lb;
map<ii, int> pd;
bool ok;
int lca(int i, int j){
	if(ok) return 0;
	if(i>=la || j>=lb) return 0;
	ii par = mp(i,j);
	if(pd.count(par) ) return pd[par];
	int r;
	if(a[i]==b[j]) {
		r = 1+lca(i+1, j+1);
	}
	else{
	 	r = max( lca(i+1, j), lca(i, j+1)  );
	}
	if(r>=5) ok = 1;
	return pd[par] = r;
}
int main (int argc, char const* argv[]) {
	int r;
	while ( (cin >> a >> b) ){ 
		la = a.length(), lb = b.length();
		pd.clear();
		ok = 0;
		r = lca(0,0);
		if(r>= la ) printf("Yes\n");
		else printf("No\n");
	}	
	return 0;
}










