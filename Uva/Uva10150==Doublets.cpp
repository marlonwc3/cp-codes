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

vector<string> vs;
vi e[25145];
int n;
void go(){
	string w;
	int len, p;
	fr(i,0,n){
		w = vs[i];
		len = w.length();
		fr(j,0,len){
			fr(k,0,25){
				w[j]++; if(w[j]>'z') w[j]='a';
				p = lower_bound(vs.begin(), vs.end(), w) - vs.begin();
				if(p < 0 || p >= n || vs[p] != w) continue;
				e[i].pb(p);
			}
			w[j]++; if(w[j]>'z') w[j]='a';
		}
	}
}

bool mark[25145];
int pai[25145];
void bfs(int ini, int fim){
	queue<int> q;
	int adj, s;
	fr(i,0,n){ mark[i]=0; pai[i]=-1; }
	q.push(ini);
	mark[ini]=1;
	while(!q.empty()){
		ini = q.front(); q.pop();
		if(ini == fim ) break;
		s = e[ini].size();
		fr(i,0,s){
			adj = e[ini][i];
			if(mark[adj]) continue;
			mark[adj]=1;
			pai[adj]=ini;
			q.push(adj);
		}
	}
}

void trace(int no){
	if(no==-1) return;
	trace(pai[no]);
	printf("%s\n", vs[no].c_str() );
}


int main (int argc, char const* argv[]) {
	string line;
	while(1){
		getline(cin,line);
		if(line.empty()) break;
		vs.pb(line);
	}
	n = vs.size();
	sort(vs.begin(), vs.end());
	go();
	
	char str1[30], str2[30];
	string a,b;
	int x, y;
	bool first =1;
	while(scanf("%s %s", str1, str2) ==2 ){
		a = str1; b = str2;
		x = lower_bound(vs.begin(), vs.end(), a )- vs.begin();
		y = lower_bound(vs.begin(), vs.end(), b) - vs.begin();
		bfs(x, y);
		if(!first) printf("\n");
		if(!mark[y]) printf("No solution.\n" );
		else trace(y);
		
		
		first = 0;
	} 
	


 	
	return 0;
}












