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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
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

int m, w, c;

long double cmb[105][105];

int main (int argc, char const* argv[]) {
	fe(i,0,100){
		cmb[i][0] = 1;
	}
	fe(i,1,100){
		fe(j,1,i){
			cmb[i][j] = cmb[i-1][j] + cmb[i-1][j-1];
		}
	}
	while( 1 ) {
		sc3(m, w, c);
		if(!m && !w ) break;  
		double pm = (m+0.0)/(m+w);
		double pw = 1 - pm;
		double r = 0.0;
		for(int i=0 ; i <= c ; i +=2){
			r += cmb[c][i]*pow(pm, i)*pow(pw, c - i);
		}
		printf("%.7lf\n", r);
	
	}

	
	
	
	return 0;
}















