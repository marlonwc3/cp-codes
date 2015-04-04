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



int rep[100205];
int init(int n){fe(i,0,n) rep[i]=i; }
int find(int a){ return rep[a] = (rep[a]==a)?a:find(rep[a]); }
void uni(int a, int b) { 
	rep[find(a)] = find(b);
}
bool iss(int a, int b) { return find(a)==find(b); }

int main (int argc, char const* argv[]) {
	int n,m;
	while(1){
		sc2(n,m);
		if(!n && !m ) break;
		init(n+m+1);
		int k = 0;
		fr(i,0,n){
			sc1(k);
			fr(j,0,k){
				int w;
				sc1(w);
				w += n;
				uni(i,w);
			}
		}
		
		bool ok = 1;
		fr(i,0,n){
			ok = ok && iss(0, i);
		
		}
		if(ok) printf("S\n");
		else printf("N\n");
		
		
		
	}
	

	
	return 0;
}
