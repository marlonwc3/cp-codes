#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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


map<string, int> mymap;
map<int, string> mybackmap;
vi e[105];
int g[105], next;
vector<string> res;
struct node {
	int v;
	node(){}
	node(int _v){ v= _v;}
	bool operator < (const node &no) const{ return v >	 no.v; }
};

void go(){
	priority_queue<node> q;
	fr(i,0,next){ if(!g[i]) q.push(node(i) );  }
	int a, b, s;
	node no;
	while(!q.empty()){
		no = q.top(); q.pop();
		a = no.v; 
		s = e[a].size();
		res.pb( mybackmap[a] );
		fr(i,0,s){
			b = e[a][i];
			if(g[b]<=0) continue;
			g[b]--;
			if(!g[b]) q.push(b);
		}
	}
}


char str[105], str2[105];
int main(int argc, char const *argv[]) {
	int n, q, a, b, t = 0;
	while(sc1(n)==1){
		t++;
		mymap.clear();
		mybackmap.clear(); 
		next = 0;
		res.clear();
		fr(i,0,n){ 
			e[i].clear(); g[i] = 0; 
			scanf("%s", str);
			mymap[str] = next;
			mybackmap[next] = str; 
			next++;
		}
		sc1(q);
		while(q--){
			scanf("%s %s", str, str2);
			a = mymap[str], b = mymap[str2];
			e[a].pb(b);
			g[b]++;
		}
		go();
		printf("Case #%d: Dilbert should drink beverages in this order: ", t);
		fr(i,0,res.size() ){
			printf("%s", res[i].c_str() );
			if(i!=res.size()-1) printf(" ");
		}
		printf(".");
		_
		_
	}


	return 0;
}