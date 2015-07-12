#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second

#define oi(x) cout <<"[Oi | " << x << "]"<<endl;

using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
const long double EPS = 1e-6;


const long double PI = acosl(-1);

/*
4
83 120
55 90
72 149
110 135
*/


int cmp(long double a, long double b=0.0){
	if(fabsl(a-b) <= EPS ) return 0;
	return a>b ? 1 : -1;
}


struct PT { 
  long double x, y; 
  PT() {}
  PT(long double x, long double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT(pair<long double, long double> par){ x = par.st, y = par.nd; }
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  bool operator == (const PT &p) const { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
} ;

struct line{
	long double a,b,c;
	line(){}
	line(long double _a, long double _b, long double _c){a=_a,b=_b,c=_c;}
}; 
line toline(PT p1, PT p2){
	if(cmp(p1.x , p2.x) == 0 ) {
		return line(1, 0, -p1.x);
	}
	line l;
	l.a = -(long double)(p1.y - p2.y) / ( p1.x - p2.x); 
	l.b = 1;
	l.c = -(long double)(l.a * p1.x) - p1.y;
	return l;
}
bool lineParalel(line l1, line l2){
	return (cmp(l1.a,l2.a)==0) && ( cmp(l1.b,l2.b) ==0  ) ;
}

bool intersectLine(line l1, line l2, PT &p, bool tenso = 0 ) {
	
	if(lineParalel(l1,l2) )  { 
		//if(tenso) printf("Intersect line paralel!\n");
	 return 0;}
	p.x = (l2.b*l1.c - l1.b * l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if(fabsl(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return 1;
}


long double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q)   { return dot(p-q,p-q); }
long double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

PT rotate(PT p, long double ag){
	return PT(p.x * cosl(ag) - p.y*sinl(ag), p.x *sinl(ag) + p.y * cosl(ag));
}


PT inter(PT p, PT q, PT A, PT B){
	long double a = B.y -A.y;
	long double b = A.x - B.x;
	long double c= B.x * A.y - A.x*B.y;
	long double u  = fabsl(a*p.x + b*p.y + c);
	long double v = fabsl(a*q.x + b*q.y + c);
	return PT( (p.x *v + q.x *u)/(u+v), (p.y * v + q.y *u )/(u+v)  );
}
vector<PT> Pcorte;
void cut(PT a, PT b, const vector<PT> &Q){
	Pcorte.clear();
	fr(i,0,	Q.size()){
		long double left1 = cross( PT(b) - PT(a), PT(Q[i]) - PT(a) ), left2 = 0;
		if( i != Q.size() -1 ) left2 = cross(PT(b) - PT(a), PT(Q[i+1]) - PT(a));
		if(left1 > -EPS ) Pcorte.pb(Q[i]);
		if(left1 * left2 < -EPS ) Pcorte.pb(inter(Q[i], Q[i+1], a, b));
		
	}
	if(!Pcorte.empty()  && !(Pcorte.back() ==Pcorte.front() ) ){
		Pcorte.pb(Pcorte.front());
	}
}

PT pivot;	
bool mycmp(pair<long double, long double> p1, pair<long double, long double> p2) {
	return cross(PT(p1.st - pivot.x, p1.nd- pivot.y), PT(p2.st - pivot.x, p2.nd - pivot.y)) < 0 ;
}



pair<long double, long double>  v2[105]; 
void ordena(vector<PT> &v ){
	int pos = 0;
	pivot = PT(inf , inf ); fr(i,0,v.size() ) if(cmp(v[i].y, pivot.y) == -1) pivot = v[i], pos = i;
	if(pos != 0 ) swap(v[pos], v[0] );
	fr(i,1,v.size()){ v2[i-1] = (mp(v[i].x, v[i].y));}
	sort(v2, v2+(v.size()-1), mycmp);	
	fr(i,1,v.size()) v[i] = v2[i-1];

}


long double area(const vector<PT> &p) {
  long double area = 0;
  for(int i = 0; i < p.size(); i++) { int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabsl(area / (long double)2.0 );
}
void pf(vector<PT> v1 ) { printf("[Print points] "); fr(i,0,v1.size()) cout << v1[i] << " ";  _	 }
vector<PT> v;
long double total = 0;


int f(long double y, bool tenso = 0){
	PT p1 = PT((long double)-101, y), p2 = PT((long double)101, y);
	cut(p1 , p2, v);
	//if(tenso){ printf("CORTE | "); pf(Pcorte);}
	//ordena(Pcorte);
	//if(tenso){ printf("CORTE ORD | "); pf(Pcorte);}
	long double A1 = area(Pcorte);
	long double A2 = total - A1;
	//if(tenso) printf("A1: %Lf | A2: %Lf\n", A1, A2);
	return cmp(A1, A2);

}

bool pointIn(PT p, PT a, PT b  ) {
	return cmp(sqrtl(dist2(b,a)), sqrtl(dist2(p,a))+sqrtl(dist2(p,b))) ==0;
}




long double go(bool tenso = 0){
	long double lo = inf, hi = -inf;
	fr(i,0,v.size() ) {
		if(cmp(v[i].y , hi) == 1 ) hi = v[i].y;
		if(cmp(v[i].y, lo) == -1 ) lo = v[i].y;
	}
	long double mid = inf;
	bool ok = 0;
	//if(tenso) printf("lo: %Lf\n", lo);
	fr(i,0,32){

		mid = (lo+hi)/(long double)2.0;
		int fm = f(mid);
		//if(tenso) printf("lo: %Lf | hi: %Lf | mid: %Lf | fmid: %d\n", lo, hi, mid, fm);		
		if(fm == -1 ) {
			hi = mid;
		}
		else if(fm == 1 ){
			lo = mid;
		}
		else{
		 	ok = 1;
			break;
		}

	}
	
	if(!ok) return inf;
	if(tenso){
		//printf("mid final: %.12Lf | e f(mid): \n", mid);
		//f(mid, 1);
		
	}
	PT i1 = PT(inf, inf) , i2 = PT(-inf, -inf) ;
	PT l1 = PT((long double)-5555, mid), l2 = PT((long double)5555, mid);
	PT p;
	fr(i,0,v.size()-1){
		if(intersectLine(toline(v[i], v[i+1]), toline(l1, l2), p, 0)){
			if(!pointIn(p, v[i], v[i+1])) continue;
			//if(tenso) printf("entrou! intersect \n");
			if(cmp(p.x, i1.x) == -1 ) i1 = p;
			if(cmp(p.x, i2.x) == 1) i2 = p;
		}
	}
	//if(tenso) cout << "I1 final: " << i1 << " | I2 final: " << i2 << endl;
	return sqrtl(dist2(i1, i2));
}

const int IT =60000;
long double taxa = PI / (long double)(IT);
long double angle = 0;

int N;

long double at	(long double a, long double b, long double c){
	long double s = (a+b+c)/(long double)2.0;
	return sqrtl(s*(s-a)*(s-b)*(s-c) );
}

int main (int argc, char const* argv[]){
	PT fixed = PT(0,0);	

	if(0){
	fixed = PT(1,0);	
	cout << rotate(PT(0,0)-fixed, -1.18)+fixed << endl;
	cout << rotate(PT(0,1)-fixed, -1.18)+fixed << endl;
	cout << rotate(PT(1,0)-fixed, -1.18)+fixed << endl;		
	
	cout << at(0.726441, 0.32145, 0.84) << endl;  
	return 0;
	}
	//long double sum = sqrtl(2 * ((3*3)/2.0) * tanl((PI/4.0)/2));	
	//printf("sum: %Lf\n", sum);	
	//return 0;
	long double x, y;
	sc1(N);
	fr(i,0,N){
		scanf("%Lf %Lf", &x, &y);
		v.pb(PT(x,y));
	}
	v.pb(v[0]);
	total = area(v);
	long double ans = inf;
	
	//cout << f(0 , 1) << endl;
	
	long double r;
	fixed = PT(0,0);
	//angle = 2.607521902480;
	
	//fr(l,0,v.size() )
///	fixed = v[0];
//	cout << f(0.77688005, 1) << endl ;
	//cout << go(1) << endl; 
	if(1) fr(i,0,IT){
		//printf("rotating %Lf \n", angle);
		
		fr(j,0,v.size()) v[j] = rotate(v[j], angle);
		
		
		//printf("first: "); cout << v[0] << endl; 
		//	pf(v);
		//cout << f(0.999934030347) << endl;
		//f(0.999934030347, 1);
		angle += taxa;
		if(1){
			r = (IT > 5 ) ? go(0) : go(1) ;
			if(cmp(r, inf) >= 0 ) continue;
			if(cmp(r, (long double)1e-9) <= 0 ) continue; 			
			//if(cmp(r,0.699807271457)==0 ) printf("FUdeu no angle: %.12Lf\n", angle);
		//	printf("r: %Lf\n", r);
			ans = min(ans, r);
		}
	}
	//}
	printf("%Lf\n", ans);
	
	
	
	return 0;
}
