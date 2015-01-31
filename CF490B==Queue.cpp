#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
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

int res[2*100005];
vii e[1000005];
si s1, s2;
vii pares;

int main (int argc, char const* argv[]) {
	int n, a, b, l1, l2;
	sc1(n);
	
	fr(i,0,n){
		sc2(a,b);
		pares.pb( mp(a,b) );
		if(!a) l1 = b;
		if(!b) l2 = a;
		if(a){ 
			if(b) e[a].pb(mp(b, +2));
			s1.insert(a); s2.insert(a); 
		}
		if(b){ 
			if(a) e[b].pb(mp(a, -2) );
			s1.insert(b); s2.insert(b); 
		}
	}
	int first=0, last=0;
	fr(i,0,n ){
		a = pares[i].st, b = pares[i].nd;
		s1.erase(b);
		s2.erase(a);
	} 
	
	first = *(s1.begin());
	last = *(s2.begin());
	queue<ii> q;
	q.push(mp(first, 0)); res[0] = first;
	q.push(mp(last, n-1)); res[n-1] = last;
	e[first].pb(mp(l1, +1));
	e[last].pb(mp(l2, -1));	
	int d, p;
	int cnt = 0;
	while(!q.empty()){
		a = q.front().st, p = q.front().nd; q.pop();
		//printf("a:  %d | p: %d\n", a, p);
	//	if(cnt > 10 )  break;
		cnt++;
		fr(i,0,e[a].size()){
			b = e[a][i].st, d = e[a][i].nd;
			//printf("b: %d | d: %d | p+d %d \n", b, d, p+d);
			if(res[p+d]) continue;
			res[p+d] = b;
			q.push(mp(b, p+d));	
		}
	}
	//printf("first: %d %d | l1: %d l2 %d\n", first, last, l1, l2);
	fr(i,0,n) {printf("%d", res[i]); if(i!=n-1) printf(" ");}
	_
	
	
	
	
	return 0;
}

