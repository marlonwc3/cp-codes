#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue> 
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int, int> ii;
struct Node {
	int a, d;
	Node(){}
	Node(int _a, int _d){ a = _a; d = _d;}
	bool operator < (const Node &a) const{
		return d > a.d;
	}
};

priority_queue<Node> pq;
vector<ii> edges[10005];
int dist[10005],  n;

int dijkstra(int ini, int fim){
	for(int i=0; i < n;i++ ) dist[i] = inf;
	pq.push(Node(ini, 0));
	dist[ini]=0; Node node;
	int no, d, s, adj, w;
	while(! pq.empty() ){
		node = pq.top(); pq.pop();
		no = node.a;
		d = node.d;
		if(dist[no] != d) continue;
		s = edges[no].size();
		for(int i=0; i < s; i++) {
			adj = edges[no][i].first;
			w = edges[no][i].second;
			if(dist[adj] > dist[no] + w) {
				dist[adj] = dist[no]+ w;
				pq.push(Node(adj, dist[adj]));
			}
		}
	}
	return dist[fim];
}



int main(int argc, char const *argv[]) {
	int k, m, a, b, c;
	
	scanf("%d", &k);
	while(k--){
		pq = priority_queue<Node>();
		memset(edges, 0, sizeof edges);
		scanf("%d %d", &n, &m);
		for(int i=0; i < m ; i++){
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			edges[a].push_back(make_pair(b,c));
		}
		scanf("%d %d", &a, &b);
		a--; b--;
		c = dijkstra(a, b);
		if( c >= inf ) printf("NO\n");
		else printf("%d\n", c);
		
	}
	return 0;
}


