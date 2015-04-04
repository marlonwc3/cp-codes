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
#define EPS 1e-5
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

ii arr[100];
int m, s;
int pd[1000][1000];
int bt(ll s1, ll s2){
	ll ts = s1*s1 + s2*s2 ;
	if(s1*s1 > s || s2*s2 > s || ts > s ) 	{
		return inf;
	}
	if( s1*s1 + s2*s2 == s ) return 0;
	if(pd[s1][s2] != -1 )return pd[s1][s2];
	int r = inf;	
	fr(i,0,m){
		r = min( r,   1+ bt(s1+arr[i].st, s2+arr[i].nd  )    );
	}
	return pd[s1][s2] = r;
}

int main (int argc, char const* argv[]) {
	int n, a,b;
	sc1(n);
	int r;
	while(n--){
		sc2(m,s); s*=s;
		mst(pd, -1);		
		fr(i,0,m){
			sc2(a,b);
			arr[i] = mp(a,b);
		}
		r = bt(0, 0);
		if( r<  0 || r>= inf ) printf("not possible\n");
		else printf("%d\n", r);
		
	}	


	return 0;
}

