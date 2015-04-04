#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int arr[12];
int n = 6;
int main (int argc, char const* argv[])
{		
	int nums[7];
	while(scanf("%d %d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]) > 0){
		memset(arr, 0, sizeof arr);
		int k;		
		for(int i=0; i < 6; i++){
			k = nums[i];
			arr[k]++;
		}	
		bool perna = false;
		bool el = false;
		bool bb, bh;
		for(int i=1; i <=9; i++){
			if(arr[i] >= 4){
				arr[i]-=4; 
				perna = 1;

			}
			if(arr[i] >=2 )  {
				arr[i] -= 2; 
				el = 1;
			}
			if(arr[i] == 1 ) {
				if(bb) {
					bh=1;
				}
				else bb=1;
				arr[i]-=1;
			}
		}	
		if(perna) {
			if(el){
				printf("Elephant\n");
			}
			else if(bb && bh){
				printf("Bear\n");
			}
			else printf("Alien\n");
		
		}
		else printf("Alien\n");	
			
	}
	return 0;
}

