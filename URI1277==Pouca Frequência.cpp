
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

int cmp(double a, double b){
	if ( fabs(a-b) <= EPS ) return 0;
	return a>b ? 1: -1;
}

vector<string> vs;
int main (int argc, char const* argv[]) {
	int t,n; char str[200];
	int p, total, len; double res;
	bool first;
	sc1(t);
	while(t--){
		sc1(n);
		vs.clear();
		fr(i,0,n) { scanf("%s", str); vs.pb(str); }
		first = 1;
		fr(i,0,n){
			scanf("%s", str);
			len = strlen(str);
			p = total = 0;
			fr(j,0,len){
				if( str[j]=='M' ) continue;
				total++; 
				p += str[j]=='P';
			}
			res = (p+0.0)/total;

			if( cmp ( res, 0.75 ) < 0 ) {
				if(!first) printf(" ");
				printf("%s", vs[i].c_str() );
				first = 0;
			}
		}
		_
	
	}
	
	
	return 0;
}


