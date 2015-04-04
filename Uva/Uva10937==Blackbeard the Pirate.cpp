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

int n,m, PX, PY;
char grid[55][55];
int des[9][2] = {{1,0}, {-1,0}, {0,1},{0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
bool val(int x, int y){ return !(x < 0 || x >=n || y < 0 || y >= m ); }
bool ta(int x, int y){
	int dx, dy;
	fr(i,0,8){ 
		dx = x + des[i][0], dy = y + des[i][1]; if(!val(dx,dy)) continue;
		if(grid[dx][dy] == '*')  return 1;
	}	
	return 0;
}
bool ativo(int k, int p){ return k & (ll(1) << p); }
ll ative(int k, int p){ return k | (ll(1) << p); }
int dist[55][55][(1<<11) + 15][3], TOTAL;
bool OK;
struct State {
	int x, y, mask, lol;
	State(){}
	State(int _x, int _y, int _mask, int _lol){ x =_x, y = _y, mask =_mask, lol = _lol;}
};
int go(){
	fe(i,0,n) fe(j,0,m) mst(dist[i][j], 0);
	dist[PX][PY][0][0] = 1;
	queue<State> q;
	State state, adj;
	int x, y, dx, dy, mask, mask_adj;
	q.push(State(PX, PY, 0, 0));
	int res = inf, p, lol;
	while(!q.empty()){
		state = q.front(); q.pop();
		state.lol = (state.mask >= (TOTAL-1));
		x = state.x, y = state.y, mask = state.mask; lol = state.lol;
		if(lol){
			if(mask==TOTAL){


				OK=1;
				return dist[x][y][mask][lol];				
				res = min(res, dist[x][y][mask][lol]);				
				continue;			
			}
		}
		fr(i,0,4){
			dx = x + des[i][0], dy = y + des[i][1];
			if(!val(dx,dy) || ta(dx,dy) || grid[dx][dy] == '~' || grid[dx][dy] == '#') continue;
			bool pode = 1;
			p = grid[dx][dy] - '0';
			if( p>=0 && p <= 10) {	
				if(!ativo(mask, p)){
					adj = State(dx, dy, ative(mask,p), ative(mask,p)>=(TOTAL-1) );
					if(p || (!p && adj.lol)) {						
						if(!dist[adj.x][adj.y][adj.mask][adj.lol] ){ 
							dist[adj.x][adj.y][adj.mask][adj.lol] = 1 + dist[x][y][mask][lol];
							q.push(adj);
							pode = 0;
						}
					}
				}
			}
			if(!pode || dist[dx][dy][mask][lol]) continue;
			dist[dx][dy][mask][lol] = 1 + dist[x][y][mask][lol];
			q.push(State(dx,dy,mask,lol));
		}
	}
	return res;
}

int main (int argc, char const* argv[]) {
	while(1){
		sc2(n,m); if(!n && !m) break;
		int cnt =0; TOTAL = 0;
		fr(i,0,n){
			scanf("%s", grid[i]);
			fr(j,0,m){
				if(grid[i][j]=='!'){
					grid[i][j] = (++cnt) + '0';
					TOTAL = ative(TOTAL, cnt);
				}
				if(grid[i][j] == '@'){
					PX = i, PY = j;
				}
			}
		}
		grid[PX][PY] = '0';
		TOTAL = ative(TOTAL, 0);
		OK = 0;
		int res = inf;
		res = go();
		if(ta(PX,PY)) OK = 0;
		if(!cnt){res=1;}
		if(!cnt || OK)printf("%d\n", res-1);
		else printf("-1\n");
	}	
	
	
	return 0;
}















