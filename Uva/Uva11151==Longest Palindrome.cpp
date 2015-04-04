#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

char str[1005];
int pd[1005][1005];


int pal(int a, int b){

  if(a==b) return 1;
  if(a+1 == b) return (str[a]==str[b]) ? 2 : 1;
  if(pd[a][b] != -1 ) return pd[a][b];
  if(str[a]==str[b]) {
    return pd[a][b] = 2 + pal(a+1, b-1);
  }
  
  return pd[a][b] = max(pal(a+1, b),pal(a, b-1 )  );
}


int main (int argc, char const* argv[]) {
  
  int t,b, res;
  scanf("%d", &t);
  getchar();  
  while(t--){
    memset(pd, -1, sizeof pd);
    gets(str);
    b = strlen(str)-1;
    res = pal(0, b);
    printf("%d\n", res);
  }
  
  
  return 0;
}
