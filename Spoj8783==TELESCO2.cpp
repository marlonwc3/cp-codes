#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

/*
emissão * área do telescópio * 10 >= 40.000.000
*/
typedef long long int lld;
lld obj = 40000000;
lld cont=0, e, n, a;
bool ok(lld a){
	return (e*a)>=obj;
}
int main (int argc, char const* argv[]) {

	while( scanf("%lld", &e) > 0 ) {
		cont=0;
		scanf("%lld", &n);
		for(int i=0 ; i < n; i++){
			scanf("%lld\n", &a);
			cont+= ok(a);
		}
		printf("%lld\n", cont);
		
	}
	

	return 0;
}

