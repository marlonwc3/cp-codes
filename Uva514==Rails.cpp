#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

int nums[1005];


int n, next;
stack<int> st;
void find(int k){
	bool e = false;
	while(!e) {
		if(next == k ) {		
			e=1;
		}
		if(!e) {
			st.push(next);
		}
		next++;
	}
}


int main (int argc, char const* argv[]) {
	
	int k;
	bool ok, line = 0, pilha;
	while(1){
		scanf("%d", &n);
		if(!n) break;
		//if(line) printf("\n");
		
		while(1){
			
			scanf("%d", &k);
			if(!k) break;
			next=1; ok = 1;
			st = stack<int>();
			find(k);
			
			for(int i=0; i < n-1; i++){
				scanf("%d", &k);
				if(!ok) continue;
				pilha=0;
				if(! st.empty() ) {
					if(st.top() ==k ) {
						st.pop();
						pilha=1;
					}
				}
				
				if(!pilha){
					if(k < next) {
						ok = 0;
					}
					else {
						find(k);
					}
				}
			}
			
			if(ok) printf("Yes\n");
			else printf("No\n");

			
		}
		
		//line=1;		
		printf("\n");
	}
	

	/*
		a =  next number
		
	
	*/

	
	return 0;
}

