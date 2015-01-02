#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#define mp(a,b) make_pair(a,b)
using namespace std;


typedef map<string, int> ms;
int next=0;
ms mymap;

int rep[100005];
int cont[100005];

int find(int a){
	if(rep[a]==a) return a;
	return rep[a] = find(rep[a]);
}

bool ist(int a, int b){
	return find(a)==find(b);
}

int uni(int a, int b){
	int repA = find(a);
	int repB = find(b);
	rep[repA] = repB;
	
	cont[repB] += cont[repA];
	cont[repA] = 0;
	
	return cont[repB];
	
}

int mapping(string a){
	if(	mymap.count(a) ==  0 ) {
		next++;
		mymap.insert(mp(a,next));
		rep[next]=next; cont[next]=1;
		return next;
	}
	return mymap[a];
}

int main (int argc, char const* argv[]) {
	string a, b;
	
	int t, ka, kb, res,f ;
	
	scanf("%d", &t);
	for(int i=1; i <= t; i++){
		scanf("%d", &f);
		mymap.clear();
		next=0;
		memset(cont, 0, sizeof cont);
		memset(rep, 0, sizeof rep);
		while(f--){
			cin >> a >> b ;
			ka = mapping(a);
			kb = mapping(b);
			if(ist(ka, kb) ){
				printf("%d\n", cont[rep[ka]]);
			}
			else {
				res = uni(ka, kb);
				printf("%d\n", res);
			}		
		
		}

	}
	
	return 0;
}
