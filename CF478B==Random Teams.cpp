#include <bits/stdc++.h>
#define _ printf("\n");
#define pf(a) printf("%d ", a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define sc1(a) scanf("%d", &a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define pvi(v) fr(i, 0, v.size()) { pf(v[i]) if(i==v.size() -1 ){_} }
#define pcf(c, a) printf("%c %d ", c, a);
#define mst(a,b) memset(a, b, sizeof a)
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int lld;

lld cmb(lld n){
	if(n<2) return 0;
	return (n*(n-1))/2;
}




int main (int argc, char const* argv[]) {
	
	lld a, b, q, r=0, novo=0, menor = 0;
	scanf("%I64d %I64d", &a, &b);
	

	lld maior = cmb( a-(b-1)  ); 
	
	
	
	q  = a/b; // tem b de q
	r = a%b; // sobraram r
	lld c = b - r; // tem exatamente c com valor q

	menor = c*cmb(q);

	
	q++;

	menor += r*cmb(q);

	
	printf("%I64d %I64d\n", menor, maior);

	
	
	
	return 0;
}
