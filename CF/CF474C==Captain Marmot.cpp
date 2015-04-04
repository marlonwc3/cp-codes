#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;

struct point
{
	int x, y, rot;
	point(){}
	point(int _x, int _y){
		x=_x; y=_y; rot=0;}
	point(int _x, int _y, int _rot){
		x=_x; y=_y; rot=_rot;}
		
	bool operator == (const point &p) const{
		return x==p.x && y == p.y;
	}	
		
};
typedef vector<point> vp; // vector point
int distPoint(point a, point b){
	return sqrt( (a.x - b.x)*(a.x - b.x)  + (a.y - b.y)*(a.y - b.y)    );
}
int pesc(point a, point b){
	return  (a.x * b.x) + (a.y * b.y);
}
int perpend(point a, point b, point c, point d){
	return pesc(  point(b.x - a.x, b.y - a.y), point( d.x - c.x, d.y - c.y)   ) == 0 ;
}
 
point rotation(point a, point ref){
	// translado
	int x = a.x - ref.x;
	int y = a.y - ref.y;
	int aux = x;	
	x = -y;
	y = aux;	
	x +=  ref.x;
	y += ref.y;
	return point (x, y);
}

struct mole {
	point points[4];
	mole(){}
};

vp spoints;
bool isSquare(){
	point a, b, c;
	if(spoints[0] == spoints[2] || spoints[1]==spoints[3] ) return 0;
	for(int i=0; i < 3; i++){
		a = spoints[i];
		b = spoints[i+1];
		c = spoints[(i+2)%4 ];
		if(a==b || a==c || b==c ) return 0;
		if( distPoint(b, a) !=  distPoint(c,b) ) return 0;
		if ( !  perpend(a,b, b, c )    ) 	return 0;
	}
	return 1;
}



mole reg[105][4]; 
int regAtual;
bool mark[4]; 
int bt(int n, int cont){
	if(n>=4) { 
		if( isSquare()) { 


			return cont;
		}
		return inf;
	}
	int res=inf;
	point p;
	for(int i=0; i < 4; i++ ) {
		if(mark[i]) continue;
		mark[i]=1; // marco o mole atual
		for(int j=0; j < 4; j++){
			p = reg[regAtual][i].points[j];
			spoints.push_back(p);		
			res = min(res,  bt(n+1, p.rot + cont) ) ;
			spoints.pop_back();
		}
		mark[i]=0;
	}
	return res;
}

int n;
int main (int argc, char const* argv[]) {
	scanf("%d", &n);

	int x, y, rx, ry, res;
	point p, ref;
	
	for(int i=0 ; i < n; i++){
		regAtual = i;
		for(int j=0; j < 4; j++){
			scanf("%d %d %d %d", &x, &y, &rx, &ry);
			p = point(x, y);
			reg[i][j].points[0] = p;
			ref = point( rx, ry);

			for(int k = 1; k <= 3; k++){ 				
				p = rotation(p, ref);
				p.rot = k;	

				reg[i][j].points[k] = p;				
			
				
				
			}	
		} // terminou de ler um regimento
		memset(mark, 0, sizeof mark);
		spoints.clear();
		
		
		
		res = bt(0,0);
		if(res>=inf || res<=-1) printf("-1\n");
		else printf("%d\n",res);
	
	}
	
	
	
	return 0;
}

