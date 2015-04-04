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


string line;

bool mark[100005];

int main (int argc, char const* argv[]) {
	getline(cin, line);
	int len = line.length(), k;
	int w = line[len-1] - '0';
	bool ok = 0;
	fr(i,0,len){
		if( ((line[i]-'0')%2==0 ) && w > ( line[i]-'0'  ) ){
			swap(line[i], line[len-1]);
			ok = 1;
			break;		
		}
	}
	if(!ok) {
		for(int i = len-1; i >= 0; i--){
			if( (line[i] -'0')%2 == 0 ) {
				swap(line[i], line[len-1]);
				ok = 1; 
				break;
			}
		}	
	}	
	if(!ok) printf("-1\n");
	else printf("%s\n", line.c_str() );
	
	
	
	return 0;
}

