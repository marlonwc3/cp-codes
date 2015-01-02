#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;


int n, h;

double a,b;
char str[10005];
int main (int argc, char const* argv[])
{
	//scanf("%s", str);
	scanf("%lf", &a);	
	//scanf("%lf", &b);		
	
	a = (4.0/3)*PI*a*a*a;
	
//	a += b*0.15;


	printf("VOLUME = %.3lf\n", a);
	
	return 0;
}
