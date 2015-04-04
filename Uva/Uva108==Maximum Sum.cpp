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
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define MAX_N 120
int n, grid[MAX_N + 10][MAX_N + 10], arr[MAX_N +10][MAX_N+10];

void go (){ 
	
	

}











int main (int argc, char *argv[]) {

	while( sc1(n) ==1 ) {
	fr(i,0,n){
		fr(j,0,n){
			sc1(arr[i][j]);
			if(i > 0 ) arr[i][j] += arr[i-1][j];
			if( j> 0 ) arr[i][j] += arr[i][j-1];
			if( i > 0 &&j > 0) arr[i][j] -= arr[i-1][j-1];
		}
	}
	
	int r = -inf;
	fr(i,0,n){
		fr(j,0,n){
			fr(l,i,n){
				fr(k,j,n){
					int sub = arr[l][k];
					if ( i > 0 ) sub -= arr[i-1][k];
					if( j > 0 ) sub -= arr[l][j-1];
					if( i> 0 && j > 0 ) sub += arr[i-1][j-1];
					r = max(r, sub);
				}
			
			}
		
		}
	
	}
	printf("%d\n", r);
	
	}	

	
	return 0;
}
















