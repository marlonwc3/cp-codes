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
	scanf("%d %d %d", &a, &b, &c);
	
	a = max(a,b);
	a = max(a, c);
	

	printf("%d eh o maior\n", a) ;
	return 0;
}
