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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const double PI = acos(-1);


struct PT{
	double x, y;
	PT(){}
	PT(double _x, double _y){ x = _x, y = _y; }
	PT operator + (const PT &p) const { return PT(x+p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y ); }
	PT operator * (double c) const{ return PT(x*c, y*c); }
	PT operator / ( double c) const { return PT(x/c, y/c); }
};
double dot(PT p, PT q){ return p.x * q.x + p.y * q.y; }

// centor c 
vector<PT> intersect(PT a, PT b, PT c, double r) {
	vector<PT> ret;
	b = b-a;
	a = a-c;
	double A =dot(b,b);
	double B = dot(a,b);
	double C = dot(a,a) - r*r;
	double D = B*B - A*C;
	if( D < -EPS) { return ret; }
	ret.pb(c + a+b*(-B + sqrt(D+ EPS))/A );
	if( D > EPS ) ret.pb(  c + a + b*(-B - sqrt(D) )/A   );
	return ret;
}

double norm(PT v ){
	return sqrt(dot(v,v));
}

double angle(PT a, PT b, PT c, PT d) {
	PT v1 = b - a;
	PT v2 = d - c;
	return  acos( dot(v1, v2) / (norm(v1) * norm(v2) ) ) ;

}


int cmp(double a , double b = 0.0 ) {
	if(fabs(a-b) <= EPS) return 0;
	return a> b ? 1 : -1;

}



int main (int argc, char const* argv[]){
	int L, R;
	sc2(L,R);
	if ( R <= L/2) {
		double r = PI*R*R;
		printf("%.3lf\n", r);
	}
	else{
			double r;
			//(L*sqrt(2.0))/2.0 <= R  ? ?
		if( cmp( R , (L*sqrt(2.0))/2.0 ) >= 0 ) {
			r = L*L;	
		
		} 
		else{
			vector<PT> ret = intersect(PT(0,0), PT(0,L), PT(L/2.0, L/2.0), R);
			
			if(0){
			printf("pontos:\n");
			fr(i,0,ret.size() ){
				cout << ret[i].x <<" " << ret[i].y << endl; 
			}
			}
			PT centro = PT(L/2.0, L/2.0);
			double ag = angle(centro ,ret[0], centro, ret[1]);	
			//printf("angle: %lf\n", ag);			
			double base = norm(ret[0] - ret[1]);
			//printf("basE: %lf\n", base);
			double at = ( base*(L/4.0) );
			double setor = ( ag * (R*R)) / 2.0;
			
			double fora = setor - at;
			
			//printf("at: %lf | setor: %lf | fora: %lf\n", at, setor, fora);
			
			r = PI*R*R - 4.0 * fora;

			
			
			
		
		}
	
		printf("%.3lf\n", r);
			
			
				
	
	}
	
	
	
	
	
	return 0;
}






