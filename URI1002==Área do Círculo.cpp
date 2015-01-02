#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

double r;
int main (int argc, char const* argv[])
{
	scanf("%lf", &r);
	
	r=r*r*PI;
	printf("A=%.4lf\n", r);
	
	return 0;
}
