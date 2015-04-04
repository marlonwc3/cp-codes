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

double rad(double angle){
	return (angle*PI)/180.0;
}

int cmp(double a,  double b =0.0){
	if(fabs(a-b) <= EPS ) return 0;
	return a>b ? 1:  -1;
}


int main (int argc, char const* argv[]) {
	int l, w , x, y, r, a , v, s;
	double vx, vy, sf, xf, yf;
	int q;
	double resto;
	double rx, ry;
	while(1){
		sc4(l,w,x,y); sc4(r, a, v, s);
		if(!l && !w && !x && !y && !r && !a && !v && !s) break;
		x -= r, y -= r;
		vx = v*cos(rad(a));
		vy = v*sin(rad(a));
		l -= 2*r;
		w -= 2*r;
		
		xf = x + vx*s; xf = fabs(xf);
		q = floor(xf/(l+0.0));
		//printf("xf : %lf|  vx: %lf | q: %d\n", xf, vx, q);
		rx = xf - q*l;
		if(q%2==1){
			rx = l - rx;
		}
		
		rx += r;
		
		yf = y + vy*s; yf = fabs(yf);
		q = floor(yf/(w+0.0));
	
		ry = yf - q*w;
		if(q%2==1){
			ry = w - ry;
		}

		ry += r;		
		
		printf("%.2lf %.2lf\n", rx, ry);
		
	}
	
	
	
	return 0;
}















