
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
bool cmp(int a, int b) { return a>b;}


char str[2000];
int mod, len;

int val(char c){
	if(c >= '0' && c <='9' ) return c-'0';
	if (c >= 'A' && c<='Z') return c-'A' + 10;
	return c-'a' + 26 + 10;
}

ll exp(ll a, ll b){
	if( !b ) return 1;
	if ( b==1) return a;
	ll r = exp(a, b/2)%mod;
	r= (r*r)%mod;
	if( b%2 == 1 ) r*= (a)%mod;
	return r%mod;
	
}

int solve(){
	len = strlen(str);
	ll k, res; int pt; 
	fr(i,2, 63){
		mod = i-1;
		pt =0;
		res = 0;
		for(int j = len-1; j>=0; j--){
			if(str[j]=='-') continue;
			k = val(str[j]);
			if ( k >= i ) {res=1; break; } 
			
			k = (k* exp(i, pt))%mod; 
			res = (res+k)%mod;
		}
		if(!res) return i;
	}
	return -1; 
}

int main (int argc, char const* argv[]) {
	int n;
	while ( scanf("%s", str)  ==1 ) {
		n = solve();
		if(n==-1) printf("such number is impossible!\n");
		else printf("%d\n", n);
	}
	
	
	return 0;
}













