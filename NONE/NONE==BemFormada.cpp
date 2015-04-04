#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
stack<int> p;
char str[1000];
bool contar(){
	int s = strlen(str); char c;
	for (int i = 0; i < s; i += 1){
			c = str[i];
			if(c=='(' ) p.push(c);
			else {
				if(p.empty()) return 0;
				p.pop();
			}
	}
	return p.empty();
}

int main (int argc, char const* argv[])
{
	bool res;
	while(1){
		memset(str, 0, sizeof str);
		scanf("%s", str);
		if( str[0] == '0' ) break;		
		p = stack<int>();
		res = contar();
		if(res) printf("Valida\n");
		else printf("Invalida\n");
	}
	return 0;
}

