#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-6
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


int des[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}};
int r,c;
char matrix[100][100];
bool trap[100][100];
bool val(int x, int y){ 
	if( x < 0 || x >= r || y <  0 || y >= c ) return 0;
	return 1;
}
int cnt = 0;
void ff(int x,int y){
	if(matrix[x][y]=='X' || matrix[x][y]=='#' || matrix[x][y] =='T' ) return;
	cnt += matrix[x][y] == 'G';
	matrix[x][y]='X';	
	if(trap[x][y]) return;
	int dx, dy;
	fr(i,0,4){
		dx = x + des[i][0], dy = y + des[i][1];
		if(!val(dx,dy)) continue;
		ff(dx,dy);
	}
}
int main (int argc, char const* argv[]) {
	int aux;
	while(sc2(c,r)==2){
		mst(trap, 0);
		cnt = 0;
		int px=-1,py=-1, dx,dy;
		fr(i,0,r) {
			scanf("%s", matrix[i]);	
			fr(j,0,c){
				if(matrix[i][j]=='P') {px=i, py=j;}
				if(matrix[i][j]=='T'){
					trap[i][j]=1;
					fr(k,0,4){
						dx = i+des[k][0], dy = j+ des[k][1]; 
						if(!val(dx,dy)) continue;
						trap[dx][dy]=1;
					}
				}
			}
		}
		
		ff(px,py);
		printf("%d\n", cnt);
	}
	
	
	return 0;
}

