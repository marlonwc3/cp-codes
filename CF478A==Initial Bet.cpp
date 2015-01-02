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


int main (int argc, char const* argv[]) {
	int sum=0, a;
	fr(i,0,5){
		sc1(a);
		sum+=a;
	}
	
	if(sum && sum%5 == 0 ) {
		sum/=5;
		printf("%d\n", sum);
	}
	else printf("-1\n");
	







	return 0;
}
