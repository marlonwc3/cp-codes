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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

double fe[505];
int n,k;
double pjump[20];
bool  mark[505];
double mem[505];

double go(int p){
	if ( p >= n ) return 0;
	if(mark[p]) return mem[p];
	
	double res = fe[p];
	//printf("p: %d | %lf \n", p, res);	
	fe(i,1,k){
		//printf("jump %d -> %lf\n",i,  pjump[i] );
		double c =  pjump[i]*go(p+i);
		//printf("De c: %lf\n", c);
		res += c;
	}
//	printf("ret %lf\n", res);
	mark[p]=1;
	return mem[p] = res;
}


int main (int argc, char const* argv[]) {
	int caso, q;
	double a,b;
	sc1(caso);
	fe(t,1,caso){
		sc2(n,k);
		fe(i,1,k) scanf("%lf", &pjump[i]);
		mst(mark, 0);
		fr(i,0,n){
			sc1(q);
			double sum=0;
			fr(j,0,q){
				scanf("%lf %lf", &a, &b);
				sum += a*b;
			}
			fe[i]=sum;
			//printf("fe %d -> %lf\n", i, fe[i] );
		}
		a = go(0);
		printf("Case #%d: %.6lf\n",t, a);
	
	
	
	}
	
	
	return 0;
}















