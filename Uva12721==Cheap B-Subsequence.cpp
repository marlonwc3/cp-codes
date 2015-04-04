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
char str[1000];
vector< pair<ll,ll> >  e[50];
int b, len;

ll pd[150][150];

ll bt(int p, int k){ // k é quantos b's
	//printf("p: %d |k: %d\n", p, k);
	if(k>=b) return 0;
	if( p>=len ) return linf;
	if(pd[p][k] != -1) return pd[p][k];
	int ch = str[p]-'a', s;
	//printf("ch: %d | %c\n", p, str[p]);
	s = e[ch].size();
	ll w = 0;
	for(int i = s-1; i>=0; i--){
		if( ((k+1) % e[ch][i].st) == 0  ){
			w += ((k+1)/e[ch][i].st)*e[ch][i].nd;
		}
	}

	ll res = min(bt(p+1, k), w + bt(p+1, k+1)  );
	//printf("DE [p: %d |k: %d] -> w:%lld |res %lld \n", p, k, w, res);
	return pd[p][k] = res;
}


int main(int argc, char const *argv[]) {
	int caso, q, x, y;
	sc1(caso);
	ll res;
	fe(t,1,caso){
		fe(i,0,30) e[i].clear();
		scanf("%s %d", str, &b);
		fe(i,'a'-'a', 'z'-'a'){
			sc1(q);
			while(q--){ sc2(x,y);  e[i].pb(mp(x,y));}
		}
		len = strlen(str);
		mst(pd, -1);
		res = bt(0,0);
		printf("Case #%d: %lld\n", t, res);

	}


	return 0;
}
