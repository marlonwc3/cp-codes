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


vii e[1005];
int dist[1005];
int n,m;

bool bford(){ // return true if there is a negative cycle
	int s, a, w;
	fr(i,0,n) dist[i]=inf;
	dist[0] =0;
	fr(i,0,n-1){
		fr(j,0,n){
			s = e[j].size();
			fr(k,0,s){
				a = e[j][k].st, w = e[j][k].nd;
				dist[a] = min(dist[a], dist[j]+w);	
			}
		}
	}
	bool ok =0;
	fr(j,0,n){
		s = e[j].size();
		fr(k,0,s){
			a = e[j][k].st, w = e[j][k].nd;
			if(dist[a] > dist[j]+w ){
				ok = 1; break;
			}
		}
	}	
	return ok;
}

int main (int argc, char const* argv[]) {
	int t, a,b,c;
	bool ok;
	sc1(t);
	while(t--){
		sc2(n,m);
		fr(i,0,n) e[i].clear();
		fr(i,0,m){
			sc3(a,b,c);
			e[a].pb(mp(b,c));
		}
		ok = bford();
		if(ok) printf("possible\n");
		else printf("not possible\n");
		
	
	}
	
	
	return 0;
}












