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

vii e[105];
bool mark[105];
int lol;
si myset;
bool dfs(int no, int fim, int pai){
	if(no==fim) return 1;
	mark[no]=1;
	int s = e[no].size(), adj , cor;
	fr(i,0,s){
		adj = e[no][i].st, cor =e[no][i].nd;
		
		if(cor != lol ) continue;
		//printf("%d --> %d | %d | lol: %d \n",no, adj, cor, lol );
		if(mark[adj] ) continue;
		if(dfs(adj, fim, no) ) {
			//printf("ent\n");
			return 1;
		}
	}
	return 0;
}	

int n,m, a, b, c;
si todas;
int main(int argc, char const *argv[]) {
	sc2(n,m);
	fr(i,0,m){
		sc3(a,b,c);
		e[a].pb(mp(b,c));
		e[b].pb(mp(a,c));
		todas.insert(c);
	}


	int q, cnt;
	sc1(q);
	while(q--){
		sc2(a,b);
		myset.clear();

		cnt = 0;
		for(si::iterator it = todas.begin(); it!=todas.end(); it++){
			lol = *it;
					mst(mark,0);
			//printf("lol: %d\n", lol);
			if( dfs(a,b,-1) ){
				cnt++;
			}	
		}

		printf("%d\n", cnt);
	}
	return 0;
}
