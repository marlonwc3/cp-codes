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
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

int num[430], low[430], pai[430], mark[420];
int root, rootCont, PASSO=0;
vi e[420];
int res[420], next;
int dfsCounter;
void dfs(int no){
	low[no]=num[no] = dfsCounter++;
	mark[no] = PASSO;
	int s  = e[no].size(), adj;
	bool in=0;
	fr(i,0,s){
		adj = e[no][i];
		if(mark[adj] != PASSO){
			if(no == root ) rootCont++;
			pai[adj] = no;
			dfs(adj);
			if(no != root && low[adj] >= num[no]){
				if(!in){res[next++]=no; in=1; }
			}
			low[no] = min(low[no], low[adj]);
		}
		else if(adj != pai[no]){
			low[no] = min(low[no], num[adj]);
		}
	}
}

int main (int argc, char const* argv[]) {
	int n, m, a, b;
	int t = 0;
	while(1){
		sc2(n,m); if(!n && !m) break;
		t++;
		PASSO++;
		next =0;
		dfsCounter = 1;
		fe(i,0,n+2) {
			e[i].clear(); 
			pai[i]=-1;
		}
		fr(i,0,m){
			sc2(a,b);
			e[a].pb(b);
			e[b].pb(a);
		}
		fe(i,1,n){
			if(mark[i] != PASSO){
				root = i; rootCont = 0;	
				dfs(i);
				if(rootCont >= 2 ) res[next++]=i;
			}	
		}
		printf("Teste %d\n", t);
		if(!next) printf("nenhum\n");
		else {
			sort(res, res+next);
			printf("%d", res[0]);
			fr(i,1,next) { printf(" %d", res[i] ); }
			_
		}
		_
	}
	
	return 0;
}


















