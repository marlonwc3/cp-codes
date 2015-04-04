#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
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

//si s;

vii v;

int main (int argc, char const* argv[]) {
	int n, a,b;
	sc1(n);
	fr(i,0,n){
		sc2(a,b);
		v.pb(mp(a,b));
	}
	sort(v.begin(), v.end());
	a = 0;
	
	fr(i,0,n){
		if( v[i].second >= a ) a = v[i].second;
		else a=v[i].first;
	}
	
	printf("%d\n", a);
	
	return 0;
}
