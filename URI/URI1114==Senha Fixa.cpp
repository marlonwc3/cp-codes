#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;


double q;
long long int a;


int main (int argc, char const* argv[]){
	bool valid  = 0 ;
	while(1){
		scanf("%lld", &a);
		if(a==2002) valid=1;
		if(valid){
			printf("Acesso Permitido\n");
			break;
		}	
		else printf("Senha Invalida\n");
	
	}
	return 0;
}
