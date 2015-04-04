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
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int cmp(double a, double b){
	if( fabs(a-b) < EPS ) return 0;
	return a>b ? 1 : -1; 
}

struct point  {
	double x, y;
	point(){}
	point(double _x, double _y){
		x=_x; y = _y;
	}
	bool operator < (const point &p) const{
		if(fabs(x -p.x) < EPS  ) return x <  p.x;
		return y < p.y;
	}
};

bool print;


struct  vec{
	double x, y;
	vec(){}
	vec(double _x, double _y){x=_x; y=_y;}
	vec(point a, point b){
		x=b.x - a.x; y=b.y -a.y;
	}
	double norm(vec vt){
		return sqrt( vt.x*vt.x + vt.y*vt.y	 		 );
	}
	double dotProd(vec a){
		return a.x * x  + a.y * y;
	}
	double angle(vec vt){

		return acos(   dotProd(vt) / (norm(*this)*norm(vt) )  );
	}		
};


double area(point a, point b, point c){ 
	//using heron fornula ( area = sqrt( s * (s-la) *(s-lb) *(s-lc)  ) )  // where l == edge
		vec v1,v2,v3;
		v1 = vec(a,b); double la = v1.norm(v1);
		v2 = vec(b,c); double lb = v2.norm(v2);
		v3 = vec(c,a); double lc = v3.norm(v3);
		double s = (la+lb+lc)/2; // semi-perim
		return sqrt( s* (s-la )*(s-lb)*(s-lc)  ); // heron formule
}

struct Fig {
	char t;
	double r;
	point a, b, c;
	Fig(){}
	Fig(point _a, point _b){
		a=_a; b=_b; t = 'r';
	}
	Fig(point _a, double _r){
		a=_a; r=_r; t = 'c';
	}
	Fig(point _a, point _b, point _c){
		a=_a; b= _b; c= _c; t='t';
	}
	bool in(point p){
		int res;
		if(t=='r'){
			return p.x > a.x && p.y < a.y && p.x < b.x && p.y > b.y;
		}
		if(t == 'c'){
			vec v = vec(a, p);
			res = cmp( v.norm(v), r  );
			return res == -1;  
		}
		if( p.x == a.x || p.y == a.y || p.x == b.x || p.y == b.y || p.x == c.x || p.y == c.y ) return 0;	  // fronteira
		// triangulo
//		return 0;
		double at = area(a,b,c), control = 0.0; //total area
		
		double a1 = area(a,b,p);
		double a2 = area(a,c,p);
		double a3 = area(b,c,p);
		
		control += (a1/at) + (a2/at) + (a3/at);
		
		return cmp(control, 1.0) == 0; // suming all control points area must to be 0 
	
	}

};

vector<Fig> f;


int main (int argc, char const* argv[]) {
bool res;
	point a, b, c, d; double r; char t;
	double x ,y;
	while(1){
		scanf(" %c", &t);
		if(t=='*') break;
		if(t=='r'){
			scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
			f.pb( Fig(a,b) );
		}
		if(t=='c') {
			scanf("%lf %lf %lf", &a.x, &a.y, &r);
			f.pb(Fig(a, r) );
		}
		if(t == 't'){
			scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
			f.pb(Fig(a,b,c) );
		}
	}
	int s = f.size();
	int pt  =0;
	bool ok;
	while(1){
		scanf("%lf %lf", &x, &y);
		if(cmp(x, 9999.9) == 0 && cmp(y, 9999.9) == 0 ) break; 
		ok =0 ;
		pt++;
		fr(i,0,s){
			if(  f[i].in( point(x,y) )   )  {
				printf("Point %d is contained in figure %d\n", (pt), ( i+1) );
				ok=1;
			}
		}
		if(!ok) printf("Point %d is not contained in any figure\n", pt);
		
	}
	
	
	
	return 0;
}





