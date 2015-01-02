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

int des[8][2] = {  {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1},{1,-1}, {-1,-1} };
int r, c;
char grid[120][120];
int memo[120][120];
bool val(int x, int y){ return ! ( x<0 || x >= r || y <0 || y >= c );  }

int ff(int x, int y, int k){
	if(grid[x][y]=='L') return 0;
	if(grid[x][y]=='X' && !k ) return 0;
	if(memo[x][y]!=-1) return 0;
	int cnt=  0 , dx, dy, r;	
	if(grid[x][y]=='X'){
		memo[x][y] = k;
		fr(i,0,8) { 
			dx = x + des[i][0], dy = y+ des[i][1]; 
			if(!val(dx,dy)) continue;
			ff(dx,dy,k);
		}
		return 0;
	}
	grid[x][y] = 'X';
	fr(i,0,8){
		dx = x + des[i][0], dy = y + des[i][1];
		if(!val(dx,dy)) continue;
		r = ff(dx,dy, k);
		cnt += r;
	}
	return 1+ cnt;
}

int main (int argc, char const* argv[]) {
	int t, x,y, res;
	sc1(t);
	char str[10];
	bool first=1;
	while(t--){
		r=c=0;
		mst(grid, 0);
		mst(memo,-1);
		if(!first) _
		while(1){
			scanf("%s", grid[r]);
			if(grid[r][0]>='0' && grid[r][0] <= '9') break;
			r++;
		}
		c = strlen(grid[0]);
		sscanf(grid[r], "%d", &x);
		scanf("%d", &y);
		x--, y--;
		res = ff(x,y,0);
		ff(x,y,res);
		printf("%d\n", res);
		while(	scanf("%d %d", &x, &y) == 2){
			x--, y--;
			if(memo[x][y]!=-1) res = memo[x][y];
			else {
				res = ff(x,y,0);
				ff(x,y,res);
			}
			printf("%d\n", res);
		}
		first = 0;	
	}
	
	
	
	return 0;
}


