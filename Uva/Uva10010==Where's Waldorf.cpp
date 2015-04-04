
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
bool cmp(int a, int b) { return a>b;}

char matrix[60][60];
 int n,m, len;

int des[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
char str[60];

bool val(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y>=m) return 0;
	return 1;
}

bool foo(int i, int j, int k){ // try to find str in m
	int dx = i, dy = j; int d = 0;
	//printf("i-> %d j %d k %d len %d\n", i, j, k, len);
	while ( d < len ) {
		if (!val(dx,dy) ) {return 0; }
		if ( matrix[dx][dy] != str[d] && (matrix[dx][dy]+32) != str[d] &&  (matrix[dx][dy]-32) != str[d]   ) return 0;
		dx+= des[k][0]; 
		dy+= des[k][1];	
		d++; 
	}
	//printf("encontrou\n");
	return 1;
}


ii solve(){
	bool ok;
	fr(i,0,n){
		fr(j,0,m){
			fr(k,0,8){
				if( foo(i,j,k) ) {
				 
					//printf("em %d %d\n", i, j); 
					
					return mp(i+1,j+1); 
				}
			}
		}
	}
}




int main (int argc, char const* argv[]) {
	int t , k;
	bool f = 1;
	sc1(t);
	ii res = mp(-1, -1);
	while(t--){
		if(!f) _
		sc2(n,m);
		fr(i,0,n){
			scanf("%s", matrix[i]);
		}
		sc1(k);
		while(k--){
			scanf("%s", str);
			len = strlen(str);
			res = solve();
			printf("%d %d\n", res.st, res.nd);
		}
		f = 0;
	}

	
	return 0;
}



















