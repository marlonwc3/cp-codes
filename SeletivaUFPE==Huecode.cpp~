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

vii enemyes;
ii boy;
char grid[1005][1005]; 


int dist[1005][1005];
int n,m;
bool val(int x,int y){ return !(x < 0 || x>= n|| y < 0 || y  >= m); }
int des[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };

bool is(char c){
	return c >= '1' && c <= '9';
}

int go(){
	enemyes.clear();
	ii p;
	fr(i,0,n){
		fr(j,0,m){
			if(grid[i][j] =='B') p = mp(i,j);
			else if( is(grid[i][j]  ) ) enemyes.pb(mp(i,j)); 
			else if ( grid[i][j] == 'R' ) boy = mp(i, j);
			dist[i][j] = 0;
		}
	}
	int x, y, dx, dy;
	queue<ii> q;
	q.push(p);
	dist[p.st][p.nd] = 1;
	while(!q.empty()){
		p = q.front(); q.pop();
		x = p.st, y = p.nd;
		//printf("x: %d | y: %d\n", x, y);
		
		fr(i,0,4){
			dx = x + des[i][0], dy = y + des[i][1];
			if( !val(dx,dy) || dist[dx][dy] || grid[dx][dy] == 'P' ) { continue; }
			dist[dx][dy] = 1 + dist[x][y];
			q.push(mp(dx,dy));
		}
	}
	int d = dist[boy.st][boy.nd];
	int r = 0;
	fr(i,0,enemyes.size()){
		x = enemyes[i].st, y = enemyes[i].nd;
		if(!dist[x][y]) continue;
		if( dist[x][y] <= d ) {
			r += grid[x][y] - '0';
		}
	}
	return r;
	
}



int main (int argc, char const* argv[]) {
	
	int caso;
	sc1(caso);
	fe(t,1,caso){
		sc2(n,m);
		fr(i,0,n) scanf("%s", grid[i]);
		int r = go();
		printf("Caso #%d: %d\n",t,  r);
	
	}
	
	
	
	
	return 0;
}














