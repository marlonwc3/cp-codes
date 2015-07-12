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

int NEXT = 1;
vii c1[105],  c2[105];
vi v1[105],  v2[105];
vii b1, b2;

inline int get(){return NEXT++; }

int main (int argc, char const* argv[]){
	int K, a, b;
	int N= 0, M = 0;
	sc1(K);
	if(K%2 == 0 ) printf("NO\n");
	else {
		
		//M = 1;

		
		
		
		ii p, p2;
		int X = get(), Y = get() ;
		fr(i,0,K-1){
			fr(j,0,K+1) {v1[i].pb(get()); }
		}
		fr(i,0,K-1){
			fr(j,0,K+1){
				fr(l, j+1, K+1){
					c1[i].pb(mp(v1[i][j], v1[i][l]));
					//M++;
					
				}
			}
			p = c1[i].back();
			b1.pb(mp(X, p.st));
			//M++;
			
			
			if(i%2 == 1) {
				p2 = c1[i-1].back();
				b1.pb(mp(p.nd, p2.nd) );
				//M++;
				c1[i].pop_back();
				c1[i-1].pop_back();
				//M -= 2;
			}
		}
		
		

		fr(i,0,K-1){
			fr(j,0,K+1) { v2[i].pb(get());   }
		}
		fr(i,0,K-1){
			fr(j,0,K+1){
				fr(l, j+1, K+1){
					c2[i].pb(mp(v2[i][j], v2[i][l]));
					//M++;
				}
			}
			p = c2[i].back();
			b2.pb(mp(Y, p.st));
			//M++;
			if(i%2 == 1) {
				p2 = c2[i-1].back();
				b2.pb(mp(p.nd, p2.nd) );
				c2[i].pop_back();
				c2[i-1].pop_back();
				//M -= 2;
			}
		}
		fr(i,0,K-1){
			M += c1[i].size();
			M += c2[i].size();
		}	
		M += b1.size();
		M += b2.size();
		M++;
		N = NEXT -1 ;
		if(N > 1000000 || M > 1000000) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n%d %d\n", N, M);	
		//return 0;	
		fr(i,0,K-1){
			fr(j,0,c1[i].size()){
				printf("%d %d\n", c1[i][j].st, c1[i][j].nd);
			}
		}
		fr(i,0,K-1){
			fr(j,0,c2[i].size()){
				printf("%d %d\n", c2[i][j].st, c2[i][j].nd);
			}
		}		
		fr(i,0,b1.size()){
			printf("%d %d\n", b1[i].st, b1[i].nd);
		}
		fr(i,0,b1.size()){
			printf("%d %d\n", b2[i].st, b2[i].nd);
		}		
		printf("%d %d\n", X,Y	);
	
	
	
	
	
	}
	
	
	
	return 0;
}





