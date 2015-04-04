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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%llld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%lld %lld ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

int cmp(double a, double b) { 
	if(fabs(a-b) <= EPS ) return 0;
	return a>b?1:-1;
}

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator == (const PT &p) const{ return cmp(x, p.x)==0 && cmp(y, p.y)==0;}
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

bool mycmp(PT a, PT b){
	if(cmp(a.x, b.x)==0) return cmp(a.y, b.y) == -1;
	return cmp(a.x, b.x) == -1;	
}


int main (int argc, char const* argv[]){
	double a,b,c,d,e,f,g,h;
	PT p1, p2, p3 , p4;
	int pos;
	vector<PT> vp;
	PT v1, v2;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a,&b,&c,&d,&e,&f,&g,&h)==8){
		vp.clear();
		p1 = PT(a,b);
		p2 = PT(c,d);
		p3 = PT(e,f);
		p4 = PT(g,h);						
		vp.pb(p1); vp.pb(p2); vp.pb(p3); vp.pb(p4); 
		sort(vp.begin(), vp.end(), mycmp);
		fr(i,0,3) {if(vp[i]==vp[i+1]) {pos=i; break;}}
		p3 = vp[pos];
		vp.erase(vp.begin()+pos);
		vp.erase(vp.begin()+pos);
		p1 = vp[0], p2 = vp[1];		
		//cout << "P1:" << p1 << " P2: " << p2 << " P3: " << p3 << endl;
		v1 = p1-p3;
		
		p2 = p2 + v1;
		printf("%.3lf %.3lf\n", p2.x, p2.y);
		
		
	}
	
	
	
	return 0;
}























