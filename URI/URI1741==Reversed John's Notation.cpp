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

#define MAX_N 2*(1000000)
char line[MAX_N + 10];

int ZERO = 0;
int op(int a, int b, char ch){
	if(ch=='-') return b-a;
	if(ch=='+') return b+a;
	if(ch=='*') return a*b;
	if(ch=='/') {
		if(!a) { ZERO = 1; return 1;}
		return b/a;

	}
}
int N;
bool OK;
ii f(int p){
	if(p >= N) return mp(0,-1);
	if(line[p]==' ') return f(p+1);
	if(isdigit(line[p]) ) return mp(line[p]-'0', p+1);
	ii p1 = f(p+1);	
	if(p1.nd == -1 || !OK ) {OK=0; return mp(-1,-1); }
	ii p2 = f(p1.nd);
	int r = op(p1.st, p2.st, line[p]);
	return mp(r, p2.nd);
}

int main (int argc, char const* argv[]){
	while( gets(line) ) {
	//while(1){
		N = strlen(line);
		OK = 1;
		ZERO = 0;
		ii r= f(0);
		//printf("r: %d %d\n", r.st, r.nd);
		if(!OK || r.nd != N) printf("Invalid expression.\n");
		else if( ZERO ) printf("Division by zero.\n");
		else{
			printf("The answer is %d.\n", r.st);
		}
	
	
	}
	
	
	return 0;
}





















