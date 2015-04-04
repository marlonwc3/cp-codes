#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#define LSOne(S) (S & (-S))
using namespace std;

typedef vector<int> vi;
vi arr;
int maior;




int ft_rsq(int b){
	int sum=0;
	for(;b; b-= LSOne(b)){
		sum+=arr[b];
	}
	return sum;
}

int ft_rsq(int a, int b){
	return ft_rsq(b) - (a==1 ? 0 : ft_rsq(a-1))  ;
}

void ft_adjust(int k, int v){
	int s = arr.size();
	for(; k <= s; k+= LSOne(k)){
		arr[k]+=v;
	}
}


int main (int argc, char const* argv[]){
	
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);	
		arr.assign(1000005, 0);
		int cont=0;
		int maior=0;
		for(int i=0; i < n; i++){
		
			scanf("%d", &k);
			ft_adjust(k, 1);
			maior = max(maior,k);
			
			if(i>=1){
				if(maior!=k){
				 	cont+=  ft_rsq(k+1, maior); 	
				 }
			
			}
		}
		printf("%d\n", cont);
	}
	
	return 0;
}


