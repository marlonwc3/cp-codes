include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

double a,b;
int main (int argc, char const* argv[])
{
	scanf("%lf", &a);
	scanf("%lf", &b);	
	
	a =  (3.5*(a) + 7.5*(b) ) /11;
	

	printf("MEDIA = %.5lf\n", a);
	
	return 0;
}
