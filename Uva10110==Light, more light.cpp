#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#define fr(i,a,b) for(int i=a; i<b; i++)
#define pf(a) printf("%d\n", a)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d", &a, &b)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
vi primes;



bool mark[65735];
int crivemax=65735;
void foocrive(){ // not mark == prime
	memset(mark, 0, sizeof mark);
	mark[1] = 1;
	for(int i=2; i <= crivemax;i++ ){
		if(mark[i]) continue;
			primes.push_back(i);
			for(int j=i+i; j <= crivemax; j+=i){
				mark[j]=1;
			}
	}
}

lld primeFactor(lld n){
	int res = 1;
	int pindex=0; lld cont=0;
	lld pf=primes[pindex];
	while(n != 1 && pf*pf <= n){
		cont=0;

		while(n%pf==0){
			n/=pf;

			cont++;
		}
		if(cont>0) {
			res *= (cont+1);
			res%=2;
		} 
		 pindex++; 

		pf = primes[pindex];
	}
	if(n!=1) {
		res*=2;
	}
	return res%2;
	
}	


int main (int argc, char const* argv[])
{
	foocrive();
	lld n;
	while(1){
		scanf("%lld", &n);
		if(!n) break;
		if( n < 65735 && !mark[n] ) n=0;
		else n = primeFactor(n);
		if(!n) printf("no\n");
		else printf("yes\n");
	
	}


		return 0;
}
