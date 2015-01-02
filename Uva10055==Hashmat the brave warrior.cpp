#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long int lld;
lld a, b;
int main (int argc, char const* argv[]) {
	while(scanf("%lld %lld", &a, &b) >0){
		a = fabs(a-b);
		printf("%lld\n", a);
	}
	return 0;
}
