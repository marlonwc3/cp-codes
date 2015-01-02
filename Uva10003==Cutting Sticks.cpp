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


vi v;
int pd[1005][1005];

int solve(int a, int b){
//	printf("solve %d %d\n", a,b);
	if(a==b) return 0;
	if(a+1 == b) return 0;
	if(pd[a][b]!=-1) return pd[a][b];
	int cont = v[b]-v[a];
//	if(v[b] < v[a] ) printf("a%d b%d -- vb%d va%d\n", a,b, 	v[b], v[a]);
	int res = inf;
	for(int i=a+1; i<b; i++){
		res = min ( res, solve(a,i) + solve(i,b) );
	}
	cont+=res;
	return pd[a][b] = cont;
}


int main (int argc, char const* argv[]) {
	int l, n, c;
	while(1){
		sc1(l); iz(l);
		mst(pd, -1); 
		v.clear();
		v.pb(0);
		sc1(n);
		while(n--) {
			sc1(c);
			v.pb(c);
		}
		v.pb(l); n = v.size()-1;
		n = solve(0,n);
		printf("The minimum cutting is %d.\n", n);
		
	}
	
	
	
	return 0;
}





