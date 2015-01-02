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



vi v1, v2;
int mark[200];

int main (int argc, char const* argv[]) {	
	int k, n;
	sc1(n);
	while(n--){
		sc1(k);
		v1.pb(k);
	}
	sc1(n);
	while(n--){
		sc1(k);
		v2.pb(k);
		mark[k]++;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int cont =0;
	int s1 = v1.size(), s2 = v2.size();
	fr(i,0,s1){
		fr(j,0,s2){
			if( !mark[ v2[j] ] ) continue;
			if( fabs(v1[i]-v2[j]) <= 1 ) {
				cont++;
				mark[ v2[j] ]--;
				goto fim;
			} 
		}
		fim:;
	}
	printf("%d\n", cont);
	
	return 0;
}


