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

vi compo[100005];
int mark[100005], X;
int PASSO = 1;
vii e[100005];
void dfs(int no, int c){
	//printf("no: %d | c: %d\n", no, c);
	mark[no] = PASSO;
	compo[c].pb(no);
	fr(i,0,e[no].size()){
		if(e[no][i].nd > X || mark[e[no][i].st] == PASSO) continue;
		dfs(e[no][i].st, c);	
	}
} 




int next_compo = 0;

int main (int argc, char const* argv[]) {
	int caso, n, m;
	int a ,b , c;
	sc1(caso);
	fe(t,1,caso){
		next_compo=0;
		sc1(n);
		fe(i,0,n) {e[i].clear(); compo[i].clear(); }
		fr(i,1,n){
			sc3(a,b,c);
			e[a].pb(mp(b,c));
			e[b].pb(mp(a,c));
		}
		sc1(X);
		
		fe(i,1,n){
			if(mark[i] != PASSO) {
			//	printf("call %d\n", i);
				dfs(i, next_compo);
				next_compo++;
			}
		}
//		printf("compo %d\n", next_compo);
		ll r = 0, s;
		fr(i,0,next_compo){
			s = compo[i].size();
			r += ((s+1)*s)/2;
		}
		printf("Caso #%d: %lld\n", t, r);
			



	
		PASSO++;	
	}
	
	
	
	
	return 0;
}






