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

#define LSOne(S) (S & (-S))
vector<ll> t;
void ft_create(int n) {  t.assign(n+1, 0); }
ll ft_rsq(ll b){
	ll sum = 0; for(; b; b-= LSOne(b)) sum+=t[b];
	return sum;
}
void ft_adjust(int k, int v){
	int s = t.size();
	for(;k<= s; k+= LSOne(k) ) { t[k]+=v;}
}


int n;
int arr[100005];
int main (int argc, char const* argv[]) {
	while(1){
		sc1(n); iz(n);
		fr(i,0,n) {
			sc1(arr[i]);
		}
		t.clear();
		ft_create(n);
		ll cnt =0, k, w;
		for(int i=n-1; i>=0; i--){
			k = arr[i];
			//pv(t, x);
			w = ft_rsq(k-1);
			//printf("k: %d | w: %d\n", k, w);
			cnt += w;
			ft_adjust(k, 1);

		}
		//printf("cnt: %d\n", cnt);
		if(cnt%2==1 )printf("Marcelo\n");
		else printf("Carlos\n");
	}
	return 0;
}

