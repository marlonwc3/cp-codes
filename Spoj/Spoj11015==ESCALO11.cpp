#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
struct Node
{
	vi edges;
	int p; // prioridade é o indice
	
	Node(){}
	Node(int _p){
		p=_p;
	}
	
	bool operator < (const Node &a) const{
		return p > a.p;
	}
	
};

priority_queue<Node> pq;
Node nodes[50005];
vi topo;
int dep[50005];

int n,m;


void tsort(){
	for(int i=0 ; i < n; i++){
		if(!dep[i]){
			pq.push(nodes[i]);
		}
	}	//adiciona tds de dependencia 0
	Node no;
	int s, adj; vi e;
	while(!pq.empty()){
		no = pq.top(); pq.pop();		
		e = no.edges;

		topo.push_back(no.p);
		s = e.size();
		for(int i=0; i < s; i++){
			adj = e[i];
			if(dep[adj]>0) {
				dep[adj]-=1;
				if(!dep[adj] ) pq.push(nodes[adj]);
			}
		}
	}
}


int main (int argc, char const* argv[]) {
	int a, b, s;
	while(scanf("%d %d", &n, &m) > 0){

		pq = priority_queue<Node>();
		memset(nodes, 0, sizeof nodes);
		memset(dep, 0, sizeof dep);
		topo = vi();	
		for(int i=0; i < n;i++) {
			nodes[i] = Node(i);
	
		}
		while(m--) {
			scanf("%d %d", &a, &b);
			
			dep[b]++;
	
			nodes[a].edges.push_back(b);
		}
		
		
		
		tsort();
		s = topo.size();
		if(s != n){
			printf("*\n");
		}
		else {
			for(int i=0; i<s; i++){
				printf("%d\n", topo[i]);
			}
	
		}
		
	}

	return 0;
}


