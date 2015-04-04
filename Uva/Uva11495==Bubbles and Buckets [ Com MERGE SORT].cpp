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

ll cnt = 0;

vi merge(vi a, vi b){
	int i = 0, j = 0 , s1 = a.size(), s2 = b.size();
	vi r;
	while( i  < s1 && j < s2){
		if(a[i] < b[j]){
			r.pb(a[i]);
			i++;
		}
		else {
			r.pb(b[j]);
			cnt += ll(a.size()) - i;
			j++;
		}
	}
	while( i < s1){
		r.pb(a[i]); i++;
	}
	while(j < s2){
		r.pb(b[j]); j++;

	}
	return r;

}
vi v;
vi msort(int lo, int hi){
	vi r;
	if(lo+1 >= hi ) {
		r.pb(v[lo]);
		return r;
	}
	int mid = (lo+hi)/2;
	vi a = msort(lo, mid);
	vi b = msort(mid, hi);
	r = merge(a,b);
	return r;
}
int main (int argc, char *argv[]) {
	int n, k, s;
	while( 1 ){
		sc1(n); iz(n);
		cnt=0; v.clear();
		fr(i,0,n){
			sc1(k); v.pb(k);
		}
		msort(0,n);
		//printf("%d\n", cnt);
		
		if(cnt%2) printf("Marcelo\n");
		else printf("Carlos\n");
		
	}
	
	
	
	return 0;
}
