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
#define EPS 1e-6
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


vi e[105];
int g[105];
vi v;
int n, m;

bool mark[105];
vector<string> vs;
vector<char> vc;
void bt(int no){
	vi lol;
	int s = e[no].size(), adj;
	mark[no]=1;
	vc.pb((no+'a'));
	fr(i,0,s){
		adj = e[no][i];
		if(g[adj]<=0) continue;
		g[adj]--;
		lol.pb(adj);
	}
	bool ok = 1;
	fr(i,0,n){
		ok = ok && mark[v[i]] && !g[v[i]];
		if(mark[v[i]] ) continue;
		if(!g[v[i]]) bt(v[i] );
	}
	if(ok){
		string str = "";
		fr(i,0,vc.size()) str += vc[i];
		vs.pb(str);
	}
	mark[no]=0;
	vc.pop_back();
	fr(i,0,lol.size()) g[lol[i]]++;
}


int main (int argc, char const* argv[]) {
	string line;
	int len, a,b;
	bool first = 1;
	while(getline(cin,line)){
		if(!first) _ 
		fr(i,0,105) {
			e[i].clear();
			g[i]=0;
		}
		v.clear();
		vs.clear();
		vc.clear();
		len = line.length();
		for(int i =0 ; i < len; i+=2){
			v.pb( line[i]-'a' );
		}
		n = v.size();
		getline(cin,line);
		len = line.length();
		for(int i =0 ; i < len; i+=4){
			a = line[i] -'a', b = line[i+2]-'a';
			e[a].pb(b);
			g[b]++;
		}	
		fr(i,0,n){
			a = v[i];
			if(!g[a]) bt(a);
		}
		b = vs.size();
		sort(vs.begin(), vs.end());
		fr(i,0,b){
			printf("%s\n", vs[i].c_str() );
		}
		first =0 ;
	}
	return 0;
}





