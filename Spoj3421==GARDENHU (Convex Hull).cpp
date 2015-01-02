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
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
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
typedef long double lb;

struct point{
	int x, y;
	point(){}
	point(int _x, int _y){x =_x, y=_y;}
	bool operator ==(const point &p) const{
		if(x==p.x && y == p.y) return 1;
		return 0;
	}
};
double cross(point p, point q, point r ) {
	return (r.x - q.x) *( p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}
bool collinear(point p, point q, point r){
	return fabs(  cross(p,q,r)  ) < EPS;
}
bool ccw(point p, point q, point r){
	return cross(p,q,r) > 0; 
}

point pivot(0,0);

double dist(point a, point b){
	return hypot(b.x - a.x , b.y - a.y);
}

bool angleCmp(point a, point b){
	if(collinear(pivot, a,b) ) return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return ( atan2(d1y, d1x) - atan2(d2y, d2x) ) < 0;
}

vector<point> CH(vector<point> P ){
	int i , N = (int)P.size();
	if(N<=3) return P;
	
	int P0 = 0 ;
	fr(i,1,N+1){
		if(P[i].y < P[0].y  || (P[i].y == P[P0].y && P[i].x > P[P0].x) ){// verificar
			P0 = i;
			
		}
	}
	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
	
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp);
	
	point prev(0,0), now(0,0);
	stack<point> S; S.push(P[N-1]); S.push(P[0]);
	i = 1;
	while(i < N ){
		now = S.top(); S.pop();
		prev = S.top();
		S.push(now);
		if( ccw(prev, now, P[i])  ) S.push(P[i++]);   
		else S.pop();
	}
	
	vector<point> ch;
	while(!S.empty()){
		ch.push_back(S.top()); S.pop();
	}
	return ch;
}


int main (int argc, char const* argv[]) {
	vector<point> v;
	int n, x, y;
	sc1(n);
	while(n--){
	
		sc2(x,y);	
		v.pb(point(x,y) 	);
	}
	
	v = CH(v);
	double sum = 0;
	fr(i,0,v.size()-1) {
		sum+=dist(v[i], v[i+1]);
	}
	int k = sum;
	printf("%d\n", k);
	
	return 0;
}






















