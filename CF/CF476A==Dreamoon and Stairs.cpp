#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=a; i < b; i++)
#define pf(a) printf("%d ", a);
#define mp(a,b) make_pair(a,b)
#define pv(v) for(int i=0; i < v.size(); i++) { pf(v[i]); if(i==v.size() -1 ){ _; } }
#define pb(a) push_back(a)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define inf 0x3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int lld;

int n, m;
int ra, rb;
bool f(){
	int i = n/2;
	int j = 0, k;
	while( i >= 0 ) {
		j = n-2*i;
	//	pf(i) pf(j) _;
		if( (i+j)%m == 0   )  {
			ra = i; rb=j;
			return 1;
		}
		i--; j+=2;
	} 
	ra=rb=-1;
	return 0;
}

int main (int argc, char const* argv[]) {
	sc2(n,m);
	f();
	ra+=rb;
	if(ra < 0 ) ra=-1;
	printf("%d\n", ra);
	return 0;
}
		
		
	
