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

int des[8][2] = {
	{1,0}, {-1,0}, {0,1},{0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}
};

int m[1030][1030];
bool val(int x, int y){  return (x < 0 || x > 1024  || y < 0 || y > 1024 ) ? 0 : 1; }
int mx, my, d, add;



int main (int argc, char const* argv[]) {
	int t, n;
	sc1(t);
	while(t--){
		mst(m,0);
		sc1(d); sc1(n);
		fr(i,0,n){
			sc3(mx, my, add);
			for(int j = mx - d; j<= mx+d; j++){
				for(int k = my -d ; k<=my+d; k++){
					if(!val(j,k)) continue; 
					m[j][k]+=add;
				}
			}			
		}

		int px=0, py=0, cnt=0;
		fr(i,0,1025){
			fr(j,0,1025){
				if(m[i][j] > cnt ) {
					cnt = m[i][j];
					px = i; py = j;
				}
			}
		}
		printf("%d %d %d\n", px, py , cnt);
	}
	return 0;
}





















