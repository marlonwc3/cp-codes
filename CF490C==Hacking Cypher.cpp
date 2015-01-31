#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;

ll a, b;
string line;
bool memo[1000005];

int main (int argc, char const* argv[]) {
	getline(cin,line);
	scanf("%I64d %I64d", &a, &b);
	//printf("a: %I64d b %I64d\n", a, b);
	bool ok = 1;
	int len = line.length();
	ll pt = 1, sum =0;
	int p1=-1, p2=-1;	
	if(line[0]=='-') goto label;
		
	for(int i = len-1; i>= 0; i--, pt= (pt*10)%b ){
		sum = (((line[i]-'0')*pt)%b + sum)%b;
//		printf("1. sum: %I64d\n", sum);
		memo[i] = sum==0;
	}
	sum = 0;
	for(int i =0; i < len; i++  ){
		sum = ((10*sum)%a + (line[i]-'0'))%a;
		if(i+1 < len && sum==0 && memo[i+1] && line[i+1] != '0' ){
			p1 = i, p2 = i+1;
		}
	}

	
	label:;
	if(p1 == -1 || p2 == -1 ) ok = 0;
	if(ok){ if( line[0]=='0' || line[p2]=='0') ok = 0; } 
	if(ok){
		printf("YES\n");
		fe(i,0,p1) printf("%c", line[i]);  _
		fr(i,p2,len) printf("%c", line[i]);
		_
	}
	else printf("NO\n");
	
	
	
	
	
	
	
	
	
	return 0;
}


