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

ll memo[10005];


int main (int argc, char const* argv[]) {
	memo[1] = 1;
	int p  = 2;
	int i = 1;
	int aux;
	while ( 1 ) {	
		aux = i;
		if(i >= 10005  ) goto fim;	
//		printf("i: %d | aux : %d\n", i, aux);
		while( i - aux <= p ){
			if(i != aux ) memo[i] = memo[i-1] + p;	
			i++;
	//		printf("i: %d\n", i);
			if(i >= 10005  ) goto fim;
		}
		i--;
		p++;
	}
	fim:;
	//fr(i,0,10) printf("%lld ", memo[i] );
//	_
//	printf("em 1000 %lld\n", memo[10000] );
	
	int a;
	while( 1 ) {
		sc1(a); iz(a);
		printf("%d %lld\n", a, memo[a]);	
	}
	
		
	return 0;
}










