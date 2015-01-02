#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
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
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;

vi e[350];
int dist[350];
int pai[350];
int n;
void go(int no){
	fr(i,0,n+2) dist[i]=inf;
	queue<int> q;
	dist[no]=0;
	mst(pai, -1);
	int adj, s, d;
	q.push(no);
	while(!q.empty()){
		no = q.front(); q.pop();
		d = dist[no];
		s = e[no].size();
		fr(i,0,s){
			adj = e[no][i];
			if(dist[adj] > d+ 1 ){
				dist[adj] = d+1;
				q.push(adj);
				pai[adj] = no;
			} 	
		}
	}
}

int main (int argc, char const* argv[]) {
	char str[5000];
	bool hif = 1;
	stack<int> res;
	while(sc1(n) == 1){
		int a, b, m;
		fr(i,0,n){
			scanf("%s", str);
			char *pch = strtok(str, ",-");
			bool first=  1;
			while(pch != NULL) {
				if(first){
					sscanf(pch, "%d", &a);
					e[a].clear();
					first = 0;
				}
				else {
					sscanf(pch, "%d", &b);
					e[a].pb(b);
				}
				pch = strtok(NULL, ",-");
			}
		}
		
		printf("-----\n");
		sc1(m);
		fr(i,0,m){
			sc2(a,b);
			go(a);
			if(dist[b] < 0 || dist[b] >= inf ) printf("connection impossible\n");
			else {
				res = stack<int>();			
				while(pai[b]!=-1){	
					res.push(b);
					b = pai[b];
				}
				if(res.top() != a ) res.push(a);
				
				printf("%d", res.top() ); res.pop();
				while(!res.empty()) {
					printf(" %d", res.top() ); res.pop();
				}
				_
				
			}
		}
		
		
		hif = 0;
		
	}
	

	
	return 0;
}












