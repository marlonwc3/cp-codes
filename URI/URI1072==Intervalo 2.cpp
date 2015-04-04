#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;


int n, a,b;
int main (int argc, char const* argv[]) {
	
	
	scanf("%d", &n);
	int in=0, out=0;
	for(int i=0; i < n; i++){
		scanf("%d", &a);
		if(a >=10 && a <= 20) in++;
		else out++;
	}
	printf("%d in\n", in);
	printf("%d out\n", out);	
	return 0;
}


