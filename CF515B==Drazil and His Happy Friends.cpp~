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

bool hm[105], hf[105];

int main (int argc, char const* argv[]) {
	int n,m, a, b, g, k;
	int total = 0, thappy=0;
	sc2(n,m);
	total += (n+m);
	sc1(b);
	thappy += b;
	fr(i,0,b){
		sc1(k);
		hm[k]=1;
	}
	sc1(g);
	thappy += g;
	fr(i,0,g){
		sc1(k);
		hf[k]=1;
	}
	
	//printf("total %d th %d\n", total, thappy);
	int i =0;
	while ( i < 1000000 && thappy < total){
		a = i%n;
		b = i%m;
		if( (!hm[a] && hf[b]) ){
			hm[a]=1;
			thappy++;
		}
		else if(hm[a] && !hf[b])		{
			hf[b] = 1;
			thappy++;
		}
		i++;
	}
	
	if( thappy >= total ) printf("Yes\n");
	else printf("No\n");
	
	
	
	
	
	
	
	
	return 0;
}



