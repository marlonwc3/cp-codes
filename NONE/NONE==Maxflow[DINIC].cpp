#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


vi e[110];
int cap[110][110], flow[110][110], level[110], path[110];

bool blgraph(int src, int sink){
	queue<int> q;
	mst(level, 0);
	q.push(src);
	level[src] =  1;
	int no, s, adj;
	while( !q.empty() ){
		no = q.front(); q.pop();
		s = e[no].size();
		fr(i,0,s){
			adj = e[no][i];
			if( level[adj] == 0  && (cap[no][adj] - flow[no][adj] > 0 || flow[adj][no] > 0 )  ) {
				q.push(adj);
				level[adj] = level[no] + 1;
			}
		}
	}
	return level[sink]!=0;
}
int visit[110], PASSO;
int blockingFlow(int src, int sink	){
	mst(path, 0);
	PASSO++;
	stack<int> mystack;
	int ret = 0, adj, no, s;
	mystack.push(src);
	while(!mystack.empty()){
		no = mystack.top(); s = e[no].size();
		if(no != sink) {
			for(int i = 0; i < s; i++){
				adj = e[no][i];
				if(visit[adj] == PASSO || level[adj] != level[no]+1) continue;
				if(cap[no][adj] - flow[no][adj] > 0 ) {
					mystack.push(adj); path[adj] = no;
				}	
				else if (flow[adj][no] >  0){
					mystack.push(adj); path[adj] = -no;				
				}
			}
			if(mystack.top() == no ) {
				mystack.pop(); visit[no] = PASSO;
			}
		}
		else{
			int F = inf, bottleneck, menor = inf;
			for(int cur = sink; cur != src; cur = abs(path[cur]) ){
				F = min(F, 
					path[cur] >  0 ?  cap[path[cur]][cur] - flow[path[cur]][cur] : flow[cur][abs(path[cur])] );
			}
			for(int cur = sink; cur != src; cur = abs(path[cur]) ){
				if(path[cur] > 0 ) {
					flow[path[cur]][cur] += F;
					if(cap[path[cur]][cur] - flow[path[cur]][cur] == 0 ){
						bottleneck = path[cur];			
					}
				}
				else{
					flow[cur][abs(path[cur])] -= F;					
					if( flow[cur][abs(path[cur])] == 0  ){
						bottleneck = abs(path[cur]);
					}
				}
			}
			while( !mystack.empty() && mystack.top() != bottleneck ){
				mystack.pop();
			}
			ret += F;	
		}
	}
	return ret;	
}
int dinic(int src, int sink){
	int ret = 0;
	while(1) {
		int lv = blgraph(src, sink) ;
		if(lv<=0) break;
		ret += blockingFlow(src, sink);
	}
	return ret;
}

int main (int argc, char const* argv[]) {
	int n, s, t, c, a,b, w, caso = 0;
	while( 1 ) {
		sc1(n); iz(n);
		caso++;
		fe(i,0,n+2) e[i].clear();
		sc3(s, t, c);
		mst(flow,0);
		mst(cap, 0);
		fr(i,0,c){
			sc3(a,b,w);
			e[a].pb(b); e[b].pb(a);
			cap[a][b] +=w; cap[b][a] +=w;
		}
		int res = dinic(s,t);
		printf("Network %d\n", caso);
		printf("The bandwidth is %d.\n", res);
		_
	}
	
	
	
	return 0;
}








