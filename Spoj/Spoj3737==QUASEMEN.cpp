#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define inf 0x3f3f3f
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, bool> iib;
typedef vector<iib> viib;
typedef vector<int> vi;
struct Node
{
	int id; int d;
	Node(){}
	Node(int _id, int _d){ id=_id; d=_d;}
	bool operator < (const Node &a) const{
		return d > a.d;
	}	
};

int dist[505];
vi pais[505];
priority_queue<Node> q;
viib edgeList[505];
int n;
void dijkstra(int ini, bool seg){
	for(int i=0; i < n; i++){dist[i]=inf;}

	dist[ini] = 0;
	q.push(Node(ini, 0));
	Node node;
	viib edges; int adj, w, no, d, s, sp;
	bool pode=false, mark;
	while(!q.empty()) {
		node = q.top(); q.pop();
		no = node.id; d= node.d;	
		if(dist[no] != d) continue;
		edges = edgeList[no]; s = edges.size();
		for(int i=0; i <s;i++){
			mark = edges[i].second;
			if(seg && mark) continue;
			adj = edges[i].first.first;
			w = edges[i].first.second;

			if(!seg && dist[adj] == dist[no]+w ){
				pais[adj].push_back(no);
				
			}
			else if(dist[adj] > dist[no] + w){

					
					pais[adj].clear();

					pais[adj].push_back(no);
					dist[adj] = dist[no]+w;
					q.push(Node( adj, dist[adj]) );				
				
			}			
			

		}
	}
}


int marking(int no, int ini){
	if(no==ini) return 0;
	int s, pai, se;
	s = pais[no].size(); viib edges;
	for(int i=0; i<s; i++){
		pai = pais[no][i];
		edges = edgeList[  pai ]; se =edges.size();
		for(int j=0; j< se; j++){
			if( edges[j].first.first == no) {
				edgeList[  pai ][j].second=true;
				marking(pai, ini);
				break;
			}
		}
		
	}
	
}

int foo(int ini, int fim){
	memset(pais, 0, sizeof pais);
	dijkstra(ini, 0);
	if(dist[fim] >= inf) return inf;
	marking(fim,ini);
	dijkstra(ini, 1);
	return dist[fim];
}


int main (int argc, char const* argv[]) {
	int m, ini, fim, a, b, c; 
	while(1){
		scanf("%d %d", &n, &m);
		if(!n && !m) break;
		memset(edgeList, 0, sizeof edgeList);
		q = priority_queue<Node>();
		scanf("%d %d", &ini, &fim);
		while(m--){
			scanf("%d %d %d", &a, &b, &c);
			edgeList[a].push_back(make_pair( make_pair(b,c),0 ));
		}

		a = foo(ini, fim);
		a = (a>=inf) ? -1 : a;
		printf("%d\n", a);
	}
	
	return 0;
}

















