#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int colunas[10];

int cont=0;

int dmod(int a, int b){
	a -=b;
	return (a < 0) ? a*-1 : a;
}

int backtracking(int ini){
	if(ini >= 8) {
		cont++;
		return 0;
	}
	bool ok;
	for(int i=0; i < 8; i++){	
		ok=true;
		for(int j=0; j < ini; j++){ //achar um i
			int emJ = colunas[j];	
			if( dmod(emJ, i) == dmod(ini, j)  || (emJ == i)  ) {
				ok =false; break;
			}
		}		
		if(!ok) continue;	
		colunas[ini]=i;	
		backtracking(ini+1);
	}	
	colunas[ini]=0;
	return 0;
}



int main (int argc, char const* argv[]) {

	memset(colunas, 0, sizeof colunas);
	backtracking(0);
	printf("cont:%d\n", cont);
	return 0;
}






