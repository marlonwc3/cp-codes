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

const int des[4][2] ={{0,1}, {0,-1},{1,0}, {-1,0}  };
int grid[105][105];
int N;
bool valpos(int x,int y){
	if( x < 0 || x >= N || y < 0 || y>= N) return 0;
	return 1;
}

bool val(int x,int y, int k){
	if(!valpos(x,y)) return 0;
	int dx,dy;
	fr(i,0,4){
		dx = x + des[i][0]; dy = y + des[i][1];
		if(!valpos(dx,dy)) continue;
		if(grid[dx][dy] != 0 && grid[dx][dy] != k ) return 0;
	}
	return 1;
}

void go(int x, int y, int k ){
	grid[x][y] = k;
	int dx,dy;
	fr(i,0,4){
		dx = x  + des[i][0], dy = y + des[i][1];

		if(!val(dx,dy,k)) continue;
		if(grid[dx][dy] != 0) continue;		
		go(dx,dy,k);
	}
}




void pf(){

	fr(i,0,N){
		fr(j,0,N) printf("%d ", grid[i][j]);
		_
	}
	
}
int main (int argc, char const* argv[]){
	int K;
	int NEXT = 1;
	
	sc2(N,K);
	fr(i,0,N){
		fr(j,0,N){
			grid[i][j] = 0;
		}
	}
	fr(i,0,N){
		fr(j,0,N){
		if(NEXT > K ) goto label;
			if(val(i,j, NEXT) ){
				grid[i][j] = NEXT++;
			}
		
			if(NEXT > K ) goto label;
		}
	}
	label:;
	if( NEXT <= K) printf("NO\n");
	else{ 
		printf("YES\n");

	//pf();
	fr(i,0,N){
		fr(j,0,N){
			
			if(grid[i][j] != 0 ){
			//printf("call %d %d k: %d \n", i, j, grid[i][j]);
			 go(i,j, grid[i][j]);
			 }

		}
	}
	//_
	//pf();
		
		fr(i,0,N){
			fr(j,0,N){
				if(grid[i][j] == 0 ) printf("S");
				else printf("L");
		
			}
			_
		}
	
	}
	
	
	
	
	return 0;
}





