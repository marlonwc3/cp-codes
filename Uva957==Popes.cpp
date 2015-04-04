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



int main (int argc, char const* argv[]) {
	int y, n, k;
	int ag, bg, rg, a, b, r, last;
	vi v;
	while( sc1(y) ==1 ){
		v.clear();
		sc1(n);
		fr(i,0,n){
			sc1(k);
			v.pb(k);
		}
		
		//pv(v,x);
		int d, p;
		rg = 0;
		
		fr(i,0,n){
			 k =v[i];
			 d = k + y -1;
			 p = upper_bound(v.begin(), v.end(), d) - v.begin() ;
			 //printf("%d %d %d\n", k, d, p );
			 if( p == v.size() ) p--;
			 while( v[p] > d ) p--;			 
//			 if( p >= v.size() ) continue;
//	 		 printf("%d\n", v[p] );			 
			 bool ok = 0;
			 while( p+1 < v.size() && v[p] == v[p+1]) {p++; ok= 1;}
			 p-= ok;
			 
//			 printf("p fim %d\n", p);
			 if( v[p] - k <= y ){
			 	r = p - i + 1;
			 	
			 	if(r > rg) {
			 		rg = r;
			 		ag = k, bg = v[p]; 
			 	}
			 	
			 } 
			 
		}
		printf("%d %d %d\n", rg, ag, bg);
			
	}
	
	
	
	
	return 0;
}







