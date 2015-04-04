#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b)  if(!b) {break;}
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a,b) memset(a, b, sizeof (a))
#define fr(i,a,b) for(int i = (a); i < (b); i++)
#define fe(i,a,b) for(int i = (a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a,i) for(int i =0; i < (a.size()); i++ ) { printf("%d ", a[i]); if(i != a.size() -1) printf(" "); }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;


int des[8][2] = {
	{-2, 1}, {-1, 2}, {1, 2},{2, 1}, {2, -1},{1, -2}, {-1, -2}, {-2, -1}
};



int main (int argc, char const* argv[]) {
	
	int n;

	while(sc1(n)==1){
	
		bool mark[10][10];
		mst(mark, 0);
		mark[4][1] =1;
		mark[4][2] =1;
		mark[2][2]= 1;
		mark[3][5] =1;
		
		
		
		int x =4, y = 4 , dx, dy;
		int d;
		int cnt  = 0;
		bool ok = 1;
		fr(i,0,n){
			sc1(d); d--;
			dx = x + des[d][0];
			dy =y + des[d][1];
			//printf("d: %d dx: %d | dy: %d | %d \n", d, dx, dy, mark[dx][dy] );
			if(ok) cnt++;
			if(mark[dx][dy]) ok=0;
			//mark[dx][dy]=1;
			x = dx;
			y = dy;
			
		}
		printf("%d\n", cnt);
	}
	
	
	
	
	
	
	
	return 0;
}
