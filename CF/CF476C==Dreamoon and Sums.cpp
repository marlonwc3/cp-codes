#include <bits/stdc++.h> 
#define MOD 1000000007
#define _ printf("\n");
#define pf(a) printf("%d ", a);
using namespace std;

typedef long long int lld;

int main (int argc, char const* argv[]) {
	lld a, b;
	
	scanf("%I64d %I64d", &a, &b);


	lld w = (( (b%MOD )*( (b-1)%MOD ))/2 )%MOD ; 
	lld z = ((( (a%MOD) +1  )*( a%MOD ) )/2)%MOD;
	z = (z * (b%MOD) )%MOD;
	z = (z+ (a%MOD) )%MOD;
	z = (z*w)%MOD;
	
	
	printf("%I64d\n", z);

	
		

	
	return 0;
}
