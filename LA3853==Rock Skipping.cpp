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
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

struct skip {
	int c, l , i, d;
	skip(){}
	skip(int _c, int _l, int _i, int _d){ c=_c; l = _l; i = _i; d = _d; }
	bool operator >  (const skip &s) const {
		if(c > s.c ) return 1;
		if(c == s.c )  {
			if(l > s.l) return 1;
			if(l == s.l){
				if(i > s.i) return 1;
				if(i == s.i) {
				 	if(d < s.d ) return 1; 
				 }
			}
		}
		return 0;
	} 
};

skip res;
char str[50];
int t;

ii count(int ini, int k){ // lenght ultima antes de sair 
	int res = 0,  last = ini;
	
	while ( ini < t && str[ini] == '.'){ last = ini; ini +=k ; res++;  } 
	if(ini < t ) last = ini;
	return mp(res,last) ;
}

void f(){
	ii r; skip k;
	res = skip(-1, -1, -1, inf);
	fr(i,0,t){
		if(str[i]!='.') continue;
		for(int j = 1; j <= t-i; j++) {
			r = count(i,j);	
			k = skip (   r.st,r.nd,i,j) ;
			if ( k > res ) res = k;
		}
	
	}			
		
}



int main (int argc, char const* argv[]) {
	while(1){
		scanf("%s", str);
		t = strlen(str);
		if(t == 3 & str[0]=='E' && str[1]=='N' && str[2] == 'D') break;
		
		f();
		if(res.i==-1) {
			res.i = t-1; res.d = 1;
		}
		printf("%d %d\n", res.i, res.d);
		
	}
	return 0;
}





















