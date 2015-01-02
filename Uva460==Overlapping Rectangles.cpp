#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
struct Point{
	int x, y;
	Point(){}
	Point(int _x, int _y){
		x = _x;
		y = _y;
	} };

struct Rect{
	Point a,b;
	Rect(){}
	Rect(Point _a, Point _b){a=_a; b=_b;} };

bool pin(Rect r, Point c){ // c in rect (a,b)
	Point a =r.a, b = r.b;
	return (c.x >= a.x && c.y >= a.y && c.x <= b.x && c.y <= b.y);
}
bool colinear(Point a, Point b){return a.x == b.x || a.y == b.y;}
int main (int argc, char const* argv[]) {
	int t, xa, ya, xb, yb;
	Point a, b;
	Rect r1, r2;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		a = Point(xa, ya);
		b = Point(xb, yb);
		r1 = Rect(a,b);
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		a = Point(xa, ya);
		b = Point(xb, yb);
		r2	 = Rect(a,b);	
		a = Point( max(r1.a.x, r2.a.x), max(r1.a.y, r2.a.y)   );
		b = Point( min(r1.b.x, r2.b.x), min(r1.b.y, r2.b.y) );
		if( ! pin(r1, a) || !pin(r1, b) || !pin(r2, a) || !pin(r2,b) )  printf("No Overlap\n");
		else if(colinear(a,b))  printf("No Overlap\n");		
		else printf("%d %d %d %d\n", a.x, a.y, b.x, b.y);
		if(t) printf("\n");
	}
	return 0; }

