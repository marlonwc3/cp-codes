#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

lld resQnt;
lld qnt(lld n){
	if(!n) return 0; resQnt=0;
	while(n){ resQnt += n%10; n/=10; }
	return resQnt;
}
int f(lld n){
	while(n>=10){
		n = qnt(n);	
	}
	return n;
}
int main (int argc, char const* argv[]) {	
	lld n; int res;
	while(1){
		scanf("%lld", &n);
		if(!n) break;
		res = f(n);
		printf("%d\n", res);
	}
	return 0;
}
