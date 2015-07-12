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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

string s1 = ".alal";
string s2 = "miao.";

int main (int argc, char const* argv[]){
	int N;
	string str;
	sc1(N);
	getline(cin, str);
	int l;
	bool ok1, ok2;
	fr(i,0,N){
		getline(cin, str);
		l = str.length();
		ok1 = 0, ok2 = 0;
		string x, aux;
		x = "";
		int l2 = min(l, int(s2.length()));
		fr(j,0,l2){
			x.pb(str[j]);
		}
		if(x == s2) ok2=1;
		reverse(str.begin(), str.end());
	
		x = "";
		l2 = min(l, int(s1.length()));
		fr(j,0,l2){
			x.pb(str[j]);
		}
		if(x == s1) ok1=1;		
		if(ok1 && ok2) printf("OMG>.< I don't know!\n");
		else if(!ok1 && !ok2) printf("OMG>.< I don't know!\n");
		else if(ok1) printf("Freda's\n");
		else printf("Rainbow's\n");
		
		
		
	}
	
	
	
	
	
	
	return 0;
}



