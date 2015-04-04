#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream> 
#include <vector>
#include <queue>
#include <map>
#define mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<char, char> cc; // first == L , second == R;


char matrix[3][10] = {
	{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, 
	{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'}, 
	{'z' ,'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'}

};

char str[105];

int main (int argc, char const* argv[])
{	
	char c;
	scanf("%c", &c);
	int desY = (c=='R') ? -1 : 1;
	int  len;
	scanf("%s", str);
	len = strlen(str);
	int x, y;
	bool found=0;
	for(int i=0; i <len; i++){
		c = str[i];
		found =0;
		
		for(int j=0; j <3; j++){	
			for(int l=0; l < 10; l++){
				if(matrix[j][l] == c){
					found =1;
					x = j;
					y = l;
					break;
				}
			}
		}
		
		printf("%c", matrix[x][y+desY]);
	}
	printf("\n");
	
	
	return 0;
}
