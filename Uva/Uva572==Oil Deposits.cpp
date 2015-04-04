#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
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
 
 
int des[8][2] = {
	{0,1}, {0,-1}, {1,0},{-1,0},{1,1}, {-1,-1}, {-1,1 }, {1, -1}
}; 

int n,m;
bool val(int x, int y){
	if(x < 0 || x >= n || y < 0  || y >= m ) return 0;
	return 1;
}

char matrix[305][305];
char next;
void ff(int i, int j){
	if(matrix[i][j]!='@') return;
	matrix[i][j] = next;
	int dx, dy; 
	fr(k,0,8){
		dx = i + des[k][0];
		dy = j + des[k][1];
		if(!val(dx , dy)) continue;
		ff(dx, dy);
	}
} 
 
int foo(){
	int res = 0; 
	next = 'A'-1;
	
	fr(i,0,n){
		fr(j,0,m){
			if(matrix[i][j]=='@'){
				res++;
				next++;
				ff(i,j);
			}
		}
	}

	return res;
}
 
int main (int argc, char const* argv[]) {
	int res;
	while(1){
		sc2(n,m);
		if(!n && !m) break;
		fr(i,0,n){
			scanf("%s", matrix[i]);
		}
		res = foo();
		printf("%d\n", res);
	}
	
	
	return 0;
}




