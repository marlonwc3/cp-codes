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
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


const int MAX_N = 2000010;
ll arr[MAX_N];
ii v[MAX_N];
int N;
bool mycmp(ii a, ii b) {
	return (a.st + a.nd  ) < ( b.st + b.nd ); 

}

int main (int argc, char const* argv[]){

	 ll k ;
	sc1(N);
	fr(i,0,N){
		scanf("%I64d", &k);
		arr[i] = k;
		v[i] = mp(k,i ); 
	
	}
	sort(v, v+N, mycmp);	
	//for(int i =0 ; i < N; i ++ ) printf("%I64d %I64d - \n", v[i].st, v[i].nd ) ;
	fr(i,0,N){
		k = v[i].nd;
	//	printf("%d %d\n", v[i].st, v[i].nd) ;
		arr[i] = v[i].st  + k  - i;
	}

	bool ok  = 1;
	//fr(i,0,N) printf("%I64d ", arr[i] ) ; _
	fr(i,1,N) if(arr[i] < arr[i-1]) {ok=0; break; }
	if(!ok) printf(":(\n");
	else {
		printf("%I64d", arr[0]);
		fr(i,1,N) printf(" %I64d", arr[i]);
		_
	}
	
	
	
	
	return 0;
}




