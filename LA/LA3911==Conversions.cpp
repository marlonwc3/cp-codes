#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;

double res; 
double qt;
char op[5];
int main (int argc, char const* argv[])
{

	int n;
	scanf("%d", &n);
	for(int i=1; i <= n; i++){
		scanf("%lf", &qt); 
		scanf("%s", op);
		if(op[0]=='k') {
			res = qt*2.2046;
			printf("%d %.4lf lb\n", i, res);
		}
		else if(op[0] == 'l' && strlen(op) >= 2) {
			res = qt*0.4536;
			printf("%d %.4lf kg\n", i, res);			
		}
		else if( op[0] =='l') {
			res = qt*0.2642;
			printf("%d %.4lf g\n", i, res);			
		}
		else if(op[0] == 'g') {
			res = qt*3.7854;
			printf("%d %.4lf l\n", i, res);			
		}
	}

	return 0;
}
