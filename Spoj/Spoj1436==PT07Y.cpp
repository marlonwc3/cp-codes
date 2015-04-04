#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=a; i < b; i++)
#define pf(a) printf("%d ", a);
#define mp(a,b) make_pair(a,b)
#define pv(v) for(int i=0; i < v.size(); i++) { pf(v[i]); if(i==v.size() -1 ){ _; } }
#define pb(a) push_back(a)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int lld;


vi nos[10005];
bool mark[10005];
int n, m;
	
bool bfs(int ini){
	memset(mark, 0, sizeof mark);
	mark[ini]=1;
	queue<int> q;
	q.push(ini);
	int no, adj, s;
	while(!q.empty()){
		no = q.front(); q.pop();
	//	pf(no) _;
		s = nos[no].size();
		fr(i,0,s){
			adj = nos[no][i];
//			printf("adj: "); pf(adj) printf(" mark:%d ", mark[adj]); _; 
			if(mark[adj]) return 0;
			mark[adj]=1;
			q.push(adj);
		}
	}
	return 1;
}


int main (int argc, char const* argv[]) {
	sc2(n, m);
	int a, b;
	fr(i,0,m) {
		sc2(a,b);
		nos[a].push_back(b);
	}
	bool res;
	res = bfs(1);
	n++;
	fr(i, 1, n){
		if(!res) break;
		res = res && mark[i];
	}
	if(res) printf("YES\n");	
	else printf("NO\n");
		
	return 0;
}

		

