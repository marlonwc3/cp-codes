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

int matrix[100][100];
int col[100];
map< ii, int> mymap;
int main (int argc, char const* argv[]) {
	int n,m;
	bool ok;
	int t;
	sc1(t);
	while( t-- ) {
		mst(col, 0);
		sc2(n,m);
		mymap.clear();
		ok = 1;
		fr(i,0,n){
			fr(j,0,m){
				sc1(matrix[i][j]);
				if(matrix[i][j]){
					col[j]++;
				}
			}
		}
		fr(i,0,m){
			if(col[i]!=2) {ok = 0; break;}
		}	
		if(ok) for(int i = 0; i < m; i++){
			int p1=-1, p2=-1;
			for(int j = 0; j < n; j++){
				if(matrix[j][i]){
					if(p1 == -1 ) p1 = j;
					else p2 = j;
				}
			}
			if(mymap[mp(p1,p2)] || mymap[mp(p2,p1)] ) ok = 0;
			mymap[mp(p1,p2)] = mymap[mp(p2,p1)] = 1;
			
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}




