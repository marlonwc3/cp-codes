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

int dist[1020][1020];
int r, c, sx, sy;
int des[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
bool val(int x, int y){ return !(x<0||x>=r ||y <0 ||y>=c);	 }

struct node{
	int x, y, d;
	node(){}
	node(int _x, int _y, int _d){ x=_x, y=_y, d=_d;}
	bool operator < (const node &n) const{
		return d < n.d;
	}
};

queue<node> q;
int dijkstra( ii ini){
	dist[ini.st][ini.nd] = 0;
	int x, y, dx,dy, d;
	node no;
	q = queue<node>();	
	q.push(node(ini.st, ini.nd, 0) );
	while(!q.empty()){
		no = q.front(); q.pop(); 
		x = no.x, y= no.y, d =no.d;
		if(dist[x][y] != d) continue;
		fr(i,0,4){
			dx = x + des[i][0], dy = y +des[i][1];
			if(!val(dx,dy)) continue;
			if(dist[dx][dy]==-1) continue;
			if( dist[dx][dy] > d + 1 ) {
				dist[dx][dy] = d+1;
				q.push(node(dx, dy, d+1) );
			} 
		}
	}
	
	return dist[sx][sy];
}

int main (int argc, char const* argv[]) {
	int n, cnt, x,y;
	while(1){
		sc2(r,c); if(!r && !c ) break;
		mst(dist,inf);
		sc1(n);
		while(n--){
			sc2(x, cnt);
			while(cnt--){
				sc1(y);
				dist[x][y] = -1;
			}
		}
		sc4(x,y,sx,sy);
		n = dijkstra(mp(x,y));
		printf("%d\n", n);		
	}
	
	
	return 0;
}


