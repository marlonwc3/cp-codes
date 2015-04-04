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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
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

vi e[120];
int dist[120], n;

int SUM;
int go(int no){
	int r = 0;
	queue<int> q;
	fe(i,0,105) dist[i]=0;
	dist[no] = 1;
	q.push(no);
	int adj, s;
	while(!q.empty()){
		no = q.front(); q.pop();
		s = e[no].size();
		r += (dist[no] - 1);
		fr(i,0,s){
			adj = e[no][i];
			if(dist[adj])continue;
			dist[adj] = 1 + dist[no];
			q.push(adj);
		
		}
	
	}
	return r;
}





bool mark[120];
	vi v;
int bota(int a){
	if(!mark[a]){
		mark[a] = 1;
		v.pb(a);
	}
}

int main (int argc, char const* argv[]) {
	int a,b;
	int caso = 0;
	while(1){
		mst(mark, 0);
		v.clear();
		fe(i,0,105) e[i].clear();
		sc2(a,b); if(!a && !b) break;
		e[a].pb(b);
		bota(a); bota(b);
		caso++;
		while(1){
			sc2(a,b);
			if(!a && !b) break;
			e[a].pb(b);
			bota(a); bota(b);
		}
		SUM = 0;
		fr(i,0,v.size()){
			int w = go(v[i]);
			SUM += w;
		}
		b = v.size();
		double r =  (SUM+0.0)/(b*(b-1));
		printf("Case %d: average length between pages = %.3lf clicks\n",caso,r );
		
		
		
	
	
	}
	
	
	
	
	return 0;
}























