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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

vi r;
vi v;
int arr[25], n, m, res;
void go(int p, int sum){
	if(p >= n){
		if( sum > m) return;
		if( sum > res ) {
			res = sum;
			r = v;
			return;
		}
		return;
	}
	v.pb(arr[p]);
	go(p+1, sum + arr[p]);
	v.pop_back();
	go(p+1, sum);
	
}


int main (int argc, char *argv[]) {
	while( sc2(m,n) == 2){
		r.clear(); v.clear();
		res = -inf;
		fr(i,0,n){
			sc1(arr[i]);
		}
		//fr(i,0,n) printf("%d ", arr[i] ); _
		
		go(0, 0);
		fr(i,0,r.size()) printf("%d ", r[i]);
		printf("sum:%d\n", res);
	}
	
	
	return 0;
}
















