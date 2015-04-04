#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b)  if(!b) {break;}
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a,b) memset(a, b, sizeof (a))
#define fr(i,a,b) for(int i = (a); i < (b); i++)
#define fe(i,a,b) for(int i = (a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a,i) for(int i =0; i < (a.size()); i++ ) { printf("%d ", a[i]); if(i != a.size() -1) printf(" "); }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;




int main (int argc, char const* argv[]) {
	int t;
	sc1(t);
	int n, k;
	vll v;
	while(t--) {
		sc1(n);
		v.clear();
		fr(i,0,n){
			sc1(k);
			v.pb(k);
		}
		ll sum = 0, aux;
		int cnt = 0;
		fr(i,0,n){
			 k = v[i];
			 aux = sum+k;
			 //printf("k: %d | aux: %lld\n", k ,aux);
			 bool ok = 1;
			 
			 fr(j,i+1, n){
			 //printf("vj: %lld\n", v[j] );
			 	if(v[j] <= aux) {ok = 0; break;}
			 }
			 if(ok){
			 	cnt++;
			 	sum = aux;
			 }
		}
		printf("%d\n", cnt);
		
	}

	
	return 0;
}
