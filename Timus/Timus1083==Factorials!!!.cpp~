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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-12
#define oi(__) cout << "Oi ["<< __ << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const long double PI = acos(-1);
const long double LIMIT =0.000001;

char str[100];
int main(){
	ll n;
	scanf("%lld", &n);
	scanf("%s", str);
	ll cnt = 0;
	for(int i = 0; str[i]; i++){
		if(str[i] == '!') cnt++;
	}
	ll para = (n % cnt == 0) ? cnt : (n % cnt) ;
	ll r = 1;
//	printf("para: %d\n", para);
	//int x = 0;
	for(ll i = 0; ; i++){
		if( (n - i*cnt) == para ) {
			r *= (n-i*cnt);
			break;
		}
//		printf("i: %d | cnt: %d | i*cnt: %d\n", i, cnt, i*cnt );
		//if(x++ > 6) break;
		r *= (n - i*cnt);
	}
	printf("%lld\n", r);
	
	
	
	
}
