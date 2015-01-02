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
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii; 
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;

vi res;
vi v;
int n;
void p(){
	fr(i,0,6) {
		printf("%d", res[i]);
		if( i!=5 ) printf(" ");
	}
	_
}

bool foo(int cont, int i){
	if ( cont>= 6 ) {
		p();
		return 0;
	}
	if( i >= n ) return 0;
	int num = v[i];
	res.pb(num);
	foo(cont+1, i+1);
	res.pop_back();
	foo(cont, i+1);	
}


int main (int argc, char const* argv[]){
	int k;
	bool f = 1;
	while(1){
	
		sc1(n);
		iz(n);
		if(!f) _
		
		
		v.clear();
		res.clear();
		fr(i,0,n){
			sc1(k);
			v.pb(k);
		}

		foo(0,0);
		f = 0;
	}
	
	
	return 0;
}



