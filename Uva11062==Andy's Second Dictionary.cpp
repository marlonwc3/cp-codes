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

char line[100000], str[550];
set<string> myset;
int main (int argc, char const* argv[]) {
	string s = "";
	int len;
	char *pch;	
	int id=0;

	while(gets(line) ){	
		len = strlen(line);
		if(!len) continue;
		fr(i,0,len){
			if(line[i] == '-') continue;
			line[i] = tolower(line[i]);
			if(line[i]<'a' || line[i] >'z') line[i]=32;
		}
		
		pch = strtok(line, " ");
		while( pch != NULL ) {
			s += pch;
			len = s.length();
			pch = strtok(NULL, " ");
			len = s.length();
			if(pch!=NULL || s[len-1]!='-') {
				myset.insert(s);
				id++;
				s= "";
			}
			else if( pch ==NULL && s[len-1]=='-'){
				s = s.substr(0, len-1);
			}
		}
	}
	
	for(set<string>::iterator it = myset.begin(); it!=myset.end(); it++) {
		printf("%s\n", (*it).c_str()  );
	}

	
	return 0;
}











