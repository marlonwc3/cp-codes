#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

vlld v;
int siz;
void f(){
	lld k;
	v.pb(1);
	v.pb(1);
	for(int i=2; i < 10000; i++){
		k = v[i-1] + v[i-2];
		if(k < 0 || k >= 2000000000) break;
		v.pb(k); 
	}	
	siz = v.size();
}
lld find(lld k){
	for(int i = siz-1; i >= 0; i--) if(v[i] <= k) return v[i]; 
	return 0;
}
int main (int argc, char const* argv[]) {
	f();
	int t, n;
	lld k, res, r, cnt;
	sc1(t);
	for(int j = 1; j <= t; j++){
		res = 1;
		sc1(n);
		while(n--){
			scanf("%lld", &k);
			cnt = 0;
			while(1){
				r = find(k);
				if(!r) break;
				k-=r; cnt++;
			}
			res*=cnt;
		}
		printf("Case %d: %lld\n", j, res);
	}	
	return 0;
}










