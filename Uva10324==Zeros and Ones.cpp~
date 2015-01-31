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


int rep[1000005];
void ini(int n){ fe(i,0,n) rep[i]=i; }
int find(int a) {  return rep[a] = (rep[a]==a) ? a : find(rep[a]); }
void uni(int a, int b ) { rep[find(a)]  = find(b); }
bool iss(int a, int b) {  return find(a)==find(b); }
string line;
int main (int argc, char const* argv[]){
	int len, n, a, b, t = 0;
	while( getline(cin, line ) ) {
		t++;
		len = line.length();
		ini(len);
		int p = -1, bef = -1, k;
		fr(i,0,len) {
			k = line[i]-'0';
			if( k == bef ) {
				uni( i, p ); 
			}
			else {
				p = i;
				bef = k;
			}
		}
		sc1(n);
		printf("Case %d:\n", t);
		fr(i,0,n){
			sc2(a,b);
			if ( iss(a,b)  ){
				printf("Yes\n");
			}
			else printf("No\n");
		}
		getline(cin, line);	
	}
	return 0;
}












