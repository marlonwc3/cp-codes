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

map<string, pair<string,string> > mymap;

string go(string a){
	pair<string, string> par = mymap[a];  
	a = par.st;
	string b = par.nd;
	if(a.length() < b.length() ) return a;
	if(b.length() < a.length() ) return b;
	return a;
}


int main (int argc, char const* argv[]) {
	int n,m;
	sc2(n,m);
	char str[100], str2[100];
	fr(i,0,m){
		scanf("%s %s", str, str2);
		mymap[str] = mp(str,str2);
		mymap[str2] = mp(str, str2);
	}
	
	string a;
	fr(i,0,n){
		scanf("%s", str);
		a = go(str);
		printf("%s", a.c_str() );
		if(i!=n-1) printf(" ");
	}
	_
	
	
		
	return 0;
}
