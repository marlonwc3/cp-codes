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

int n,m;



bool val(int x,  int y){
	return !(x < 1 || x > n || y < 1 || y > m );
}
int grid[2000][2000];
bool check(int x, int y){
	int cnt = grid[x][y];
	int k = 0;
	//st left
	k += grid[x-1][y-1];
	k+= grid[x-1][y];
	k += grid[x][y-1];
	if(cnt +  k == 4 ) return 1;
	k = 0;
	
	k += grid[x-1][y];
	k += grid[x-1][y+1];
	k += grid[x][y+1];
	if(cnt +  k == 4 ) return 1;

	k = 0;
	k += grid[x][y+1];
	k += grid[x+1][y+1];
	k += grid[x+1][y];
	
	if(cnt +  k == 4 ) return 1;

	k = 0;	
	k += grid[x+1][y];
	k += grid[x+1][y-1];
	k += grid[x][y-1];
	
	if(cnt +  k == 4 ) return 1;
	
	return 0;	
	
	
	
}


int main (int argc, char const* argv[]) {
	int n, m, s, x, y;
	sc3(n,m,s);
	bool ok  = 0;
	int p = 0;
	fr(i,0,s){
		sc2(x,y);
		grid[x][y] = 1;
		if(check(x,y)) {
			if(!ok){
				p = i+1;
				ok = 1;
			}
		}
	}
	if(!ok) p = 0;
	
	printf("%d\n", p);
	
	
	return 0;
}

