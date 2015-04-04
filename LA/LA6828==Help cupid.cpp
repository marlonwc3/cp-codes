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

vi v;
int main (int argc, char const* argv[]) {
	int n, sum, k, ans;
	while(sc1(n) == 1 ) {
		v.clear();
		sum = 0;
		fr(i,0,n){
			sc1(k);
			v.pb(k);
			v.pb(k+24);
		}

		sort(v.begin(), v.end());	
		//pv(v,x);
		ans = inf;
		//printf("sum %d | n %d ans %d\n", sum, n, ans);		
		for(int i =0; i+n < v.size(); i++){
			sum = 0;
			for(int j = i; j<i+n; j+=2){
				sum += abs(v[j+1]- v[j]);
			}
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
		
	}	
	
	
	return 0;
}










