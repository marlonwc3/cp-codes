#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;

char str[1005];
int len;
int main (int argc, char const* argv[])
{
	int cont =0, t, num;
	bool res;
	while(1){
		scanf("%s", str);
		len = strlen(str);
		if(len==1 && str[0]=='0') break;
		cont=0; int t = len-1;
	
		if(len > 1) {
			for(int i=0; i <len; i++){
				num =  str[i]-'0';
				if(t%2==1) {
					num *= 10;
				}			
				cont += num;
				cont%=11;
				t--;
			}
			res = (cont%11)==0;
		}
		else res=0;
		if(res) printf("%s is a multiple of 11.\n", str);
		else printf("%s is not a multiple of 11.\n", str);
	}	
		
		
	return 0;
}
