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
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;




int main (int argc, char const* argv[]){
	int n, k, p, x, y;
	scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
	vi v;
	int a;
	fr(i,0,k){
		sc1(a);
		v.pb(a);
	}
	k = n-k;
	int aux = k;
	while(k--) v.pb(1);
	int sum = 0;
	sort(v.begin(), v.end());
	fr(i,0,v.size()) sum += v[i];
//	pv(v,x);
	int pos = n/2;
	vi r;
//	printf("aux: %d \n", aux);
	fr(i,pos,n){
		//if(aux < 0) break;
		if(v[i] >= y ) break;
		else {
			sum--;
			sum+=y;
			r.pb(y);
			aux--;
		}
	}
	if(aux < 0  || sum >x) printf("-1\n");
	else{
		while(aux--){
			r.pb(1);
		}	
		//sort(r.begin(), r.end());
		printf("%d", r[0]);
		fr(i,1,r.size()){
			printf(" %d", r[i]);
			
		}
		_
		
	}
	
	
	
	
	
	return 0;
}
