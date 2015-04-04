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

int nums[120];
int m, n; // preço, num moedaas

ll pd[50005];

ll bt(int sum){	
	if( sum < 0 ) return linf;
	if(sum==0) return 0;
	if(pd[sum] != -1 ) return pd[sum];
	ll r = linf;
	fr(i,0,n) {
		if( nums [i] <= sum ) {
			r = min(r, 1 + bt(sum - nums[i] )  );
		}
	}	
	return pd[sum] = r;
	
	
}

int main (int argc, char const* argv[]) {
	
	int k;
	ll r;
	while(1){
		sc1(m);  if(!m) break;
		sc1(n);
		mst(pd,-1);
		fr(i,0,n) {
			sc1(nums[i]);
		}
			
		r = bt(m);
		if(r >= linf || r < 0 ) printf("Impossivel\n");
		else printf("%lld\n", r);
		
		
		
	}
	
	
	return 0;
}



