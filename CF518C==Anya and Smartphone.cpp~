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

deque<int> frame[100005];
int f[100005];
int pos[100005];

int n,m,k;


int main (int argc, char const* argv[]) {
	sc3(n,m,k);
	
	int kcnt = 0, next = 1;
	int w;
	fr(i,0,n){
		sc1(w);
		frame[next].pb(w);
		f[w] = next;
		pos[w] = frame[next].size() -1;
		kcnt++;
		if(kcnt >= k) {
			next++; kcnt = 0;
		}
	}
	ll r = 0;
	int fboy, posboy, ant;
	fr(i,0,m){
		sc1(w);
		fboy = f[w];
		posboy = pos[w];
		r += fboy;
		
		if( posboy -1 < 0 ) {
			if( fboy == 1 ) continue;	
			ant = frame[fboy-1].back();
			frame[fboy-1].pop_back();
			frame[fboy-1].pb(w);
			
			frame[fboy].pop_front();
			frame[fboy].push_front(ant);
			swap(f[w], f[ant]);
			swap(pos[w], pos[ant]);			
			
		}
		else {
			ant = frame[fboy][posboy-1];
			swap( frame[fboy][posboy], frame[fboy][posboy-1] );
			swap(f[w], f[ant]);
			swap(pos[w], pos[ant]);
		}
	
	}
	printf("%I64d\n", r);
	return 0;
}



