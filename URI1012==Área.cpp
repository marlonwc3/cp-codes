#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;


int n, h;

double a,b,c, k;
char str[10005];
int main (int argc, char const* argv[])
{
	//scanf("%s", str);
	scanf("%lf", &a);	
	scanf("%lf", &b);		
	scanf("%lf", &c);			
	
	k = (a*c)/2;
	printf("TRIANGULO: %.3lf\n", k);
	k= PI*c*c;
	printf("CIRCULO: %.3lf\n", k);	
	k = ((a+b)*c)/2;
	printf("TRAPEZIO: %.3lf\n", k);
	k = b*b;
	printf("QUADRADO: %.3lf\n", k);	
	k = a*b;
	printf("RETANGULO: %.3lf\n", k);		
	
	
	
/*
TRIANGULO: 7.800
CIRCULO: 84.949
TRAPEZIO: 18.200
QUADRADO: 16.000
RETANGULO: 12.000

*/	
	
	
	return 0;
}
