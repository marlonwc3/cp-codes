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

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b, a%b); }

ll mmc(ll a, ll b){ return (a*b)/gcd(a,b); }




int arr1[10005], arr2[10005];

int main (int argc, char const* argv[]) {
	int caso, n;
	sc1(caso);
	fe(t,1,caso){
		sc1(n);
		fr(i,0,n){ sc1(arr1[i]); }
		fr(i,0,n){ sc1(arr2[i]); }
		ll res = 0;
		fr(i,0,n){
			res = max(res, mmc(arr1[i], arr2[i]) );
		}
		printf("Caso #%d: %lld\n", t, res);
		
	}	
	
	
	
	
	return 0;
}


