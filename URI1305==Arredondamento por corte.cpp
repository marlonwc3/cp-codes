
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

char str[35];
char str2[30];
ll parse(int a, int b, bool op){
	ll pt=0, res=0;
	int sig = 1;
	if(str[a]=='-'){ sig =-1; a++;}
	for(int i=b-1; i>= a; i--, pt++){
		if(op) res += ll(str[i]-'0') * ll ( pow(10.0, pt)   );	
		else{
		    res +=  ll(str2[i]-'0') * ll ( pow(10.0, pt)   );	
		 
		 }
	}
	return res*sig;
}

int main (int argc, char const* argv[]) {

	while(scanf("%s %s", str, str2) != EOF )  {  
		int p=-1, len; 
		len =strlen(str);
		fr(i,0,len){
			if(str[i]=='.' ) {
				p = i; break;
			}
		}
		if(p==-1) printf("%s\n", str); goto fim;
		ll a, b, c;
		a = parse(0,p,1);
		if(p==len-1) goto print;
		b = parse(p+1, len, 1);		
		c = parse(2, 6, 0);
		len = len - ( p+1  );
		if ( len <  4)  b = b*pow(10.0, 4-len);
		if ( len > 4 ) c = c*pow(10.0, len-4); 
		if( b>c ) { 
			if(a==0 && str[0]=='-') a=0;
			else a++; 
		}
		print:;
		printf("%lld\n", a	); 
		fim:;
	}
	return 0;
}

