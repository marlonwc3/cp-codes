#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream> 
using namespace std;


long long int a, b;
long long int c, d;
double x, y;
int main (int argc, char const* argv[]) {
	scanf("%lld %lld", &a, &b);
	scanf("%lld %lld", &c, &d);
	
	x = ( a-c )*(a-c) + (b-d)*(b-d);
	x = sqrt(x); 
	

	printf("%.4lf\n", x) ;
	return 0;
}
