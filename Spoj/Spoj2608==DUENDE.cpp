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
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii; 
typedef set<int> si;
typedef pair<char, int> ci; 
typedef long double lb;

/*
0 saida
1 normal 
2 tem cristao
3 inicial
*/

int n, m;
int des[4][2] = {   {0,1}, {0,-1}, {1,0}, {-1, 0} };
int matrix[15][15], dist[15][15];
queue<ii> q;
bool val(int x, int y){
	if( x< 0 || x >=n || y <0 || y>=m) return 0;
	return 1; }
	
	
int bfs(ii ini){
	int x, y, dx, dy, res = inf;
	mst(dist, inf);
	dist[ini.st][ini.nd] = 0;
	q = queue<ii>();
	q.push(ini);
	while(!q.empty()){
		ini = q.front(); q.pop();
		x = ini.st, y = ini.nd;
		fr(i,0,4){
			dx = x + des[i][0];
			dy = y + des[i][1];
			if(!val(dx, dy) ) continue;
			if( matrix[dx][dy] == 2 || matrix[dx][dy]==3 ) continue;
			if(dist[dx][dy] > dist[x][y] + 1 ) {
				dist[dx][dy] = dist[x][y] + 1;
				q.push(mp(dx,dy));
			}
			if(matrix[dx][dy] == 0) res = min(res, dist[dx][dy]);
		}
	}
	return res;
}


int main (int argc, char const* argv[]){
	sc2(n,m);
	int k;
	ii ini;
	fr(i,0,n){
		fr(j,0,m){
			sc1(k);
			matrix[i][j]=k;
			if(k==3){
				ini.st = i, ini.nd = j;
			}
		}
	}
	k = bfs(ini);
	printf("%d\n", k);
	
	
	
	return 0;
}





















