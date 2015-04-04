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

int v[105], n;
int par, impar;


bool f(int r, int c){
	//printf("try %d %d\n", r, c);
	int tpar=0, timpar=0;
	if(c%2 == 1) {tpar = r*(c-1); timpar = r;} 
	else tpar = r*c;
	//printf("tpar: %d | timpar : %d\n", tpar, timpar);
	timpar  -= impar;
	tpar -= par;
	if(tpar < 0 ) {
		timpar +=tpar;
		if(timpar == 0) tpar = 0;
	}
	return timpar == 0 && tpar == 0;
	
}

int main (int argc, char const* argv[]) {
	int caso;
	sc1(caso);
	fe(t,1,caso){
		sc1(n);
		int total = 0;
		par = impar = 0;
		fr(i,0,n){
			sc1(v[i]);
			impar+= v[i]%2 == 1;
			v[i] -= (v[i]%2 == 1);
			par += v[i];
		}
		//printf("total %d | par: %d | impar :%d \n", total, par, impar);
		total = (par+impar);
		bool ok =0;
		for(int c = 1; c*ll(c) <= ll(total) ; c++){
//			printf("i: %d | \n");
			if( total%c != 0 ) continue;
			int r =total/c;
		//	printf("try %d %d\n", i, c);
			if( (c>=2 && f(r, c))|| (r>= 2 && f(c, r)  ) ){
				//printf("ok para %d %d\n" , r, c);
			 	ok=1;
			 	break;
			}
		}
		if(ok) printf("Caso #%d: Challenge Accepted!\n", t);	
		else printf("Caso #%d: Run for your life!\n", t);
		
		
	
	
	
	}
	
	
	
	
	return 0;
}











