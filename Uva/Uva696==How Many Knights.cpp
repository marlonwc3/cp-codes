#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int memo[505][505];
int n, m;

int main (int argc, char const* argv[])
{	
	memset(memo, -1, sizeof memo);
	int res, k, a; 
	bool mod;

	while(1){
		scanf("%d %d", &n, &m);
		if(!n && !m ) break;
		res = -1;
		
		if(memo[n][m] != -1 ) res = memo[n][m];
		else if(n == 1 || m == 1) {
			res = max(n, m);
		}
		else if(n==2 && m == 2) res = 4;
		else if(n ==2 || m == 2  ){
			a = max(n,m);
			mod=0;
			if(a%2) {
				mod=1; a--;
			}
			res = ceil(a/4.0)*4;
			if(mod) {
				if( ( a/2 )%2 == 0){
					res += 2;
				}						
			}
		
		}
		else {
			res = ceil ( (n*m)/2.0  ); 
		}
		if(memo[n][m] == -1 ) {
			memo[n][m] = res;
			memo[m][n] = res;	
		}

		printf("%d knights may be placed on a %d row %d column board.\n", res, n, m);	
		
	}
	

	return 0;
}

