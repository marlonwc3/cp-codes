#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <string>
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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second   
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
#define clr(a, b) memset(a, b, sizeof(a)) // tati 

using namespace std;
typedef vector<int> vi;
typedef   long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);

ll fexp(ll a, ll b){
	if(!b) return 1;
	if(b==1 ) return a;
	ll r = fexp(a, b/2); r*=r; 
	if(b%2 == 1 ) r *= a;
	return r;
}



string line;
int main (int argc, char const* argv[]){
	int caso; 
	sc1(caso); getline(cin, line);
	int op, r, len;
	fe(T,1,caso){
		getline(cin, line);
		r = 0;
		op = 0;
		len = line.length();
		fr(i,0,len){
			if(line[i] == '[' ) { op++; }
			else op--;
			r = max(r, op);
		}
		
		ll x = fexp(2 , r);
		printf("%d %lld\n", T, x);
		
		
		
	
	
	}
	
	
	
	return 0;
}

