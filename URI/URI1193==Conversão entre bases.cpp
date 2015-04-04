
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

char str[9005];
stack<char> sc; 
int len;
ll pint(int base){
	int pt=0;
	ll res = 0, k;
	for(int i=len-1; i>=0; i--, pt++){
		if(str[i]>='a') {
			k = ((str[i]-'a')+10)*pow(16.0, pt);
		}
		else k = (str[i]-'0')*pow(base+0.0, pt);
		res += k;
	}
	return res;
}

void ps(){
	char c;
	while(!sc.empty() ) {
		c =sc.top(); sc.pop();
		printf("%c", c);
	}

}
void to(ll n, int base){
	ll k;
	while( n ){
		k = n%base;
		if( base ==16 && k>= 10 ) { 
			k-=10;
			sc.push('a'+k );		
		}
		else sc.push( k+'0' );
		n/=base;
	}
}




int main (int argc, char const* argv[]) { 
	int n; ll num;
	sc1(n);
	char str2[5]; int caso;
	for(int i=1; i<=n; i++){
		scanf("%s %s", str, str2);
		len = strlen(str);
		if(str2[0]=='b') { num = pint(2); caso =0; }
		if(str2[0]=='d') { num = pint(10); caso=1; }
		if(str2[0]=='h' ){ num = pint(16);caso=2;	}
		printf("Case %d:\n", i);
		if(caso==0){
			printf("%lld", num);  printf(" dec\n");
			to(num,16);  ps(); printf(" hex\n");
			
		}	
		if(caso==1){
			to(num, 16); ps(); printf(" hex\n");
			to(num,2); ps(); printf(" bin\n");
		}
		if(caso==2){
			printf("%lld", num);  printf(" dec\n");
			to(num, 2); ps(); printf(" bin\n");
		}
		_
		
	}
	
	
	return 0;
}




















