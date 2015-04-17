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
typedef pair<char, int> ci;

int matrix[16][16];
int N;

int des[4][2] = {{1,0},{-1,0},{0,1}, {0,-1}};
bool val(int x, int y ){
	return !(x < 0 || x >= N || y < 0 || y >= N);
}
int matrixAdj[16][16];
bool par(int x, int y ){
	int s = 0;
	fr(i,0,4){
		if(!val(x + des[i][0], y + des[i][1]) ) continue;
		s += matrixAdj[x + des[i][0]][y + des[i][1]];
	}
	return s%2 == 0;
}

int tenta(){
	 fr(i,0,N) fr(j,0,N) matrixAdj[i][j] = matrix[i][j];
	int s = 0;
	fr(i,0,N){
		fr(j,0,N){
			if(par(i, j)) continue;
			if(i+1 >= N || matrixAdj[i+1][j]) return inf;
			matrixAdj[i+1][j] = 1;
			s++;
		}
	
	}
	
	return s;
	
}
int bt(int p){
	if( p >= N)  return tenta();
	if(matrix[0][p]) return bt(p+1);
	int r = inf;
	matrix[0][p] = 1;
	r = min(r, 1 + bt(p+1));
	matrix[0][p] = 0;
	r = min(r, bt(p+1));
	return r;	
}








int main (int argc, char const* argv[]){
	int caso;
	int res;
	sc1(caso);
	fe(t,1,caso){
		sc1(N);
		fr(i,0,N) fr(j,0,N) sc1(matrix[i][j]);
		
		
		res = bt(0);
		if(res>=inf) res = -1;
		printf("Case %d: %d\n", t, res);
	
	}

	
	return 0;
}






















