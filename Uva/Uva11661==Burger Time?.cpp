#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

string line;
int main (int argc, char const* argv[]) {
	int len;
	while(1){
		sc1(len); iz(len);
		getline(cin, line);
		getline(cin, line);
		int res = inf;
		int ld , lr ; ld=lr=-1;
		fr(i,0,len){
			if( line[i] =='Z' ) { res=0; break;}
			if(line[i] =='R'){
				if(ld!=-1) res = min(res, abs(ld - i) );
				lr = i;
			}	
			else if (line[i] =='D' ) {
				if(lr != -1 ) res = min(res, abs(lr- i) );
				ld = i;
			}
		}
		
		printf("%d\n", res);
		
	}
	
	
	
	
	return 0;
}








