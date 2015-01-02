#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;


int gm[25][25], c, m;

int pd[25][205];
//cont initially ==m
int bt(int cont, int g){
	if(cont < 0 ) return 0;
	if(g>=c) return m-cont;
	if(pd[g][cont]!=-1) return pd[g][cont];
	int res=0, s = gm[g][0]; 
	for(int i=1; i <= s; i++){
		res = max(res,  bt(cont-gm[g][i],g+1)  );	
	}		
	return pd[g][cont]=res;
}

int main (int argc, char const* argv[]) {
	int n, k, a;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &m, &c);
		memset(pd, -1, sizeof pd);
		memset(gm, 0, sizeof gm);
		for(int i=0; i < c; i++){
			scanf("%d", &k);
			gm[i][0]=k;
			for(int j=1; j<=k; j++){
				scanf("%d", &gm[i][j]);
			}		
		}
		k = bt(m,0);
		if(!k) printf("no solution\n");
		else printf("%d\n", k);
	}
	return 0;
}
