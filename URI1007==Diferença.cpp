#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream> 
using namespace std;


long long int a,b, c, d;
int main (int argc, char const* argv[]) {
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);
	scanf("%lld", &d);		
	
	a*=b;
	c*=d;
	a-=c;
	
	printf("DIFERENCA = %lld\n", (a));
	return 0;
}
