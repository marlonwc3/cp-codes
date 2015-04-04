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
	scanf("%d", &a);
	scanf("%lf", &x);
	x = a/x;
	

	printf("%.3lf km/l\n", x) ;
	return 0;
}
