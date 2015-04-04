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

ll cntH = 0;
ll sum = 0 ;
ll val, h;

ll fexp(ll a, ll b){
	if(!b) return 1;
	if(b==1) return a;
	ll r =fexp(a, b/2);
	r*=r;
	if(b%2 ==1 ) r*=a;
	return r;
}

void bs(ll hi, ll lo, bool left){
	if( lo >= hi ) return;
	cntH++;
	ll mid = (hi+lo)/2;
	ll hl = h - cntH;
	if( val <= mid ){
		if(left){
			sum += 1 + fexp(2, hl+1) -1;
		}
		else{
			sum++;
		}
		left = 1;
		hi = mid;
	}
	else{
		if( left) {
			sum++;
		}
		else {
			sum += 1 + fexp(2, hl+1) -1;
		}
		left = 0;
		lo = mid+1;
	}
	bs(hi, lo, left);
}

int main(int argc, char const *argv[]) {
	cntH =0 ;
	scanf("%I64d %I64d", &h, &val);
	ll hi = fexp( 2, h );
	bs(hi, 1 , 0);
	printf("%I64d\n", sum);
	return 0;
}
