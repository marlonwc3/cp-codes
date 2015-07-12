#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define oo 0x3f3f3f3f
#define ooL 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define rp(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define re(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
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

#define se if
#define printa printf // broken key 'f' 

#define MAX_N 1000000
vi v;
int pd[MAX_N + 5];
int pai[MAX_N + 5];

int go(int n){
	se(n<0) return oo;
	se(n==0) return 0;
	se(pd[n] != -1) return pd[n];
	int r = oo,r2;
	rp(i,0,v.size()){
		r2 = 1+ go(n - v[i]);
		se(r2 < r ){
			r = r2;
			pai[n] = n - v[i];
		}
	}
	
	return pd[n] = r;
}
vi path;
void get(int n){
	se(n == 0) return;
	path.pb(n - pai[n]);
	get(pai[n]);
}


bool ok ( int n ){
	while(n){
		se(n%10 != 0 && n%10 != 1) return 0;
		n/=10;
	}
	return 1;
}


int main (int argc, char const* argv[]){
	re(i,1,MAX_N){
		se(ok(i)) v.pb(i);
	}
	//pv(v,x);

	mst(pd,-1);
	int n, s;
	sc1(n);
	s = go(n);
	get(n);
	printa("%d\n", s);
	printa("%d", path[0]);
	rp(i,1,s){
		printa(" %d", path[i]);
	}
	_
	

	return 0;
}
