
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

vector<string> vs;
bool cmp(string a, string b){
	int len = a.length();
	fr(i,0,len){
		if( a[i] < b[i] ) return 1;
		if( a[i] > b[i]) return 0;
	}
	return 1;
}

int main (int argc, char const* argv[]) {
	int n, len, cont;
	char str[205];
	string acima;
	while(scanf("%d", &n) != EOF ) {
		vs.clear(); cont=0;
		fr(i,0,n){
			scanf("%s", str);
			vs.pb(str);
		}
		sort(vs.begin(), vs.end(), cmp);
		acima = vs[0];
		len = acima.length();
		fr(i,1,n){
			fr(j,0,len){
				if(acima[j] == vs[i][j] ) cont++;
				else break;
			}
			acima = vs[i];
		}
		printf("%d\n", cont);
	}
	
	
	
	
	return 0;
}








