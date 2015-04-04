
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
bool cmp(int a, int b) { return a>b;}

char arr[1000005];
string str;
int main (int argc, char const* argv[]) {
	int n, len, d;
	sc1(n); bool um;
	while(n--){
		scanf("%s", arr);
		str=arr;
		len = str.length();
	
		d = len-1;
		while (d >= 0 ) {
			str[d]++;
			if(str[d] > '9') str[d] = '0';
			else break;
			d--;
		}
		if ( d < 0 ){
			str="1"+str; len++;
		}
		

		for(int i=0, j=len-1; i<j; i++, j--) {
			if(str[i]==str[j]) continue;	
			if ( str[i] > str[j] ) { 
				str[j]=str[i]; continue;
			}
			d = j-1;
			while (d >= 0 ) {
				str[d]++;
				if(str[d] > '9') str[d] = '0';
				else break;
				d--;
			}

			str[j]=str[i];
		}
		
		printf("%s\n", str.c_str());
		
	}	
	return 0;
}








