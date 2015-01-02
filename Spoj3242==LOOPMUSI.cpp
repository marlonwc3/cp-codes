#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fr(i, a, b) for(int i=a; i < b; i++)
#define pf(a) printf("%d\n", a)
using namespace std;

int n;

int des(int k){
	return (k+1)%n;
}

int arr[10005];
int sign, nsign;
int main (int argc, char const* argv[]) {
	int first, a, cont;
	while(1){
		scanf("%d", &n);
		if(!n)break;
		int ctd  = 0, cont=0;
		for(int i=0; i < n; i++){
			scanf("%d", &a);
			arr[i]=a;
			if(i>=1) {
				nsign = (arr[i] - arr[i-1] > 0 ) ? 1 : -1;
				if(i==1) sign = nsign;
				if(nsign != sign ) {
					cont++;	
					sign = nsign;
				}
			}

		}	
	
		nsign = arr[0] - arr[n-1] > 0  ? 1 : -1;
		if(nsign != sign ) {
			cont++;
			sign = nsign;
		}
		nsign = arr[1] - arr[0] > 0  ? 1 : -1;;
		if(nsign != sign ) {
			cont++;
			sign = nsign;
		}		
		
		printf("%d\n", cont);
		
	}


		return 0;
}
