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
#define EPS 1e-9
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

int LOL = 17;
vll mem[20][20];

void bt(int p, ll sum, ll pt){
	if(p > LOL ) return;
	for(ll i = 2, j=1; i <= (1LL<<17) && i <= sum; i<<=1, j++ ){
		if( sum%i == 0 ){
			mem[j][p].pb(sum);
		}
	}
	bt(p+1, sum + 1*pt, pt*10 );
	bt(p+1, sum + 2*pt, pt*10);

}


int main(int argc, char const *argv[]){
	bt(0, 2, 10);
	int caso, p, q, s;
	fe(i,1,17){
		fe(j,1,17){
			sort(mem[i][j].begin(), mem[i][j].end());
		}
	}


	sc1(caso);
	fe(t,1,caso){
		sc2(p,q);
		p--;

		s = mem[q][p].size();
		if(!s){ printf("Case %d: impossible\n", t);}
		else if(s==1){
			printf("Case %d: %lld\n", t, mem[q][p][0]);
		}
		else{
			ll r1 = mem[q][p][0];
			ll r2 = mem[q][p][s-1];
			printf("Case %d: %lld %lld\n",t, r1, r2 );
		}
	}


	return 0;
}
