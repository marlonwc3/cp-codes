#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <string>
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
#define clr(a, b) memset(a, b, sizeof(a)) // tati 

using namespace std;
typedef vector<int> vi;
typedef   long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);


struct PT{
	double x, y;
	PT(){}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y);}
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y);}
	PT operator * (double c) const { return PT(x*c, y*c);}
	PT operator / (double c) const { return PT(x/c, y/c);}
};

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y;}
double dist2(PT p, PT q) { return dot(p-q, p-q); }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }

ostream &operator <<(ostream &os, const PT &p ){
	os << "(" << p.x << ", "<< p.y << ")"; 
}
int N;  
PT polygon[55];
bool pointIn ( PT q){
	bool c = 0;
	fr(i, 0,N){
		int j = (i+1)%N;
		if(   (polygon[i].y <= q.y && q.y < polygon[j].y || polygon[j].y <= q.y && q.y < polygon[i].y ) && q.x < polygon[i].x + (polygon[j].x - polygon[i].x) * (q.y - polygon[i].y)/(polygon[j].y - polygon[i].y )   )  c = !c;
	}	
	return c;
}

PT project(PT a, PT b, PT c ){
	return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}


bool on(PT q){
	fr(i,0,N){
		if(dist2(project(polygon[i], polygon[(i+1)%N] ,q ), q ) < EPS ){
			return 1;
		}
	}
	return 0;
}

struct tripla{
	int a, b, c;
	tripla(){}
	tripla(int _a, int _b, int _c ){ a=_a, b=_b, c=_c; }
};
vector<tripla> todos;
int main(){
	int ytop, ybottom;
	int xleft, xright, x ,y;

	int caso;
	sc1(caso);
	fe(t,1,caso){
		sc1(N); // data set number, lixo ! (oi rael! ) 
		sc1(N);
		ytop = -inf, ybottom = inf;
		xleft = inf, xright = -inf; 
		fr(i,0,N){
			scanf("%d %d", &x, &y);

			polygon[i] = PT(x,y);
			if( x < xleft ) xleft = x;
			if( x > xright ) xright = x;
			if( y > ytop ) ytop = y;
			if( y < ybottom ) ybottom = y; 
		}
		//printf("ytop: %d | ybottom: %d | xleft: %d | xright: %d\n", ytop,ybottom, xleft, xright ) ; 
		int cnt;
		PT  p;
		todos.clear();
		for(int j = ytop; j >= ybottom; j-- ){ 
			cnt = 0 ;
			int menor = inf, maior = -inf; 
			fe(i,xleft, xright ) {	
				p = PT(i, j);
				if(on(p)) continue;
				if(pointIn(p) ){
					if( menor == inf ) {
						menor = i;
					}
					if ( i > maior ) {
						maior = i; 
					}
					cnt++;
				}
			}
			if(cnt) {
			//printf("j: %d | qtd: %d | -> ", j, cnt);
				todos.pb(tripla(j, menor, maior ));

			}
		}
		printf("%d %d\n", t, int(todos.size()) );
		fr(i,0,todos.size()){
			printf("%d %d %d\n", todos[i].a, todos[i].b, todos[i].c) ;
		}
	
	
	
	}
	
	











	return 0;
}












