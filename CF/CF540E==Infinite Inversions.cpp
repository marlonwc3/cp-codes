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
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-12
#define oi(__) cout << "Oi ["<< __ << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S) )
vll t;
int N;
void ft_create (int n) {  
N = n;
t.assign(n+1, 0); }   
ll ft_rsq(int b) {
    ll sum = 0; for(; b; b -= LSOne(b) ){
    	//printf("BIT RSQ: b: %d\n", b);
     	sum += t[b];
     }
return sum; }
int ft_rsq(int a, int b) { return ft_rsq(b) - (a==1 ? 0 : ft_rsq(a-1)); }
void ft_adjust(int k, ll v) {
	
 for(; k<=N; k+= LSOne(k)  ) {
	// printf("adjust BIT k: %d\n ", k);
 	t[k]+=v; 
 }
 }


vii swaps;
vi todos;
vi boys;
map<int, int> agora;
map<int, int> devia;

ll get(int lo, int hi ){
	if( lo > hi ) return 0;
	ll p1 = lower_bound(boys.begin(), boys.end(), lo) - boys.begin();
	ll p2 = upper_bound(boys.begin(), boys.end(), hi) - boys.begin();
	return p2 - p1;
}


int main (int argc, char const* argv[]){
	int n , k, a, b;
	vi::iterator it; 
	sc1(n);
	fr(i,0,n){
		sc2(a,b);
		swaps.pb(mp(a,b));
		todos.pb(a); todos.pb(b);
	}
	//pv(todos,x);
	sort(todos.begin(), todos.end());
	it = unique(todos.begin(), todos.end());

	todos.resize(distance(todos.begin(), it) );
	n = todos.size();
//	pv(todos,x);
	boys = todos;
	fr(i,0,n){	
		agora[todos[i]] = i;
		devia[todos[i]] = i;
	}
	//pv(todos,x);
	//printf("n: %d\n", n);
	int p1, p2;
	fr(i,0,swaps.size()){
		a = swaps[i].st, b = swaps[i].nd;
		p1 = agora[a], p2 = agora[b];
		//printf("p1: %d | p2: %d | a: %d | b: %d \n", p1, p2, a, b);
		//if(p1 != p2){
		 swap(todos[p1], todos[p2]);
		agora[a] = p2, agora[b] = p1;
		//}
	

	}
	//pv(todos,x);
	fr(i,0,n){
		//printf("%d | agora: %d | devia: %d\n", todos[i], agora[todos[i]], devia[todos[i]]);
		
	}
//	oi(1);
	ll ans = 0;
	ft_create(n);
	ll x;
	//printf("tsize: %d\n", int(t.size()) ) ;
	for(int i = n-1; i>= 0; i--) {
		a = todos[i];
		p1 = devia[a];
		k =  ft_rsq(p1+1);
	//	printf("p1+1: %d\n", p1+1);
		
		ans += k;
		//if(p1 == i ) continue;
		
		ll d = (p1 != i ) ?  (abs(ll(a) - boys[i]) - 1) : 0 ;		
		//printf("a: %d | i: %d | p1: %d | k: %d | d: %d \n", a, i , p1, k, d);		
		ans += d;
		if( i > p1 ) {
			x = get(a+1, boys[i]-1);

			ans -= x;
		}
		else {
			x = get(boys[i]+1, a-1);
			ans -= x;
		}
		//	printf("x: %d\n", x);
		ft_adjust(p1+1, 1);
	}
	printf("%I64d\n", ans);
		
	
	return 0;
}
