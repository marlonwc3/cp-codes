#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;


int n;
int main (int argc, char const* argv[]) {
	
	
	scanf("%d", &n);
		
	if(n==61){
		printf("Brasilia\n");
	}
	if(n==71) printf("Salvador\n");
	if(n==11) printf("Sao Paulo\n");
	if(n==21) printf("Rio de Janeiro\n");
	if(n==32) printf("Juiz de Fora\n");
	if(n==19) printf("Campinas\n");
	if(n==27) printf("Vitoria\n");
	if(n==31) printf("Belo Horizonte\n");
	
	return 0;
}

