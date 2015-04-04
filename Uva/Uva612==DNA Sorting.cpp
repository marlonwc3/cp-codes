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

typedef pair<string, int> psi;
vii v;
vector<string> vs;
char str[60];

int main (int argc, char const* argv[]) {
	int t, n, m;
	sc1(t);
	bool f =1;
	while(t--){
		v.clear();
		vs.clear();
		sc2(n,m);
		if(!f) _
		
		fr(i,0,m){
			scanf("%s", str);
			vs.pb(str);
			int cont =0 ;
			fr(j,0,n){
				fr(k,j+1, n){
					cont += str[k]<str[j];
				}
			}
			v.pb(mp(cont,  i) );
		}
		stable_sort(v.begin(), v.end());
		fr(i,0,m){
			int p = v[i].nd;
			printf("%s\n", vs[p].c_str());
		}
		f = 0;
	}
	
	
	
	return 0;
}







