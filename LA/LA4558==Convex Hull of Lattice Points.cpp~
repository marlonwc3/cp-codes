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

bool cmp(double a , double b  ){
	return fabs(a-b) > EPS; 
}

struct PT{
	double x, y;
	PT(){}
	PT(double _x, double _y){
		x = _x, y = _y; 
	}
	PT operator + (const PT& p)  const {return PT(x + p.x, y + p.y); }  
	PT operator - (const PT& p) const { return PT(x-p.x, y - p.y) ; }
	
	double operator %(const PT &p) const { return x*p.y -  y*p.x; }
	
	double operator == (const PT& p ) const { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
	
};

vector<PT> up, lo, pts;

bool cmp1(PT a , PT b){
	if( a.y > b.y ) return 1;
	else if (!cmp(a.y, b.y) ) {
		if( a.x < b.x ) return  1;
		return 0;
	}
	return 0;
}

void hull(){

	int tam = pts.size();
	fr(i,0,tam){
	
		while(up.size() >= 2 && (  up[up.size()-1] - up[up.size()-2]    )%(pts[i] - up[up.size()-2]) >= 0 ) up.pop_back(); 
		up.pb(pts[i]);
	
	}
	for(int i = tam-1; i >= 0; i--){
		while( lo.size() >= 2 && (lo[lo.size()-1] - lo[lo.size()-2]) %(pts[i] - lo[lo.size()-2]) >= 0 ) lo.pop_back();
		lo.pb(pts[i]);
	}

}





int main (int argc, char const* argv[]){

	int t, n, x, y, caso;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &caso);
		up.clear();
		lo.clear();
		pts.clear();
		
		scanf("%d", &n);
		
		fr(i, 0, n)
		{
			scanf("%d%d", &x, &y);
			pts.pb(PT(x, y));
		}
		
		sort(pts.begin(), pts.end(), cmp1);
		pts.erase(unique(pts.begin(), pts.end()), pts.end());
		hull();

		printf("%d %lu\n", caso, up.size()+lo.size()-2);
		
		fr(i, 0, up.size())
		{
			printf("%.0lf %.0lf\n", up[i].x, up[i].y);
		}
		fr(i, 1, lo.size()-1)
		{
			printf("%.0lf %.0lf\n", lo[i].x, lo[i].y);
		}
		
	
	}
	
	return 0;
}










