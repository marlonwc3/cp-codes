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

int m, k,n, sum=0;
int arr[1000005];
int main (int argc, char const* argv[])
{
	memset(arr, 0, sizeof arr);
	scanf("%d", &n);
	for(int i=1; i <=n; i++){
		scanf("%d", &k);
	
		for(int j=sum+1; j <= sum+k; j++){
			arr[j] = i;
		}
		sum+=k;
	}
	
	scanf("%d", &m);	
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		printf("%d\n", arr[k]);
	}
	
	
	return 0;
}
