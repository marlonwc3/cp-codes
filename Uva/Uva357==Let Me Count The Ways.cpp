#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
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



int nums[10] = {1, 5, 10, 25, 50};
ll pd[30005][6];
ll bt(int n, int p){
	if(n < 0 ) return 0;
	if( n== 0 ) return 1;
	if( p == 5) { return n==0; }
	if( nums[p] > n  ) return 0;
	if(pd[n][p] != -1 ) return pd[n][p];
	ll cnt = 0 , w;
	for(ll i =0; n - i*nums[p] >= 0; i++  ){
		cnt +=  bt( n- i*nums[p], p+1 );
	}
	return pd[n][p] = cnt;
}

int main (int argc, char const* argv[]) {
	mst(pd,-1);
	int n;
	ll k;
	while(sc1(n) ==1 ){
		k= bt(n, 0);
		if(k>1)  printf("There are %lld ways to produce %d cents change.\n", k, n);
		else printf("There is only 1 way to produce %d cents change.\n",n);

	}
	
	
	return 0;
}





