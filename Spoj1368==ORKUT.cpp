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


map<string, int> mymap;
map<int, string> mybackmap;
vector<string> topo;
int n;
vi e[50];
int g[50];
bool go(){
	queue<int> q;
	fr(i,0,n) {if(!g[i])  q.push(i); }
	int s, no, adj;
	while(!q.empty()){
		no = q.front(); q.pop();
		topo.pb( mybackmap[no] );
		s = e[no].size();
		fr(i,0,s){
			adj = e[no][i];	
			if(!g[adj])continue;
			g[adj]--;
			if(!g[adj]) q.push(adj);
		}
	}
	
	fr(i,0,n) if(g[i]) return 0;
	return 1;
}

int main (int argc, char const* argv[]) {
	char str[150];
	int m, a, b;
	bool ok;
	int t = 0;
	while(1){
		sc1(n);iz(n); t++;
		mymap.clear();
		mybackmap.clear();
		topo.clear();
		
		fr(i,0,n){
			e[i].clear();
			g[i]= 0;
			scanf("%s", str);
			mymap[str] = i;
			mybackmap[i]=str;
		}
		fr(i,0,n){
			scanf("%s %d", str, &m);
			a = mymap[str];	
			g[a] = m;
			fr(j,0,m){
				scanf("%s", str);
				b = mymap[str];
				e[b].pb(a);
			}
		}
	
		ok = go();
		printf("Teste %d\n", t);
		if(ok){
			printf("%s", topo[0].c_str());
			fr(i,1,n) printf(" %s", topo[i].c_str() );
			_
		}
		else{
			printf("impossivel\n");
		}
		_
		
	}
	return 0;
}



