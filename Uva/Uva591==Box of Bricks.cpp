#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
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
 
 
 
int main (int argc, char const* argv[]) {
	int n, k , sum, media, res;
	vi v;
	int t= 0;
	while(1){
		sc1(n); iz(n);
		t++;
		sum =0 ;
		v.clear();
		fr(i,0,n){
			sc1(k); sum+=k;
			v.pb(k);
		}
		media = sum/n;
		res = 0;
		fr(i,0,n){
			if(v[i] > media ) {
				res += v[i]-media;
			}
		}
		printf("Set #%d\n", t);
		printf("The minimum number of moves is %d.\n", res);
		_	
	}
	
	
	return 0;
}






