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
typedef  long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const long double PI = acos(-1);
const long double LIMIT =0.000001;
#define LSOne(S) ( S & (-S) )
vll t;
int LEN;
void create(int n){ t.assign(n+1, 0); LEN = n; }
ll rsq(int b){
	ll sum  =0; for(;b;b-=LSOne(b) ) sum += t[b];
	return sum;
}
ll rsq(int a, int b){ return rsq(b) - ((a==1) ? 0 : rsq(a-1));  }
void adjust(int k, ll v){
	for( ; k <= LEN; k+=LSOne(k) ) t[k] += v;
}



ll arr[10010];
int main (int argc, char const* argv[]){
	int N, K;
	sc2(N,K);
	int r = 1;
	ll x = -1;
	int k;
	ll acc = 0;
	fr(i,0,K){
		create(N);	
		fr(j,0,N){
			scanf("%lld", &arr[j] );
		//	printf("%d ", arr[j ]);
		}
	//	_
		acc = 0;
		for(int j =N-1; j>=0;j--){
		//	printf("arr[j]: %d\n", arr[j] );
			acc += rsq(arr[j]);
			adjust(arr[j], 1);
		}
		if(acc > x ){
			r = i+1;
			x = acc;
		}
		//printf("i: %d | acc: %d\n", i+1, acc);
		
	}
	printf("%d\n" , r);
	
	
	
	return 0;
}






