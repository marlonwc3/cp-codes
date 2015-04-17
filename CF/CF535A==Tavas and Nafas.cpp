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
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

string s2[15] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string s1[15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
string s3[15] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"} ;









int main (int argc, char *argv[]) {
	int n;
	sc1(n);
	
	if( n<= 10 ) printf("%s\n", s1[n].c_str() );
	else if (n>=11 && n <= 19) {
		printf("%s\n", s3[n-11].c_str() );
	} 
	else{
		int a = n%10;
		int b = n/10;
		b -= 2;
		printf("%s", s2[b].c_str() );
		
		if( a >= 1 ) {
			printf("-%s", s1[a].c_str() );
		}
		_
	
	}
	
	return 0;
}
