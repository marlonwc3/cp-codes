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

string s;
int len;
bool pal(){
	len = s.length();
	int i=0, j = len-1; 
//	printf("s %s i %d j %d\n", s.c_str() ,i, j);	
	for(; i < j; i++, j--){
	//		printf("comparing %c %c\n", s[i], s[j] );			
//		if(s[i] < 'a' || s[i] >'z') { j++; }
	//	if (s[j] < 'a' || s[j] >'z') { i--; }

		if(s[i]!=s[j]) return 0;
	}
	return 1;
	
}

int main (int argc, char const* argv[]) {
	
	
	int w;
	sc1(w); getline(cin, s);
	w++; 
	bool ok;
	string r;
	fr(t,1,w){
		getline(cin, r);

		len = r.length();
		s = "";
		fr(i,0,len){
			if( r[i] < 'a' ||r[i] >'z') continue;
			s += r[i];
		}
		
		ok = pal();
		
		printf("Case #%d:\n", t  );
//		printf("ok ->%d\n", ok);		
		if (ok ) {
			ok = 0;
			fr(i,1,350){
				if( i*i == len ) ok = 1;
			}
			if ( ok ) {
				len = sqrt(len);
				printf("%d\n", len);
			}
			else printf("No magic :(\n");
		}
		else {
			printf("No magic :(\n");
		} 

		
		
		
	}
	
	
	
	
	return 0;
}
