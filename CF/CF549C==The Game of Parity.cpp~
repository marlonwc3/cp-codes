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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;



int main (int argc, char const* argv[]){
	int n , k, w;
	int js, jd, par = 0, impar = 0, j;
	sc2(n,k);
	fr(i,0,n){
		sc1(w);
		par += (w%2 == 0);
		impar += (w%2 == 1 );
	}
	j = n - k;
	js = (j+1)/2; 
	jd = j/2;
	//printf("js: %d | jd: %d | par: %d | impar: %d | k :%d \n", js, jd, par, impar , k);
	
	if(n==k ){
		if(impar %2 == 1) printf("Stannis\n");
		else  printf("Daenerys\n");
	}
	else if( impar == 0) printf("Daenerys\n");
	else if( par == 0 ) {
		if(  (impar - j)%2 == 1 )printf("Stannis\n"); 
		else printf("Daenerys\n");
	}
	else{
		if(js > jd ) {
			if(k%2 == 0 ){
				if( jd >= par || jd >= impar ) printf("Daenerys\n");
				else printf("Stannis\n");
			}
			else{
				if( jd >= impar) printf("Daenerys\n");
				else printf("Stannis\n");	
			}
		
		}
		else{
			if(k%2 == 0) printf("Daenerys\n");
			else{
				if( js >= par) printf("Stannis\n");
				else printf("Daenerys\n");	
			}			
		}
	
	} 
	
	
	
	
	
	
	
	
	
	return 0;
}

