#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
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
typedef long double lb;

int des[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n,m;
bool val(int x, int y){ return (x < 0 || x >= n || y < 0 || y >= m ) ?  0 : 1 ; }
char matrix[120][120];

int find(int x, int y, int d){
	if(!val(x,y) ) return 0;
	if(matrix[x][y] =='.') return 0;
	bool ok = matrix[x][y] == 'x';
   	matrix[x][y] = '.';
    return ok | find( x+des[d][0], y+des[d][1] , d );	
}
int sum;
void ff(){
	bool ok;
	int dx, dy;
	fr(i,0,n){
		fr(j,0,m){
			if(matrix[i][j]!='.'){
				ok = matrix[i][j]=='x';
				matrix[i][j] = '.';
				fr(k,0,4){
					dx = i + des[k][0];
					dy = j + des[k][1];
					ok = ok | find(dx, dy, k);
				}
				if(ok){
					sum++;
				}
			}
		}
	}
	
}


int main (int argc, char const* argv[]) {
	int caso;
	sc1(caso); caso++;
	fr(t,1,caso){
		sc1(n);
		m=n;
		fr(i,0,n){
			scanf("%s", matrix[i]);
		}
		sum = 0;
		ff();
		printf("Case %d: %d\n", t, sum);
	}
	return 0;
}






