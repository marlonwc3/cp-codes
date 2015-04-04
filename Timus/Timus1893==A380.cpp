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


int main (int argc, char const* argv[]) {
	char str[50], c;
	scanf("%s", str);
	int len = strlen(str);
	int p;
	fr(i,0,len){
		if( str[i] > '9' || str[i] < '0') {p=i-1; break;} 
	}
	c = str[p+1];
	int pt =0, k = 0;
	for(int i = p; i>=0; i--){
		k += (str[i]-'0')*pow(10.0, pt);
		pt++;
	}
	
	if( k <= 2 ) {
		if(c!='A' && c!='D' )printf("aisle\n"); 
		else printf("window\n");
	}
	else if (k<=20) {
		if(c=='A' || c =='F' ) printf("window\n");
		else printf("aisle\n");   
	}
	else {
		if( c=='A' || c=='K' ) printf("window\n");
		else if ( c=='B' || c=='E' || c== 'F' || c=='J' ) printf("neither\n");
		else printf("aisle\n");
	}
	
	

	
	
	
	return 0;
}
