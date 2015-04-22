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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
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


vii e[100];
vector<vi> res;
const int LIMIT  = (1<<16)-1;
vi v;
void go(int no, int mask){
	v.pb(no);
//	printf("no: %d | mask: %d | full: %d \n", no, mask, (1<<17)-1 );
	if(mask ==LIMIT ) { res.pb(v);  goto label;}
//printf("oi\n");
	int adj, pj;
	fr(i,0,e[no].size()){
//		printf("st: %d | nd: %d\n", e[no][i].st, e[no][i].nd) ;
		if(mask & ( 1<<e[no][i].nd ) ) continue;
		adj = e[no][i].st;
		fr(j,0,e[adj].size()) if(e[adj][j].st == no ) { pj = j; break; }
	//	printf("adj: %d | pj: %d \n", adj, pj);
		mask |= ( 1<<e[no][i].nd );
		mask |= ( 1<<e[adj][pj].nd);
		
		go(adj, mask);
				
		
		mask &= ~( 1<<e[no][i].nd );
		mask &= ~( 1<<e[adj][pj].nd);		
		
	
	}
	label:;
	v.pop_back();
}

int main (int argc, char const* argv[]){
//	int k = (1<<16)-1;
	//printf("k: %d\n", k );
	e[1].pb(mp(2,0));
	e[1].pb(mp(5,1));
	e[1].pb(mp(3,2));
	
	e[2].pb(mp(1,3));
	e[2].pb(mp(3,4));
	e[2].pb(mp(5,5));	

	e[3].pb(mp(4,6));
	e[3].pb(mp(5,7));
	e[3].pb(mp(2,8));	
	e[3].pb(mp(1,9));		
	
	e[4].pb(mp(3,10));
	e[4].pb(mp(5,11));
	
	e[5].pb(mp(3,12));
	e[5].pb(mp(1,13));
	e[5].pb(mp(2,14));	
	e[5].pb(mp(4,15));	
	go(1, 0);
	
	sort(res.begin(), res.end());
	
	
	fr(i,0,res.size()){
		fr(j,0,res[i].size()) printf("%d", res[i][j]);
		_
	}
	
	
	
	return 0;
}












