#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int main (int argc, char const* argv[]) {
	int t;
	long long int a, b, c;
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if(	/*Existencia de triangulo*/
			(fabs(b-c) < a && a < (b+c) ) && 
			(fabs(b-a) < c && c < (b+a)) &&
			fabs(c-a) < b && b < (c+a)
		) {
			if(a!=b && a!=c && b!=c ) printf("Case %d: Scalene\n", i);			
			else if(a==b && a==c && b==c) printf("Case %d: Equilateral\n", i);			
			else printf("Case %d: Isosceles\n", i);
		}
		else  printf("Case %d: Invalid\n", i);
	}
	return 0;
}
