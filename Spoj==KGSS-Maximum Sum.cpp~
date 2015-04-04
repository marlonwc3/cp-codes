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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
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


ll arr[100030];
struct Node {
	//ll val; 
	int L, R;
	ll v1, v2;
	Node(){}
	Node(ll _v1, ll _v2, int _L, int _R){ v1 = _v2, L = _L, R = _R;}
	void atualize(const Node &a, const Node &b){
		ll todos[4] = {a.v1, a.v2, b.v1, b.v2}; sort(todos, todos+4);
		v1 = todos[3]; v2 = todos[2];
//		val = max(a.val, b.val);
	}
};
Node tree[4*100005];
const Node NEUTRO = Node(-linf, -linf, 0, inf);

void pre(int no, int L, int R){
	tree[no] = Node(-linf, -linf, L, R);
	if(L == R ) {
		//tree[no].val = arr[L];
		tree[no].v1 = arr[L]; tree[no].v2 = -linf;
		return;
	}
	pre(2*no, L, (L+R)/2);
	pre(2*no +1, ((L+R)/2) + 1, R);
	tree[no].atualize(tree[2*no], tree[2*no + 1]);	
}

void update(int no, int k, ll val){
	if(tree[no].L == k && tree[no].R == k){
//		tree[no].val = val;
		tree[no].v1 = val;
		return;
	}
	if(k <= (tree[no].L + tree[no].R)/2 ){
		update(2*no, k, val);
	}
	else update(2*no + 1, k, val);
	tree[no].atualize(tree[2*no], tree[2*no +1]);
}

pair<ll,ll> query(int no, int L, int R, int iq, int jq){
	if(R < iq || L > jq) return mp(NEUTRO.v1, NEUTRO.v2);
	if(L >= iq && R <= jq ) {
		return mp(tree[no].v1, tree[no].v2);
	}
//	ll todos[4];
	pair<ll,ll> r1, r2;
	r1 = query(2*no, L, ((L+R)/2), iq, jq );	
	r2 = query(2*no + 1, ((L+R)/2) +1,R,  iq, jq );
	ll todos[4] = {r1.st, r1.nd, r2.st, r2.nd}; sort(todos, todos+4);
	return mp(todos[3], todos[2]);
}


char str[5];
int main (int argc, char *argv[]) {
	int n; ll a, b;
	sc1(n);
	fr(i,0,n){
		scanf("%lld", &arr[i] );
	}
	pre(1, 0, n-1);
	int q; sc1(q);
	pair<ll,ll> r;
	while(q--){
		scanf("%s %lld %lld", str, &a, &b	);
		a--;
		if(str[0]=='Q' ){
			b--;
		//	printf("query %lld %lld\n", a, b);
			r = query(1, 0, n-1, a, b);
			printf("%lld\n", r.st+r.nd);
		}
		else if(str[0] =='U'){
			update(1, a, b);
		}
	}
	
	
	return 0;
}













