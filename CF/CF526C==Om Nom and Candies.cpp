#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sc5(a,b,c,d,e) scanf("%d %d %d %d %d", &a, &b, &c, &d, &e)
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
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;




ll c, hr, hb, wr, wb;
int main (int argc, char const* argv[]){
	scanf("%I64d %I64d %I64d %I64d %I64d", &c, &hr, &hb, &wr, &wb);
	ll sq = sqrt(c);
	
	if( wr >= sq ) {
		swap(wr, wb);	
		swap(hr, hb);
	}
	else if( wb < sq ) {
		if (wr*hb >= hr*wb ) {
			swap(wr, wb);	
			swap(hr, hb);
		}
	}
	
	ll sobra, j, r = 0;
	fe(i,0,sq+2){
		sobra = c - i*wb;
		if( sobra < 0 ) break;	
		j  = sobra/wr;
		r = max(r, i*hb + j*hr);
	}
	printf("%I64d\n", r);
	
	
	
	
	
	return 0;
}
