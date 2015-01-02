
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
bool cmp(int a, int b) { return a>b;}

vi v;
int n,g;
int main (int argc, char const* argv[]) {
	int cont ,a ,b ,s;
	while(sc2(n,g)  != EOF ) {
		cont=0;
		v.clear();
		fr(i,0,n){	
			sc2(a,b);
			if (a>b) cont+=3;
			else v.pb(a-b);
		}
		sort(v.begin(), v.end(), cmp);
		s = v.size();
		bool fim = 0;
		fr(i,0,s){
			if( fim ) {
				if(v[i]==0) cont++;
				else break;
			}
			else { 
			if(g<=0) fim=1;
			if ( (1-v[i]) <= g  )  { 
				g -= (1-v[i]);
				cont+=3; 
			}
			else if ((0 - v[i]) == g) {
				cont++;
				g -= 0-v[i];
			}
			else fim=1; }
		}
		printf("%d\n", cont);
	}
	return 0;
}









