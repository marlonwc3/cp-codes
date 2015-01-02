#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define plld(a) printf("%lld\n", a)
using namespace std;

typedef long long int lld;

lld memo[1000005];
lld f(lld n){
	if(n <= 1000000 && memo[n] != -1 ) return memo[n];
	lld k;	
	if(n==1) return 1;
	if(n%2) k = 1 + f((n+n+n)+1); // n is odd
	else k = 1 + f(n/2); // n is even
	if(n <= 1000000 ) memo[n] = k;
	return k;
}

int main (int argc, char const* argv[]) {
	lld a, b, k, aux;
	bool swap;
	memset(memo, -1, sizeof memo);
	while(scanf("%lld %lld", &a, &b) > 0 ) {
		swap=0;
		if(a > b) {
			aux = a; a=b; b=aux; swap=1;
		}
	
		k = 0;
		for(lld i=a; i <=b; i++) k = max(k, f(i));
		if(!swap) printf("%lld %lld %lld\n", a, b, k );
		else printf("%lld %lld %lld\n", b, a, k );
	}
	return 0;
}
