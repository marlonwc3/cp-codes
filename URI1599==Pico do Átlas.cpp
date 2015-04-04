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

int grid[1200][1200];

vii v;
bool mycmp(ii a, ii b){
	if(a.st == b.st ) return a.nd < b.nd;
	return a.st < b.st; 
}

int des[8][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};
int n,m;

bool val(int x, int y){
	return !(x < 0 || x >= n || y < 0 || y >= m );
}

int main (int argc, char const* argv[]) {

	while( sc2(n,m) == 2 ){
		fr(i,0,n){
			fr(j,0,m){
				sc1(grid[i][j]);
			}
		}
		v.clear();
		int dx, dy;
		fr(i,0,n){
			fr(j,0,m){
				bool ok = 1;
				fr(d, 0, 8){
					dx = i + des[d][0];
					dy = j + des[d][1];
					if(!val(dx,dy)) continue;
					ok = ok && grid[i][j] > grid[dx][dy];
				}
				if(ok) v.pb(mp(i+1,j+1));		
			}
		}
		if(v.empty()){
			printf("-1\n");
		}
		else{
			sort(v.begin(), v.end());
			fr(i,0,v.size()){
				printf("%d %d\n", v[i].st, v[i].nd);
			}
		}
		
		_
	
	}
	
	
	
	
	
	return 0;
}









