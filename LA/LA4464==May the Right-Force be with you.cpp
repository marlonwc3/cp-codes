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

struct node{
	int  x, y, dir;
	ll d;
	node(){}
	node(int _x, int _y, ll _d, int _dir){ x=_x, y=_y, d=_d, dir=_dir;}
};
int des[4][2] = { {0,1}, {1,0},{0, -1}, {-1,0} };
int n, m;
bool val(int x, int y){ return !(x <0||x >= n || y < 0 || y >= m );}

ll dist[1005][1005][5];
char grid[1005][1005];

int sx, sy;
ll res;
void go(){
	queue<node> q;
	node mynode;
	int x, y,  dir, dx, dy;
	ll d;
	mst(dist, 0);
	dist[0][0][0]=1;
	dist[0][0][1]=1;
	
	q.push(node(0,0, 0, 0));
	q.push(node(0,0, 0, 1));
	while(!q.empty()){
		mynode = q.front(); q.pop();
		x = mynode.x, y=mynode.y, d = mynode.d, dir =mynode.dir;
		if(x == sx && y == sy ) { res = d; return; }
		//printf("x: %d | y: %d | d: %lld | dir: %d\n", x, y, d, dir);
		dx = x + des[dir][0], dy = y +des[dir][1];
		if(val(dx,dy) && !dist[dx][dy][dir] && grid[dx][dy] == '0' ){
			dist[dx][dy][dir] = 1 + d;
			q.push(node(dx, dy, dist[dx][dy][dir], dir));
		}
		dir = (dir+1)%4;
		dx = x + des[dir][0], dy = y +des[dir][1];
		if(val(dx,dy) && !dist[dx][dy][dir] && grid[dx][dy] == '0' ){
			dist[dx][dy][dir] = 1 + d;
			q.push(node(dx, dy, dist[dx][dy][dir], dir));
		}
	}
}



int main(int argc, char const *argv[]) {

	while( 1 ) {
		sc2(n,m); 
		if(!n && !m) break;
		sc2(sy, sx);
		sx--, sy--;

		fr(i,0,n){
			scanf("%s", grid[i]);
		}
		res=-1;
		if(grid[0][0] == '0') go();
		if( res != -1) printf("%lld\n", res);
		else printf("NOOO!\n");

	}
	return 0;
}
