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
#define EPS 1e-9
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

vi arr[5];
int main (int argc, char const* argv[]) {
	int n, k;
	sc1(n);
	fr(i,0,n){
		sc1(k); 
		arr[k].pb(i+1);
	}
	int s = inf;
	fe(i,1,3) s = min(s, int(arr[i].size()) ) ;
	printf("%d\n", s);
	while(1){
		bool ok =1;
		fe(i,1,3) ok = ok && !arr[i].empty();
		if(!ok) break;

		printf("%d %d %d\n", arr[1].back(), arr[2].back(), arr[3].back());	
		fe(i,1,3) arr[i].pop_back();
	}
	return 0;
}






