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


char str[1005][1005];


int main (int argc, char const* argv[]) {
	int s1=0,s2=0;
	for(int i =0; gets(str[i]); i++){
		for(int j =0; str[i][j]; j++){
			if(!isalpha(str[i][j]))continue;
			bool up = isupper(str[i][j]);
			char ch = tolower(str[i][j]);
			//printf("ch: %c | str %c\n", ch, str[i][j]);
			int k = 0;
			if(ch=='q')k=9;
			if(ch=='r')k=5;
			if(ch=='b')k=3;
			if(ch=='n')k=3;
			if(ch=='p')k = 1;
			
			if(up)s1+=k;
			else s2+=k;
		}
	}
	if(s1==s2)printf("Draw\n");
	else if ( s1 > s2 ) printf("White\n");
	else printf("Black\n");
	
	return 0;
}

