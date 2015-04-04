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

int cmp(double a,double b=0.0){
	if(fabs(a-b) < EPS ) return 0;
	return a >b ? 1 : -1;
}

struct point{
	double x,y;
	point(){}
	point ( double _x, double _y ){x=_x, y=_y;}
	bool operator < (const point &p ) const{ 
		int r1 = cmp(x, p.x), r2 = cmp(y,p.y);
		if( r1 == 0 ) return r2 == -1;
		return r1 == -1;
	}
};
bool print;
struct vec{
	double x, y;
	vec(){}
	vec( double _x, double _y) { x=_x, y=_y;}
	vec (point a, point b ) { x=b.x-a.x; y=b.y-a.y;}
	double norm(vec vt) {return sqrt(vt.x * vt.x + vt.y*vt.y); }
	double dotProd(vec a) {return a.x*x + a.y*y;}
	double angle( vec vt) {return acos ( dotProd(vt)/(norm(*this)*norm(vt)) );  }
};

struct Fig
{
	char t;
	double r;
	point a,b,c;
	Fig(){}
	Fig(point _a, point _b) {a=_a,b=_b; t='r';}
	Fig(point _a, double _r) {a=_a,r=_r; t='c';}
	Fig(point _a, point _b, point _c){
		a=_a,b=_b,c=_c,t='t';
	}
	bool in(point p){
		int res;
		if(t=='r') {return p.x > a.x && p.y < a.y && p.x < b.x && p.y > b.y;}
		if(t=='c'){
			vec v = vec(a,p);
			res = cmp(v.norm(v), r);
			return res==-1;
		}
		
		if( p.x==a.x || p.y == a.y || p.x == b.x || p.y == b.y || p.x == c.x || p.y == c.y ) return 0; 
		vec v1, v2;
		double cont = 0;
		print = 1;
		v1 = vec(p,a);
		v2 = vec(p,b);
		cont += v1.angle(v2);
		v1 = vec(p,a);
		v2 = vec(p,c);
		cont += v1.angle(v2);
		v1 = vec(p,b);
		v2 = vec(p,c);
		cont += v2.angle(v1);
		return cmp(cont, 2*PI) == 0;
		
		
	
	}
	
	
	
};




int main (int argc, char const* argv[]){
	char str[3];
	vector< Fig > v; v.clear();
	double a,b, c, d, e;
	while( 1 ){
		scanf("%s", str);
		if(str[0]=='*') break;
		if(str[0]=='r'){
			scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
			v.pb(Fig(point(a,b) , point(c,d)) );
		}
		/*
		if (str[0]=='c') {
			scanf("%lf %lf %lf", &a, &b, &c);
			v.pb(Fig(point(a,b) ,c) );			
		}
		*/
	}
	point p;
	int id = 0;
	bool ok;
	while(  1 ){ 
		scanf("%lf %lf", &a, &b);
		id++;
		p = point(a,b);
		if(cmp(a,9999.9)==0 && cmp(b,9999.9)==0) break;
		
		//printf("id: %d | %lf %lf \n", id, a,b);
		ok = 0;
		fr(i,0,v.size()){
			if( v[i].in(p) ){
			 	printf("Point %d is contained in figure %d\n", id, (i+1)); 
			 	ok=1;
			}
		}
		if(!ok) printf("Point %d is not contained in any figure\n", id);
	
	} 
	
	
	
	
	return 0;
}














