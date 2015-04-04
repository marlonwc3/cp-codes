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

vector<string> todas[1005];
int next;

string a, b;
int main(int argc, char const *argv[]) {
	int n;
	sc1(n);

	while(n--){
		cin >> a >> b;
		bool ok = 0;
		fr(i,0,next){
			if(todas[i].empty() ) continue;
			if( todas[ i ].back() == a ){
				todas[ i  ].push_back(b);
				ok = 1;
				break;
			}
		}
		if(!ok) {
			todas[next] = vector<string>();
			todas[next].push_back(a);
			todas[next].push_back(b);
			next++;
		}
	}
	n = next;
	printf("%d\n", n);
	vector< pair<string, string> > v;
	fr(i,0,next){
		a = todas[i].front();
		b = todas[i].back();
		v.pb(mp(a,b));
		//printf("%s %s\n", a.c_str(), b.c_str() );
	}
	sort(v.begin(), v.end());
	fr(i,0,n) printf("%s %s\n", v[i].st.c_str(), v[i].nd.c_str());



	return 0;
}
