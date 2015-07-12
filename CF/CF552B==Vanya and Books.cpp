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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef unsigned long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


int nd(int k){
	if(k== 0) return 1;
	int r = 0;
	while(k){
		r++; k/=10;
	}
	return r;
}

ll n;
ll ans = 0;
int main (int argc, char const* argv[]){
	cin >> n;
	ll a = 1, b = 9, z = 1;
	//printf("n: %I64d\n", n );
	while( n > b ) {
		//printf("a: %I64d | b: %I64d\n", a, b);
		ans += (b-a+1)*z;
		a = b+1;
		b = 10*b + 9;
		z++;
	}
	//printf("azgora ans: %I64d | z: %I64d \n", ans, z);
	ll k2 = (b-a+1)*z; 
	//printf("a: %I64d | b: %I64d |k2: %I64d\n", a ,b ,k2);
	ans += k2;
	ans -= (b-n)*(z);
	cout << ans << endl;
	
	
	if(0){
	ll x = 0;
	fe(i,1,n){
		x += nd(i);
	}
	
	}
	
	
	
	return 0;
}
