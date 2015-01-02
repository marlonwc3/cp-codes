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

vi p;
bool mark[1000005];
bool crive(){
	mark[0]=mark[1] = 1;
	for(ll i=2; i < 1000003; i++){
		if(!mark[i]){
			if(i%2)p.pb(i);
			for(ll j=i*i; j<1000003; j+=i){
				mark[j] =1 ;
			}
		}
	}
}	


int main (int argc, char const* argv[]) {
	crive();
	int s = p.size();

	int n, a, b;
	bool ok;
	int pos;
	while(1){
		sc1(n); iz(n);
		ok = 0;
		pos = upper_bound(p.begin(), p.end(), n) - p.begin(); 
		for(int i = pos; i >= 0; i--){
			b = p[i];
			a = n-b;
			if(a>0 && !mark[a]) {
				ok =1; 
				break;
			}	
		}
		if(ok) printf("%d = %d + %d\n", n,a, b);
		else printf("Goldbach's conjecture is wrong.\n");
	
	}
	
	
	return 0;
}

















