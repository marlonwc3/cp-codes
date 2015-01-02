#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rep[505];

int find(int a){
	if(rep[a]==a) return a;
	return rep[a] = find(rep[a]);
}

int uni(int a, int b){
	int repA = find(a);
	int repB = find(b);
	rep[repA] = repB;
}


void init(int n){
	for (int i = 0; i < n; ++i) rep[i]=i;
}

bool sset(int a, int b){
	return find(a)==find(b);

}


struct Edge
{
	int a, b, w;
	Edge(){}
	Edge(int _a, int _b, int _w){
		a=_a; b=_b; w=_w;
	}

	bool operator < (const Edge &e) const {
		return w < e.w;
	}
};


vector<Edge> edges;

int kruskal(){
	sort(edges.begin(), edges.end());
	int s = edges.size();
	int a, b, cont=0;
	for (int i = 0; i < s; ++i)
	{
		a = edges[i].a;
		b = edges[i].b;
		if(!sset(a,b)) {
			cont+=edges[i].w;
			uni(a,b);
		}

	}
	return cont;
}


int main(int argc, char const *argv[]) {
	int n, m, u,v,c;
	while(scanf("%d %d", &n, &m) > 0){
		init(n);
		edges.clear();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			edges.push_back(Edge(u,v,c));
		}
		printf("%d\n", kruskal());
	}
	return 0;
}
