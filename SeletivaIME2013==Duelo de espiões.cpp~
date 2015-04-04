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

int cmp(double a, double b =0.0 ){
	if(fabs(a-b) <= EPS ) return 0;
	return (a>b)?1:-1;
}

int na, nb;
double pd_chance[2][20][40];
int atack[2][20];

vi dados;
void bt(int p, int n, bool turn, int sum, double pb){
	//printf("p %d |n %d | turn %d | sum %d | pb %lf \n", p, n, turn, sum, pb);
	if( p >= dados.size() ) {
		pd_chance[turn][n][sum] += pb;	
		return;
	}
	int d = dados[p];
	fe(i,1,d){
		bt(p+1, n, turn, sum+i, pb*(1.0/d) );
	}
}

int PASSO=1;
double pd[305][305][2];
int pd_ok[305][305][2];


double go(int h1, int h2, bool turn){
	//printf("h1 %d | h2 %d | turn %d\n", h1, h2, turn);
	if( h2 <= 0 ){ return turn ? 1.0 : 0.0;  }	
	if( h1 <= 0 ){ return turn ? 0.0 : 1.0;  }
	if( pd_ok[h1][h2][turn] == PASSO ) return pd[h1][h2][turn];
	
	int n = turn ? na : nb;
	double r = 0, r2;
	
	
	//printf("n: %d\n", n);
	fe(i,0,n){
		r2 = 0;
		//printf("atack turn %d | i %d | %d\n", turn, i, atack[turn][i] );
		fe(j,1, atack[turn][i] ) {
			if(turn) r2 += pd_chance[turn][i][j]*( 1 - go(h1, h2 - j, !turn) );
			else r2 += pd_chance[turn][i][j]*( 1 - go(h1 - j, h2, !turn) );
		}
		r = max(r, r2);
	}
	pd_ok[h1][h2][turn] = PASSO;
	pd[h1][h2][turn] = r;
	return r;
}


int main (int argc, char const* argv[]) {
	int h1, h2, a, b, k;
	double r;
	while( sc4(h1, h2, na, nb) ==4  ) {
		fr(i,0,2){
			fe(j,0,15) {
				fe(k,0,39){ pd_chance[i][j][k]=0.0; }
				atack[i][j]=0;
			}
		}
		//printf("Oi 2\n");
	
		int sum;
		fr(i,0,na){
			sc1(k);
			dados.clear();
			sum = 0;
			fr(j,0,k){
				sc1(a);
				dados.pb(a);
				sum += a;
			}
			atack[1][i] = sum;
//			printf("i: %d ");
			bt(0, i, 1, 0, 1.0);
		}
		fr(i,0,nb){
			sc1(k);
			dados.clear();
			sum = 0;
			fr(j,0,k){
				sc1(a);
				dados.pb(a);	
				sum += a;
			}
			atack[0][i] = sum;			
			bt(0, i, 0, 0, 1.0);
		}	
				
		//printf("Oi\n");
		r = go(h1, h2, 1);
		printf("%.3lf\n", r);
	
		PASSO++;
	
	
	}
	
	
	return 0;
}




















