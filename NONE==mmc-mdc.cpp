#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;


int mdc(int a, int b){ // algoritmo de euclides
	if( !b )  return a;
	return mdc(b, a%b);
}

int mmc(int a, int b){
	return (a*b)/mdc(a,b);
}

int main (int argc, char const* argv[]) {
	int a, b;
	
	
	a=1000;
	b=17;
	
	printf ( "mdc(%d, %d): %d \n", a, b, mdc(a, b)  );
	
	a=6;
	b=15;
	
	printf("mmc(%d, %d): %d\n", a, b, mmc(a,b) );
	
	return 0;
}
