#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
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

vi e[200];
int cores[200];
bool mark[200];
bool dfs(int no){
	int s = e[no].size(), cor = cores[no], adj;
	mark[no]=1;
	bool ok =1;
	bool my=0;
	fr(i,0,s){
		adj = e[no][i];
		if(cores[adj]==0){
			cores[adj] = cor==2 ? 1: 2;
		}
		if ((cor==2 && cores[adj]==1) || (cor==1 && cores[adj]==2)) {
			my =1;
		}
		if(!mark[adj]) ok=ok&&dfs(adj);
	}
	return ok&&my;
}

int main (int argc, char const* argv[]) {
	
	int n, k, a;
	sc1(n);
	fr(i,1,n+1){
		while(1){
			sc1(k); iz(k);
			e[i].pb(k);
		}
	}
	bool ok=1;
	vi v;
	fr(i,1,n+1){
		if(!mark[i]){
			cores[i]=1;
			ok = ok && dfs(i);
		}
		if(cores[i]==1) v.pb(i);
	}
	if(ok){
		int s = v.size();
		printf("%d\n", s);
		fr(i,0,s) {
			printf("%d", v[i]);
			if(i!=s-1) printf(" ");
		}
		_
	}
	else printf("0\n");
	
	return 0;
}











