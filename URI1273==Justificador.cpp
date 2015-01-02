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
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

char str[55][55];


int main (int argc, char const* argv[]) {
	int n, m, len;
	bool first=1;
	while(1){
		sc1(n); iz(n);
		if(!first) _
		m = 0;
		fr(i,0,n){
			scanf("%s", str[i]);
			len = strlen(str[i]);
			m = max(m, len);
		}
		fr(i,0,n){
			len = m-strlen(str[i]);
			fr(j,0,len){
				printf("%c", 32);
			}
			printf("%s\n", str[i]);
		}
		first=0;
	
	}
	
	
	return 0;
}
