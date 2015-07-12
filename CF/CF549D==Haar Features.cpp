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

#define LSOne(S) (S & (-S) )
vll t[105];

int M, N ;
void ft_create () {  fe(i,0,N+1) t[i].assign(M+1, 0); }   
ll ft_rsq(int b, int r) {
    ll sum = 0; for(; b; b -= LSOne(b) ) sum += t[r][b];
    return sum;
}
int ft_rsq(int a, int b, int r) { return ft_rsq(b, r) - (a==1 ? 0 : ft_rsq(a-1, r)); }
void ft_adjust(int k, ll v, int r) {
    for(; k<= M; k+= LSOne(k)  ) {
    //	printf("[Bit] | r: %d | k: %d\n", r, k );
    	t[r][k]+=v;
    }
  //  printf("fim adjust\n");
}

bool mycmp(ii a, ii b) {
	int d1 = (N - a.st)*(N-a.st) + (M - a.nd)*(M - a.nd);
	int d2 = (N - b.st)*(N-b.st) + (M - b.nd)*(M - b.nd);	
	//return d1 < d2;
	if(a.st == b.st) {
		return a.nd > b.nd;
	}
	return a.st > b.st; 
}
ll ans = 0;
char grid[105][105];

int main (int argc, char const* argv[])
{
	vii v;
	
	sc2(N,M);
//	printf("N: %d | M: %d\n", N, M );
	fe(i,1,N){ 
		scanf("%s", grid[i]); 
		//printf("%s \n", grid[i] );
		fe(j,1,M) v.pb(mp(i,j));
	 } 
	sort(v.begin(), v.end(), mycmp);
	//pvp(v,x);
	ft_create();
	int a ,b, c, d;
	fr(i,0,v.size() ) {
		a = v[i].st, b = v[i].nd;
		c = ft_rsq(b, M, a);
	//	printf("a: %d | b: %d | c: %d | grid: %c \n", a, b, c, grid[a][b-1] );
		if(grid[a][b-1] == 'W') {
		//	printf("Eh W !\n");
			if(c==1) continue;
			d = (1 - c);
			//printf("W fudido | d: %d\n", d);
			for(int j = a; j >= 1; j-- ){ 
			//	printf("BOtando j: %d\n", j );
				ft_adjust(b, d, j);
			//	printf("botando linha %d | ate col: %d --> %d \n", j, b+1, ft_rsq(d, j) );

				//ft_adjust(b+1, -d, j);
			}
			ans++;
		}
		else{
			if(c==-1) continue;		
			d = (-1 - c);
			for(int j = a; j >= 1; j-- ){ 
				ft_adjust(b, d, j);
			//	printf("botando linha %d | ate col: %d --> %d \n", j, b+1, ft_rsq(d, j) );

				//ft_adjust(b+1, -d, j);
			}		
			ans++;	
		}
	//_
		//printf("rsq 1: %d\n", ft_rsq(1,M, 1) );
		//printf("rsq 1,1: %d\n", ft_rsq(2,M, 1) );
		//printf("rsq 1,2: %d\n", ft_rsq(2,2, 1) );				 
		
		
	//	break;
		
	
	}	
	printf("%I64d\n", ans);

	


	
	return 0;
}


