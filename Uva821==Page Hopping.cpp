#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef set<int> si;
int dist[205];
vi nodes[105];


int bfs(int ini){
	memset(dist, -1, sizeof dist);
	int cont=0;
	dist[ini]=0;
	queue<int> q;
	q.push(ini);
	int no, adj, s;
	while(!q.empty()) {
		no = q.front(); q.pop();
		s = nodes[no].size();
		for(int i=0; i < s; i++){
			adj = nodes[no][i];
			if(dist[adj] == -1 ) { // ainda n alcancei
				dist[adj] = 1 + dist[no];
				cont += dist[adj];
				q.push(adj);
			}
		}	
	}
	return cont;
}



int main (int argc, char const* argv[]) {
	si nums;
	int a, b, cont, no;
	float res;
	int t=0;
	while(1){
		scanf("%d %d", &a, &b);
		if(!a && !b) break;
		t++;
		nums.clear();
		for(int i=0; i <105; i++ ) nodes[i].clear();
		cont = 0;

		nums.insert(a);
		nums.insert(b);

		nodes[a].push_back(b);
		si::iterator it;
		while(1){
			scanf("%d %d", &a, &b);
			if(!a && !b) break;
			nums.insert(a); nums.insert(b);
			nodes[a].push_back(b);
	
		}


		for(it = nums.begin(); it!=nums.end(); it++){
			no = *it;
			
			cont += bfs(no);
		}

		a = nums.size();
		a*= (a-1);
		res = (cont+0.0)/a;		
		printf("Case %d: average length between pages = %.3f clicks\n", t,res);
		
		
	}
	
	
	return 0;
}


