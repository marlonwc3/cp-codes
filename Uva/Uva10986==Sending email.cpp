#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define mp(a,b) make_pair(a,b)
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

struct Node{
	int no, d;
	Node(){}
	Node(int _no, int _d){
		no = _no;
		d = _d;
	}
	bool operator < (const Node &a) const{
		return d > a.d;
	}	
};

priority_queue<Node> pq;
int dist[20005];
vii elist[20005];
int n, m;

int dijkstra(int ini, int fim){
	
	for(int i=0; i < n;i++) dist[i] = inf; // memset
	dist[ini] = 0; 
	pq = priority_queue<Node>(); // limpando
	pq.push(Node(ini, 0) );
	int adj, no, w, d, s;
	Node node;
	
	while(!pq.empty() ) {
		node = pq.top(); pq.pop();
		no = node.no;
		d = node.d;
		if(dist[no] != d) continue;
		s = elist[no].size();
		for(int i=0; i < s; i++){
			adj = elist[no][i].first;
			w = elist[no][i].second;	
			if( dist[adj] > dist[no] + w){
				dist[adj] = dist[no] + w;
				pq.push(Node(adj, dist[adj]) );	
			}
		}
	}
	return dist[fim];
}




int main (int argc, char const* argv[]) {
	int t, ini, fim, a, b, w;
	scanf("%d", &t);
	for(int i=1; i <= t; i++){
		scanf("%d %d %d %d", &n, &m, &ini, &fim);
		for(int j=0; j < n;j++ ) {
			elist[j].clear();
		}
		for(int j=0; j < m ; j++) {	
			scanf("%d %d %d", &a, &b, &w);
			elist[a].push_back(mp(b,w)); 
			elist[b].push_back(mp(a,w));
		}
		a = dijkstra(ini, fim);
		if(a>= inf || a<=-1) {
			printf("Case #%d: unreachable\n", i);
		}
		else {
			printf("Case #%d: %d\n", i, a);
		}
	}
	
	return 0;
}

