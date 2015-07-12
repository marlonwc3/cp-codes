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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int des[4][2] = {{1,0},  {-1,0}, {0,1}, {0,-1}};
int N,M;
bool val(int x, int y){ return !(x < 0 || x >= N || y < 0 || y >= M); }

int c,d;
char grid[550][550];
bool mark[550][550];
void go(ii p){

	queue<ii> q;
	q.push(p);
	mark[p.st][p.nd] = 1;
	int dx, dy,x ,y;
	while(!q.empty()){
		p = q.front(); q.pop();
		x = p.st, y = p.nd;
		
		//printf("X: %d | Y: %d \n", x, y);
		if(x == c && y == d) goto fim;
	//	printf("marou %d %d \n", x, y);
		fr(i,0,4){
			dx = x + des[i][0], dy = y + des[i][1];
			if(!val(dx,dy)) continue;
			//printf("-> dx: %d | dy: %d || (mark[dx][dy] || grid[dx][dy] == 'X') : %d \n", dx, dy, (mark[dx][dy] || grid[dx][dy] == 'X'));
			if(!(dx == c && dy == d) &&  (mark[dx][dy] || grid[dx][dy] == 'X') ) continue;
			mark[dx][dy] = 1;
			q.push(mp(dx,dy));
			//printf("botou!\n");
			if(dx == c && dy == d) goto fim; 
			
		}
		
		
	}
	fim:;

}



int main (int argc, char const* argv[]){
	sc2(N,M);
	ii p;
	int a,b;
	fr(i,0,N) scanf("%s", grid[i] );
	sc2(a,b); a--; b--;
	sc2(c,d); c--; d--;
	mst(mark, 0);
	go(mp(a,b));
	

	if(mark[c][d]) {
		//printf("marcado!\n");
		if(grid[c][d] == 'X' && (a!=c && b != d) )  printf("YES\n");
		else{
			int x, y;
			bool ok = 0;
			//printf("da p chegar!\n");
			int cnt = 0;
			bool eh = 0;
			fr(i,0,4){
				x = c + des[i][0], y = d + des[i][1];
			//	printf("x: %d | y: %d\n",x, y);
				if(x==a && y==b) eh = 1;
				if(!val(x,y) ||	 grid[x][y] == 'X' ) continue;
					ok = 1;
					cnt++;
			
			}
			if( cnt >= 2 || (cnt>=1 && grid[c][d] == 'X') || (eh && grid[c][d] =='X') || (eh && grid[c][d] == '.' && cnt >=1 ) ) printf("YES\n");
			else printf("NO\n");
		
		}
	
	}
	else printf("NO\n");
	
	
	
	return 0;
}
