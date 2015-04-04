#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;


typedef stack<char> sc;	
typedef vector<sc> vsc;

vsc stacks;
char str[1005];


void insert(char c){
	int s = stacks.size();
	bool botou = false;
	for(int i=0; i < s; i++ ){
		if(stacks[i].top() >= c) {
			botou=1;
			stacks[i].push(c);
			break;
		}
	}
	if(!botou){
		sc nova = sc();
		nova.push(c);
		stacks.push_back(nova);
	}
}



int main (int argc, char const* argv[]) {
	
	char c; int res, len, t=0;
	while(1){
		scanf("%s", str);
		if(str[0]=='e') break;
		t++;
		stacks.clear();
		len = strlen(str);
		for(int i=0; i < len; i++){
			insert(str[i]);
		}
		res = stacks.size();
		printf("Case %d: %d\n", t, res);
	}
		
	
	return 0;
}
