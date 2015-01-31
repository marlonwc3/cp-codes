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

int m, t, r, k;
vi v;
int cnt[1000];
bool mark[5000];
int off = 500;
int main (int argc, char const* argv[]) {
	sc3(m, t, r);
	fr(i,0,m){
		sc1(k);
		v.pb(k);
	}
	bool ok = 1;
	ll sum  =0;
	fr(i,0,v.size() ) {
		if( cnt[i] >= r )  continue;
		int p = v[i] - 1;
		while( mark[p+off] ) p--;		
		while( cnt[i] < r ) {
		
			if( p +1 + t < v[i] +1 ) { ok =0; goto fim;}
			mark[p+off] = 1;
			
			
			fr(j,i+1, v.size() ) {
			if( p + 1 + t < v[j] +1 ) {break;}				
				cnt[j]++;
			}	
			sum++;
			p--;
			while( mark[p+off] ) p--;
			cnt[i]++;
		}
	
	}
	fim:;
	
	if(!ok) printf("-1\n");
	else printf("%I64d\n", sum);
	
	
	
	return 0;
}

