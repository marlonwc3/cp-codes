#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

double a,b,c;
int main (int argc, char const* argv[])
{
	scanf("%lf", &a);
	scanf("%lf", &b);	
	scanf("%lf", &c);		
	
	a =  (2*(a) + 3*(b) + 5*(c)) /10;
	

	printf("MEDIA = %.1lf\n", a);
	
	return 0;
}
