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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
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

vector<string> v;



set<string> myset;
char str[1000];


int main (int argc, char const* argv[]) {
	int t, n, len;
	ll w;
	sc1(t);
	string s, aux;
	while(t--){
		sc1(n);
		v.clear();
		myset.clear();
		fr(i,0,n){
			scanf("%s", str);
			len = strlen(str);
			s = "";
			for(int j = 0; j < len; j++){
				aux = str[j];
				s = s + aux;
				if(j!=len-1) myset.insert(s);
			}			
			//printf("botou %s\n", s.c_str());
			v.pb(s);
			
		}
		bool ok = 1;

		fr(i,0,v.size()){
			if(myset.count(v[i])){
				//printf("lasco p %s\n", v[i].c_str());
			}
			ok = ok && !(myset.count(v[i]));
			
		
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	
	
	
	
	
	return 0;
}













