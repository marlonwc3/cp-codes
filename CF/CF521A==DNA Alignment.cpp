#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
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

const ll MOD = ll(1000000007);

ll fexp(ll a, ll b){
	ll r = 1;
	for(ll k = 1; k <= b; k<<=(1LL), a= ( a*a)%MOD ){
		if(k&b) r= (r*a)%MOD;
	}
	return r;
}


int freq[300];
char str[100005];
int main (int argc, char const* argv[]){	
	int n;
	sc1(n);
	scanf("%s", str);
	int m = 0;
	fr(i,0,n){
//		printf("stri: %c\n", str[i]);
		freq[str[i]]++;	
		m = max(m, freq[str[i]]);
	}
	int cnt = 0;
//	printf("m: %d\n", m);
	fr(i,0,250) {
		cnt += freq[i]==m;
	}
	
	ll r = fexp(cnt, n);
	printf("%I64d\n", r);

	
	
	return 0;
}

