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

int ni[1005];
int di[1005];
int pi[1005];
int n;

ll mem[1005][20005];

ll bt(int day, int q){
	if( day >= n ) return 0;
	int d = di[day];
	d -= q;
	if ( d > ni[day] ) return linf;
	if( mem[day][q] != -1 ) return mem[day][q];
	
	ll sum = d * pi[day];
	int x = min(ni[day] - d, di[day+1]);
	ll r = inf;
	fe(i,0,x){
		r = min(r, pi[day]*i + bt(day+1, i) ); 
	}
	return mem[day][q] = sum + r;
	
}






int main (int argc, char const* argv[]) {
	int t;
	sc1(t);
	while(t--){
		sc1(n);
		fr(i,0,n){
			mst(mem[i], -1);
			sc3(pi[i], ni[i], di[i]);
		}
		ll res = bt(0, 0);
		printf("%lld\n", res);	
	}
	return 0;
}


















