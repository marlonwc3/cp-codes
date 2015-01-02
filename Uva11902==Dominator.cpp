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
typedef pair<char, int> ci;

vi e[110];
int n;
bool mark[110];
bool mark2[110];
bool mark3[110];
void dfs(int no){
	if(mark2[no]) return;
	mark[no]=1;
	int s = e[no].size();
	fr(i,0,s){
		if(!mark[ e[no][i] ] ){
			dfs(e[no][i]);
		}
	}
}

void pline(){
	printf("+");
	fr(i,0,(2*n)-1 ) printf("-");
	printf("+\n");
}

int main (int argc, char const* argv[]) {
	int caso, k;
	sc1(caso); caso++;
	fr(t,1,caso){
		sc1(n);
		fr(i,0,n+3) e[i].clear();
		
		
		fr(i,0,n){
			fr(j,0,n){
				sc1(k);
				if(k) e[i].pb(j);
			}
		}
		mst(mark, 0);
		mst(mark3, 0);
		dfs(0);
		fr(i,0,n) mark3[i]=mark[i];
		printf("Case %d:\n", t);
		fr(i,0,n){
			mst(mark, 0);
			mark2[i]=1;
			dfs(0);
			pline();
			fr(j,0,n){
				if(!mark[j] && mark3[j]) printf("|Y");
				else printf("|N");
			}
			printf("|\n");
			if(i==n-1) pline();
			mark2[i]=0;
				
		}
		
		
	}
	
	
	return 0;
}








