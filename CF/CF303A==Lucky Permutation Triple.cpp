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
	vi v1, v2, v3;
	int n, k;
	sc1(n);
	if(n%2 == 0 )printf("-1\n");
	else{
		printf("0");
		fr(i,1,n) printf(" %d", i);	 _
		printf("0");
		fr(i,1,n) printf(" %d", i);	 _
		printf("0");
		fr(i,1,n) printf(" %d", (2*i)%n);	 _				
	}

	
	
	
	
	
	
	
	
	
	
	return 0;
	
	bool ok = 0;
	
	do{
		do{
			set<int> s;
			bool ok2= 1;
			v3.clear();
			fr(i,0,n){
				k = (v1[i] + v2[i])%n;
				if(s.count(k) ) {ok2=0; break; }
				s.insert(k); v3.pb(k);
			}
			if(ok2) {ok=1; goto label;}
			
		}while(next_permutation(v2.begin(), v2.end()) );
		
		
	} while(next_permutation(v1.begin(), v1.end()) );
	label:;
	if(!ok) printf("-1\n");
	else {

		printf("YES\n"); pv(v1,x); pv(v2,x); pv(v3,x);
	}




	return 0;
}



