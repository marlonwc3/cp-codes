#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;


int n, h;

double a;
int main (int argc, char const* argv[])
{
	scanf("%d", &n);
	scanf("%d", &h);	
	scanf("%lf", &a);		
	
	a = a*h;
	

	printf("NUMBER = %d\n", n);
	printf("SALARY = U$ %.2lf\n", a);
	
	return 0;
}
