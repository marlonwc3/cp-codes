#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

int main (int argc, char const* argv[]) {
	lld res;
	int hd, md, h, m;
	
	while(1){
		scanf("%d %d %d %d", &h, &m, &hd, &md);
		if(!h && !m && !hd && !md) break;
		if( hd < h || (hd==h && md < m) ) {
			//lld a = hd*60 + md, b = (h*60 + m), c= (23*60 + 59);
			//printf("a -> %lld - b:%lld - c:%lld\n", a, b, c);
			res = (hd*60 + md) +  (   (23*60 + 59) - (h*60 + m) );
			res++; // 1 minuto de 23:59 para 00:00
		}
		else if(hd==h && md == m ) res =0; 
		else res = (hd*60 + md) - (h*60 + m);
		printf("%lld\n", res);
	}
	
	return 0;
}
