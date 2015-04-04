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
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

#define MAX_N 100005
ii todos[MAX_N+5];
int uso[MAX_N+5];
struct triple{
	int a,b,c;
	triple(int _a,int _b,int _c){a=_a, b=_b,c=_c;}
	bool operator < (const triple &t) const {
		if(a==t.a) {
			if(b == t.b) return c < t.c;
			return b < t.b;
		}
		return a < t.a;
	}
	void pf(){printf("(a: %d, b: %d, c: %d)\n", a, b, c);}
};

bool inter(int i, int j){
	if(todos[i].nd == todos[j].st || todos[j].nd == todos[i].st) return 0;
	return (todos[j].st >= todos[i].st && todos[j].st <= todos[i].nd ) || (todos[j].nd >= todos[i].st && todos[j].nd <= todos[i].nd ) || (todos[j].st <= todos[i].st && todos[j].nd >= todos[i].nd);
}

vector<triple> v;	
int go(int ini){
		set<int> livres;
		livres.clear();
		mst(uso, -1);
		int ans = 1;
		uso[ini]=1;
		livres.insert(1);
		fr(i,0,v.size()){
			if(v[i].c==ini) continue;
			if(v[i].b < 0 ) livres.insert(uso[v[i].c]);
			else{
				bool achou=0;
				int next;
				for(set<int>::iterator it = livres.begin(); it != livres.end(); it++){
					next = *it;
					if(v[i].c == !ini && next==1) continue;			
					if(next ==1 && inter(ini, v[i].c))continue;
					achou=1;
					break;
				}
				if(!achou){
					ans++; next=ans;
				}
				livres.erase(next);
				uso[v[i].c] = next;
			}
		}
	return ans;
}

int main (int argc, char const* argv[]){

	int caso,a,b,c,n;
	sc1(caso);
	fe(t,1,caso){
		sc1(n);
 v.clear();			
		fr(i,0,n){
			sc2(a,b);
			todos[i] = mp(a,b);
			v.pb(triple(a, +1, i));
			v.pb(triple(b, -1, i));
		}
		sort(v.begin(), v.end());	
		int ans= min( go(1), go(0) );
		printf("%d\n", ans);
		
	}
	
	return 0;
}
























