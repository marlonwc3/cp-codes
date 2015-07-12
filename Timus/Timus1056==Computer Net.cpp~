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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
#define clr(a, b) memset(a, b, sizeof(a)) // tati 

using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);

vi e[10010];

int dist[10010];

int bfs(int no){
	mst(dist,0);
	queue<int> q;
	q.push(no);
	int adj;
	dist[no] = 1;
	int res = 0;
	while(!q.empty()){
		no = q.front(); q.pop();
		res = max(res, dist[no]);
		fr(i,0,e[no].size()){
			adj = e[no][i];
			if(dist[adj]) continue;
			dist[adj] = 1 + dist[no];
			q.push(adj);
		}
		
	}
	return res-1;
}


int boys[10010];

int main (int argc, char const* argv[]){
	set<int> res;
	int N, k;
	sc1(N);
	int NEXT = 2;
	fr(i,0,N-1){
		sc1(k);
		e[k].pb(NEXT++);
		e[NEXT-1].pb(k);
	}
	if(0) fe(i,1,NEXT){
		pv(e[i],x);
	}
	
	int r = inf;
	fr(i,1,NEXT){
		boys[i] = bfs(i);		
		r = min(r, boys[i]);
		//printf("boy %d  -> %d\n", i, boys[i]);
	}
	vi v;
	fr(i,1,NEXT){
		if(boys[i] == r) v.pb(i);
	}
	printf("%d", v[0]);
	fr(i,1,v.size()){
		printf(" %d", v[i]);
	}
	_

	if(0){
	fe(i,1,NEXT){
		if(e[i].empty()) continue;
	//	printf("i: %d | size: %d\n", i, e[i].size());
		if(e[i].size() == 1 ) {
			fr(j,0,e[i].size()){
				res.insert(e[i][j]);
			}
		}
	}
	set<int>::iterator it = res.begin();
	if(it != res.end()){
		printf("%d", *it);
		it++;		
		for(; it!=res.end(); it++){
			printf(" %d", *it);
		}
	}
	_
	}
	


	
	return 0;
}
