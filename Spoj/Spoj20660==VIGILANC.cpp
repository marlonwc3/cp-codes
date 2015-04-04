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


ll acc[1000005];


ll get(int a, int b){
	return acc[b] - acc[a-1];
}

struct cam {
	int a, b; ll w;
	cam(){}
	cam(int _a, int _b, ll _w){ a=_a, b=_b, w=_w;}
	bool operator < (const cam &c) const{ 
		if(a==c.a) return b < c.b;
		return a < c.a;
	}
};

vector<cam> v;
int n, c;
ll pd[6*1005][1005];
ll go(int p, int m){
	if( m >= n) return 0;
	if( p >= c) return linf;
	if( pd[p][m] != -1) return pd[p][m];
	int a = v[p].a, b = v[p].b; ll w = v[p].w;
	// (a,b) é o intervalo,  w é o custo
	if( (a - m) >=2  ) return linf;
	ll res = min(  go(p+1, m) , w + go(p+1, max(m, b)  )   );
	return pd[p][m] = res;
}

int main(int argc, char const *argv[]) {
	int m;
	mst(pd, -1);
	sc3(n,m,c);
	int a, b, x ,y;
	sc1(acc[1]);
	fe(i,2,m){ sc1(acc[i]); acc[i]+=acc[i-1]; }
	fr(i,0,c){
		sc4(a,b,x,y);
		v.pb(cam(a,b,get(x,y)));
	}
	sort(v.begin(), v.end());
	//fr(i,0,c) printf("%d %d %lld\n", v[i].a, v[i].b, v[i].w);

	ll res = go(0,0);
	if( res < 0  || res >= linf ) printf("impossivel\n");
	else printf("%lld\n", res);




	return 0;
}
