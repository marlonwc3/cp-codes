#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

bool prime(ll n){

	if(n==1 ) return 0;
	if(n==2) return 1;
	ll k = sqrt(n);	
	for(ll i=2; i <= k; i++){
		if ((n%i)==0) return 0; 
	}
	return 1;

}


int main (int argc, char const* argv[]) {

	ll n;
	scanf("%lld", &n);
	if(prime(n) || n==1) printf("N\n");
	else printf("S\n");

	return 0;
}
