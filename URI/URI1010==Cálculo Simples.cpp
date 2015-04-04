#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream> 
using namespace std;


int a, b;
int c, d;
double x, y;
int main (int argc, char const* argv[]) {
	scanf("%d %d %lf", &a, &b, &x);
	
	x*=b;
	
	scanf("%d %d %lf", &c, &d, &y);
	y*=d;
	
	x +=y;	

	printf("VALOR A PAGAR: R$ %.2lf\n", x) ;
	return 0;
}
