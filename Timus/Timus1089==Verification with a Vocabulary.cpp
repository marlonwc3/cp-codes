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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


vector<string> todas;
int r = 0;
string get(string s){
	string s2;

	fr(i,0,todas.size()){
		int cnt = 0;	
		s2 = todas[i];
		if(s2.length() == s.length()){
			fr(j,0,s2.size() ){
				if(s2[j] != s[j]) cnt++;
								
			
			}
			if(cnt == 1){r++;  return s2; }
		}
		
		
	}

	return s;
}





string line;
char line2[1000010];
int main (int argc, char const* argv[]){
	while(1){
		getline(cin,line);
		if(line[0] == '#' && line.length() == 1) break;
		todas.pb(line);
	}
	
	string s;
	while(gets(line2)){
		//printf("line2: %s\n", line2);
		s = "";
		for(int i = 0; line2[i]; i++){
			if(! (line2[i] 	>= 'a' && line2[i] <= 'z') ){
				if(s.length() > 0){
					s = get(s);
					printf("%s", s.c_str() );
				}
				printf("%c", line2[i]);
				s = "";

			}
			else{
				s.pb(line2[i]);
			}
			
		}
		if(s.length() > 0 ) {
			s = get(s);
			printf("%s", s.c_str());		
		}
		printf("\n");
	
	}
	printf("%d\n", r);
	
	
	
	
	
	
	return 0;
}
