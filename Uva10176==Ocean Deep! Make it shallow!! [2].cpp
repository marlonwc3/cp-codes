#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
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


#define MOD 131071
ll fexp(ll a, ll b){
	if(!b) return 1;
	if(b==1) return a;
	ll r = fexp(a, b/2)%MOD;
	r = (r*r)%MOD;
	if(b%2 == 1) r= (r*a)%MOD;
	return r;
}
string str;
char line[10030];
int main (int argc, char const* argv[]) {
	int len, k, sum;
	bool first = 1;
	str = "";
	while( scanf("%s", line) == 1 ){
		str = line;
		len = strlen(line);
		while( line[len-1] != '#' ) {
			scanf("%s", line);
			len = strlen(line);
			str +=line;
		}	
		sum = 0;
		len = str.length();
		for(int i = len-2, j = 0; i>=0 ; i--, j++){
			k = str[i]-'0';
			k = (k*fexp(2,j))%MOD; 
			sum = (sum+k)%MOD;
		}
		if(!sum) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


