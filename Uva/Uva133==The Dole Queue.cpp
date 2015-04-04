#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int n, m, k, livres;
bool mark[25];

int des(int a, bool sent){ // sent ==1 -> counter-clockwise
	if(sent) a = (a==n) ? 1 : a+1;
	else a = (a==1) ? n : a-1;
	return a;
	
}
void p(int a){
	if(a>=100) printf("%d", a);
	else if(a>=10) printf(" %d", a);
	else printf("  %d", a);
}

int f(int ini, int sent, int jc){ // jc == já contou
	int i=ini, cont=0, total=(sent)?k:m;
	while(cont < total){
		cont+=!mark[i];
		i = des(i,sent);
	}
	i = des(i, !sent); // descrementa para posição do ultimo
	if(jc) {
		if(jc!=i) p(i);
	}
	else p(i);
	return i;
}

int main (int argc, char const* argv[])
{
	memset(mark, 0, sizeof mark);
	int inia, inib, a, b;
	bool line=0;
	while(1){
		scanf("%d %d %d", &n, &k, &m);
		if(!n && !m && !k) break;
		//if(line) printf("\n");
		memset(mark, 0, sizeof mark);		

		livres=n; inia=1; inib=n;
		while(livres > 0){

			a = f(inia, 1, 0); inia  = des(a,1); livres--;
			if(livres){
				b = f(inib, 0, a); inib = des(b,0);
				livres-=(a!=b);
			}
			else b=a;
			mark[a]=mark[b]=1;
			if(livres) printf(",");
		}
		printf("\n");
//		line=1;
	}
	
	return 0;
}

