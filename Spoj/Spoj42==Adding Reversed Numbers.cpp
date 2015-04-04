#include <bits/stdc++.h>
using namespace std;
char strres[25], a[25], b[25];
int ires, minLen, maxLen;
void f(){
	int lenA = strlen(a);
	int lenB = strlen(b);
	minLen = min(lenA, lenB);
	maxLen = (minLen == lenA) ? lenB : lenA;
	if(minLen == lenA) for(int i=minLen; i < maxLen; i++) a[i]='0';	
	if(minLen == lenB) for(int i=minLen; i < maxLen; i++) b[i]='0';
	ires=0;
	int na, nb, sumprox=0;
	for(int i=0 ; i < maxLen; i++){
		na = a[i]-'0';
		nb = b[i]-'0';
		na += nb;
		if(sumprox) {
			na++;
			sumprox=0;	
		}
		if(na >= 10 ) {
			na-=10;
			sumprox++;
		}
		if(!na && !ires) continue;		
		strres[ires++] = na+'0'; 
	}
	if(sumprox) {
		strres[ires++] = '1';
	}
}
int main (int argc, char const* argv[]) {
	int n;
	scanf("%d", &n);
	while(n--){
		memset(strres, 0 , sizeof strres);
		scanf("%s %s", a,b);
		f();
		printf("%s\n", strres);
	}
	return 0;
}

