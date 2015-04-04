#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
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
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii; 
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;
int cmp(double a, double b){ 
	if(fabs(a-b) <= EPS) return 0; 
	return (a>b) ?1 :-1; }
	
int m;
bool mycmp(int a, int b){
	int ma = a%m, mb = b%m;
	if ( ma < mb ) return 1;
	if ( mb < ma ) return 0;
	if( a%2 && !(b%2) ) return 1;
	if( !(a%2) && b%2 ) return 0;
	if( a%2 && b%2 ) return a>b;
	return a<b;
}

vi v;
int main (int argc, char const* argv[]){
	int n, k; int w=20;
	while(w--){
		sc2(n,m);
		v.clear();
		fr(i,0,n){
			sc1(k); v.pb(k);
		}
		sort(v.begin(), v.end(), mycmp);
		printf("%d %d\n", n, m);
		fr(i,0,n){
			printf("%d\n", v[i]);
		}
		
//		break;
	}
	
	printf("0 0\n");
	
		
	return 0;
}

