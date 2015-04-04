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
typedef pair<lld, lld> lii;


lii f(lld xi, lld n){
	lld k=1;
	while( n > k*k ) k+=2; xi++;
	lld d = k-1, dif;
	k*=k;
	dif= fabs(n - k);
	if(n== k) return mp(xi,xi);
	if(dif <=  d) return mp(xi-dif, xi);
	else if(dif <= 2*d) return mp(xi-d, xi -  ( dif-d)  );
	else if(dif <= 3*d) return mp(xi - 3*d + dif , xi - d );
	else  return mp(xi, xi - (4*d - dif) );
}

int main (int argc, char const* argv[]){
	int sz, p;
	lii res;
	while(1){
		sc2(sz, p);
		if(!sz && !p) break;
		sz = ceil(sz/2.0);
		res = f(sz, p);
		printf("Line = %lld, column = %lld.\n", res.first, res.second);

	}
	return 0;
}




