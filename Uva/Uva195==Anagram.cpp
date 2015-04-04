#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
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


bool mycpm(string a, string b){
	int la = a.length();
	char ca, cb;
	fr(i,0,la){
		ca = a[i], cb = b[i];
		if(ca==cb) continue;
		if( ca + 32 == cb || cb + 32 == ca ) {
			if( ca>='A' && ca <= 'Z') return 1;
			return 0; 
		}
		return (tolower(ca) < tolower(cb) );
	}
	return 0;
}


vector<string> v;
char str[30000];
int main (int argc, char const* argv[]) {
	int t, len;


	sc1(t);
	while(t--){
		scanf("%s", str);
		len = strlen(str);
		v.clear();
		sort(str, str+len);
		do{
			v.pb(str);
		}while(next_permutation(str, str+len) );
	
		sort(v.begin(), v.end(), mycpm);
		len = v.size();
		fr(i,0,len){
			printf("%s\n", v[i].c_str() );
		}
		
	}
	return 0;
}












