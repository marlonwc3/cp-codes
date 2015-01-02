#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;


char str[10];
int n,t,k, cont;
int main (int argc, char const* argv[]) {
	bool line=0;
	while(1){
		scanf("%d %d", &t, &n);
		if(!t && !n) break;
	
		n*=3;
		cont =0;
		for(int i=0; i <t;i++){
			scanf("%s %d", str, &k);
			cont+=k;
		}
		n-=cont;
		printf("%d\n", n);
//		line=1;
	}
	return 0;
}
