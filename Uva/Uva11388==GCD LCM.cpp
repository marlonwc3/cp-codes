#include <bits/stdc++.h> 
using namespace std;

int main (int argc, char const* argv[]) {
	int t, g, l;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &g, &l);
		if(l%g==0) printf("%d %d\n", g, l);
		else printf("-1\n");
	}
	return 0;
}
