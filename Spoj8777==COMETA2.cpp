#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;



int main (int argc, char const* argv[]) {
	int n;
	scanf("%d",&n);
	for(int i=1986; i <= 11000; i+= 76){
		if(i > n ) {n = i; break;}
	}
	printf("%d\n", n);	
	return 0;
}
