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
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef set<int> si;



int main (int argc, char const* argv[]) {
	int t, w, a, b, d;
	bool ok;
	sc1(t);
	while(t--){
		sc1(w);
		ok = 1; d=inf;
		while(w--){
			sc2(a,b);
			if(d==inf) d = fabs(a-b);
			else {
				if(d != fabs(a-b)  ) ok = 0;
			}
		}
		
		if(ok) printf("yes\n");
		else printf("no\n");

		if(t >0  ) _
	}
	
	

	
	return 0;
}











