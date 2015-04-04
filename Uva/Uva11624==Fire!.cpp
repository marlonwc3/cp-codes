#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int des[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
struct Point{
	int x, y, t;
	Point(){}
	Point(int _x, int _y){ x = _x; y = _y; }
	Point(int _x, int _y, int _t){ x = _x; y = _y; t = _t; }
};
int r, c;
queue<Point> q;

ci m[1005][1005];
bool mark[1005][1005];
vii fogos;

bool val(int x, int y){return (x >= 0 && x < r && y >= 0 && y< c );}

void bfsFogo(){
	int s = fogos.size();
	q = queue<Point>();
	fr(i,0, s) q.push( Point(fogos[i].st, fogos[i].nd) );
	Point aux; int x, y, t, dx, dy;
	while(!q.empty()  ) {
		aux = q.front(); q.pop();
		x = aux.x, y = aux.y;
		t = m[x][y].nd;
		fr(i, 0, 4){
			dx = x + des[i][0]; dy = y + des[i][1];
			if(!val(dx, dy)) continue;
			if(m[dx][dy].st == '#' )  continue ;
			if( m[dx][dy].nd > t + 1 ) {
				m[dx][dy].nd = t+1; 
				q.push(Point(dx, dy) );
			} 
		}
	}
}

int bfs(int x, int y){
	q = queue<Point>();
	q.push(Point(x, y, 0));
	mst(mark,0);
	mark[x][y] = 1;
	int res = inf , t, dx, dy;
	Point aux; 
	while(!q.empty()  ) {
		 aux = q.front(); q.pop();
		 x = aux.x, y = aux.y; t = aux.t;
		 fr(i,0,4){
		 	dx = x + des[i][0]; dy = y + des[i][1];
			if(!val (dx, dy)) {res = min (res, t+1); continue;}
			if(mark[dx][dy] ||  m[dx][dy].st == '#' || m[dx][dy].st=='F' || m[dx][dy].st =='J'  ) continue;
			if( m[dx][dy].nd <= t+1) continue;
			q.push( Point(dx, dy, t+1)  );
			mark[dx][dy]=1;
		 }
	}
	return res;
}



int main (int argc, char const* argv[]) {
	int t, xi, yi; char ch; 
	int res; 
	sc1(t);
	while(t--){
		sc2(r,c);
		fogos.clear();

		fr(i,0,r){
			fr(j,0,c){
				scanf(" %c", &ch);
				m[i][j] = mp(ch, inf);
				if(ch=='J') {xi=i, yi = j;}
				if(ch=='F' ) {
					fogos.pb(mp(i,j)); 
					m[i][j].nd = 0;
				} 				
 			}
		}
	
		bfsFogo();
		
		res = bfs(xi, yi);
		if(res >= inf || res < 0 ) printf("IMPOSSIBLE\n");
		else printf("%d\n", res);
		
		
	}
	
	
	
	return 0;
}














