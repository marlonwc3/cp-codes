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


vi e[13];

bool isprime(int k){
	if( k <= 1 ) return 0;
	if( k==2 ) return 1;
	int p = 2;
	while( p*p <= k ){ if(k%p == 0 ) return 0; p++; } 
	return 1;
}
bool mycmp(int a, int b){
	return a > b;
}

int main (int argc, char const* argv[]) {
	e[4].pb(2);
	e[4].pb(2);
	e[4].pb(3);
	e[6].pb(3);
	e[6].pb(5);
	e[8].pb(2);
	e[8].pb(2);
	e[8].pb(2);
	e[8].pb(7);
	e[9].pb(3);
	e[9].pb(3);
	e[9].pb(2);
	e[9].pb(7);
	int n, k;
	sc1(n);
	vi res;
	while(n--){
		scanf("%1d", &k);
		//printf("k %d\n", k);
		if(k<=1) continue;
		if(isprime(k)) res.pb(k);
		else {
			//printf("k: %d | sze %d\n", k, e[k].size() );
			fr(i,0,e[k].size()){
				//printf("alo\n");
				res.pb(e[k][i]);
			}
		}

	}
	//printf("oi \n");
	sort(res.begin(), res.end(), mycmp);
	fr(i,0,res.size()){
		printf("%d", res[i]);
	}
	_
	
	return 0;
}




