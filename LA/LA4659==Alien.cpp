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

vi todos;
char grid[12][12];
const int des[9][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
int N, SZ;
int pd[100][(1<<16)-1];
int pd_ok[100][(1<<16)-1], PASSO;


int go(int p, int mask){
	if(mask == ((1<<N)-1) ) return 0;
	if(p >= SZ ) return inf;
	if(pd_ok[p][mask] == PASSO) return pd[p][mask];
	int r = min( go(p+1, mask) , go(p+1, mask | todos[p]) + 1 );
	pd_ok[p][mask] = PASSO;
	return pd[p][mask] = r;
}

bool val(int x, int y){
	return !(x < 0 || x >= 10 || y < 0 || y >= 10);
}
int pode[12][12], NAO_PODE;

int main (int argc, char const* argv[]){
	mst(pode, 0); NAO_PODE = 0;
	mst(pd_ok, 0); PASSO=0;
	
	int caso, dx,dy;
	sc1(caso);
	fe(t,1,caso){
		todos.clear();
		N=0;
		NAO_PODE++;
		PASSO++;
		fr(i,0,10){
			scanf("%s", grid[i]);
			fr(j,0,10){
				if(grid[i][j]=='g'){
					fr(d,0,9){
						dx = i +des[d][0], dy = j + des[d][1];
						if(!val(dx,dy)) continue;
						pode[dx][dy] = NAO_PODE;
					}
				}
			}
		}
		fr(i,0,10){
			fr(j,0,10){
				if(grid[i][j]=='e'){
					fr(d,0,9){
						dx = i + des[d][0], dy = j + des[d][1];
						if(!val(dx,dy) || pode[dx][dy] == NAO_PODE ) continue;
						grid[i][j] = N++;
						break;
					}			
				}
			
			}
		}
	
		int mask;
		fr(i,0,10){
			fr(j,0,10){
				if(pode[i][j] ==NAO_PODE) continue;
				mask = 0;
				fr(d,0,9){
					dx = i + des[d][0], dy = j + des[d][1];
					if(!val(dx,dy) || grid[dx][dy] > N ) continue;
					mask |= (1<<grid[dx][dy]);
				}
				if(mask) todos.pb(mask);
			}
		}
		vi::iterator it = unique(todos.begin(), todos.end());
		todos.resize( distance(todos.begin(), it) );
		SZ = todos.size();
//		pv(todos,x);
//		break;
		int r = go(0,0);
		printf("%d %d\n", N, r);
		
		
	
	}
	
	
	
	return 0;
}













