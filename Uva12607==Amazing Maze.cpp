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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%llld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%lld %lld ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

char grid[105][105];
//int dist[105][105][5][(1<<8) + 10];
int dist_ok[105][105][5][(1<<8) + 10], PASSO;
int tesouros[105][105], tesouros_tem[105][105], TEM;



int n,m, qtd_tesouros;


bool val(int x, int y){return !(x < 0|| x >= n || y < 0 || y >= m); }

struct State{
	int x,y,k,mask, d;
	State(){}
	State ( int _x, int _y, int _k, int _mask, int _d){x=_x, y=_y, k=_k, mask=_mask, d =_d;}
};

int des[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0,-1}};

char quais[4] = {'N', 'E', 'S', 'W'};
int get(char ch){ fr(i,0,4) if(quais[i] == ch) return i; }


void toBin(int k, int n){
	if(!k) {while(n){printf("0"); n--; } return;}
	printf("%d", k%2);
	toBin(k/2, n-1);

}

int go(){
	queue<State> q;
	State state; 
	int x, y, k, mask, dx, dy, dk, mask_adj, d;
	q.push(State(0,0,grid[0][0],0,0));
	dist_ok[0][0][grid[0][0]][0] = PASSO;
	int res = inf;
	while(!q.empty()){
		state = q.front(); q.pop();
		x  = state.x, y = state.y, k = state.k, mask = state.mask, d = state.d;
		if( mask == qtd_tesouros && x == (n-1) && y==(m-1) ) {
			res = min(res, d);
			continue;
		}
		
		
		mask_adj = mask;			
		dx = x, dy = y;
		if(dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] != PASSO){
			dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] = PASSO;	
			q.push(State(dx,dy,(d+1+grid[dx][dy])%4 , mask_adj, d+1));		
		}

		mask_adj = mask;
		dx = x + des[k][0], dy = y + des[k][1];	
		mask_adj = mask;
		if(val(dx,dy)){
		
			if(dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] != PASSO){
				dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] = PASSO;	
				q.push(State(dx,dy,(d+1+grid[dx][dy])%4 , mask_adj, d+1));
			}
			
			if(tesouros_tem[dx][dy] ==TEM ){
				mask_adj |= (1<< tesouros[dx][dy]);
				if(dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] != PASSO){
					dist_ok[dx][dy][ (d+1+grid[dx][dy])%4 ][mask_adj] = PASSO;	
					q.push(State(dx,dy,(d+1+grid[dx][dy])%4 , mask_adj, d+1));
				}
			}
		}
	
	
	}
	 
	return res;
}



int main (int argc, char const* argv[]) {
	TEM=1; PASSO=1;
	
	while(1){
		sc2(n,m); if(!n && !m) break;
		fr(i,0,n){
			scanf("%s", grid[i]);
			fr(j,0,m) grid[i][j] = get(grid[i][j]);
		}
		int q, x, y;
		sc1(q);
		qtd_tesouros = (1<<(q))-1; 
//		printf("qtd: %d | q: %d \n", qtd_tesouros, q); toBin(qtd_tesouros) 
		TEM++;
		PASSO++;
		fr(i,0,q){
			sc2(x,y); x--; y--;
			tesouros[x][y] = i;
			tesouros_tem[x][y] = TEM;
		}
		x = go();
		printf("%d\n", x);
		
	}
	
	
	
	return 0;
}







