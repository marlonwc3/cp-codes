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

int N, K;
int arr[60];
int pd[10010];
int go(int n){
	if( n <= 0 ) return 1;
	if(pd[n] != -1) return pd[n];
	set<int> s;
	fr(i,0,K){
		if(arr[i] > n) break;
		s.insert(go(n - arr[i] ) );
	}	
	int r = 0;
	while(s.count(r) ) {
		r++;
	}	
	return pd[n] = r;

}



int main (int argc, char const* argv[]){

	sc2(N,K);
	fr(i,0,K) sc1(arr[i]);
	sort(arr, arr+K);
	
	fe(i,0,N) pd[i] = -1;
	int r = go(N);
	//printf("r: %d\n", r);
	if(r) printf("1\n");
	else printf("2\n");
	
	
	
	return 0;
}

