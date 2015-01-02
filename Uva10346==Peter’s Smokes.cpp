#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

/*
k=10
n=173
-----
173 -> 170 cigarros - > f(170/10) sobram 3 gimbas
17 -> 17 cigarros - > f(17/10) sobram 7 gimbas
1 cigarro -> 1 cigarro -> f(1/10) sobram 1 gimba
0 cigarro -> 0 < - 


173 cigarros , 0  gimbas -> 173 cigarros + f( 173/10, 173%10  )
17 cigarros, 3 gimbas -> 17 cigarros + f(17/10, 3+17%10)
1 cigarro, 10 gimbas -> 1 cigarro + (10 gimbas == 1 cigarro) + f(2/10, 2%10)

k;
f(c,g):
	if(g>=k) {
		c+=g/k
		g%=k
	}
	if(c==0) return 0;

	return c + f( c/k, g+ (c%k)  );


1 gimba, 1 g

return 1 + f( 1/2 , 1 + (1%2)) 

	
*/

typedef long long int lld;

lld k;
lld f(lld c, lld g){
	if(g>=k ){
		c += g/k;
		g%=k;
	}
	if(!c) return 0;
	return c + f( c/k, g + c%k  );
}


int main (int argc, char const* argv[]) {
	lld n;
	while(scanf("%lld %lld", &n, &k) > 0){
		n = ( k > n) ? 0 : f(n, 0);
		printf("%lld\n", n);
	}
	return 0;
}

