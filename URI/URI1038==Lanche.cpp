#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;


double find(int a){
	if(a==1) return 4.0;
	if(a==2) return 4.5;
	if(a==3) return 5.0;
	if(a==4) return 2.0;
	if(a==5) return 1.5;
	
}
int a, b;
double res;

int main (int argc, char const* argv[])
{
	scanf("%d %d", &a, &b);
	res = b*find(a);
	printf("Total: R$ %.2lf\n", res);
	return 0;
}
