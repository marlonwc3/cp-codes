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
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef set<int> si;



int n, l, x, y, k;
si s;
vi v;
int main (int argc, char const* argv[]) {
	sc4(n,l,x, y);
	fr(i, 0, n){
		sc1(k);
		s.insert(k); // saber se exciste ou n
		v.pb(k);
	}
	
	// tenho k números encontrar x e y, tal q x < y
	int p=-1, r, lol=-1;
	bool ex=0, ey=0;;
	fr(i, 0, n){
		k = v[i];
		if( s.count(k-x) || s.count(k+x) ) ex=1;
		if( s.count(k-y) || s.count(k+y) ) ey=1;
		p = k + x; 
		if( p<= l && s.count(p+y)  ) { lol=p; }
		else if( p<=l && s.count(p-y) ) { lol=p; }
		p = k - x;
		if( p>= 0 && lol==-1 && s.count(p+y)  ) { lol=p; }
		else if( p>=0 && lol==-1 && s.count(p-y) ) { lol=p; }

		if(lol==-1){
			p = k+y;
			if( p<= l && s.count(p+x) ) { lol=p;}
			else if( p<= l && s.count(p-x) ) {	lol=p; }
			p = k-y;
			if(p>=0 && lol == -1 && s.count(p+x) ) { lol=p;}
			else if(p>=0 && lol==-1 && s.count(p-x) ) {	lol=p; }			
		}
	}
	
	if(ex && ey ){
		printf("0\n");
	}
	else {
		if(!ex && !ey) {
			if (lol==-1) printf("2\n%d %d\n", x, y);
			else printf("1\n%d\n", lol);
		}
		else if(!ex){ // 
			printf("1\n%d\n", x);
		}
		else {
			printf("1\n%d\n", y);
		}
	
	}
	
	
	
	
	return 0;
}
