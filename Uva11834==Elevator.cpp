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
int cmp(double a, double b=0.0){
	if(fabs(a-b) < EPS ) return 0;
	return a>b?1:-1;
}
struct PT{
	int x,y;
	PT(){}
	PT(int _x, int _y) { x=_x,y=_y;}
	double dist(PT p){
//		return hypot();
		return sqrt( (x - p.x)*(x - p.x) +  (y - p.y)*(y - p.y) );
		return ( (x - p.x)*(x - p.x) +  (y - p.y)*(y - p.y) );
	}
	void pf(){
		printf("(%d, %d) ", x, y);
	}
};


int main (int argc, char *argv[]) {
	int h, w, r1, r2;
	int t;
	while(1){
		sc4(h,w,r1,r2); if(!h && !w && !r1 && !r2 ) break;
		bool ok = 0;
		
		PT c1 = PT(r1, r1);
		PT c2 = PT(w-r2, h - r2);

		t=r1+r2;
//		printf("t: %d\n", t);
		if(!(c1.x < 0 || c1.y < 0 || c2.x < 0 || c2.y < 0 ) ){
			//ok |= (c1.dist(c2) >= t*t);
			ok |= cmp(c1.dist(c2), t ) >= 0;
			//printf("dist: %d\n", c1.dist(c2));
		}		
		c1 = PT(w-r1, h-r1);
		c2 = PT(w-r2, h-r2);		
		
		
		c1 = PT(w-r1, r1);
		c2 = PT(r2, h - r2);
		if(!(c1.x < 0 || c1.y < 0 || c2.x < 0 || c2.y < 0 ) ){		
			//ok |= (c1.dist(c2) >= t*t);
			ok |= cmp(c1.dist(c2), t ) >= 0;			
			//printf("dist: %d\n", c1.dist(c2));		
		}
	//	c1.pf(); c2.pf(); _
		//printf("dist: %lf | r1+r2: %d\n", c1.dist(c2), (r1+r2) );
		if(2*r1 > h || 2*r1 > w || 2*r2 > h || 2*r2 > w ) ok=0;
		if( ok ) printf("S\n");
		else printf("N\n");
		
		
	}
	
	
	
	
	
	
	return 0;
}
















