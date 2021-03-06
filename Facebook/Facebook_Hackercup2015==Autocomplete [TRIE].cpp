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

struct Node {
	int adj[29]; ll prefix;
	Node(){ mst(adj, -1); prefix = 0; }	
	Node(ll _prefix){ mst(adj, -1); prefix = _prefix; }	
	int& operator [](const int i){
		return adj[i]; }
};
Node tree[1000015];
int next;
void init(){ tree[0] = Node(); next = 1; }
int initNode(){
	tree[next] = Node();
	return next++;
}
int cnt, h, len;
string str;
int insert(int no, int p){
	if(no==-1){
		no = initNode();
	}
	if(no && !tree[no].prefix) {
		h = min(h, cnt);
	}
	cnt++;	
	tree[no].prefix++;
	if(p < len ) {
		char ch = str[p] - 'a';
		tree[no][ch] = insert(tree[no][ch], p+1);
	}
	return no;
}

int main(int argc, char const *argv[]) {
	int caso, n, k;
	sc1(caso);
	fe(t,1,caso){
		init();
		sc1(n); getline(cin, str);
		k = 0;
		while(n--){
			getline(cin, str);
			cnt = 0; h = 100; len = str.length();
			insert(0,0);
			h = min(h, len);
			k+=h;
		}
		printf("Case #%d: %d\n", t, k);
	}

	
	return 0;
}



