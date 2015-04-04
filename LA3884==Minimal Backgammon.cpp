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
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int PASSO = 1;

int grid[120];
int n, t;
int pd_ok[120][120];
double pd[120][120];

double go(int p, int tc){
        if( p == n) return 1;
        if( tc >= t) return 0;
        if(pd_ok[p][tc] == PASSO ) return pd[p][tc];
        
        
        double r = 0;
        int d;
        fe(i,1,6){
                d = p+i;
                if( d > n ) d = n - abs(d-n) ;
                if( grid[d] =='L' ) r += go(d, tc+2);
                else if( grid[d] == 'B') r+= go(0, tc+1);
                else r += go(d, tc+1);
        }
       	pd_ok[p][tc] = PASSO;
        return pd[p][tc] = r/6;
}



int main (int argc, char const* argv[]) {
	int a, b, k;
	double r;
	while(1){
		sc4(n, t, a, b);
		if(!n && !t && !a && !b) break;
		mst(grid, 0);
		fr(i,0,a){
			sc1(k);
			grid[k]='L';
		}
		fr(i,0,b){
			sc1(k);
			grid[k]='B';		
		}
		r = go(0, 0);
		PASSO++;
		printf("%.6lf\n", r);
	}
	return 0;
}








