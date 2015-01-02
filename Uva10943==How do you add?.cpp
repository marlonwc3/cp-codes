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

#define MOD 1000000 

int pd[105][105];

int foo(int n, int k){
	if(n<0) return 0;
	if(k==0){
		return (n==0);	
	}
	if(pd[n][k]!=-1) return pd[n][k];
	int cnt = 0;
	fe(i,0,n){
		cnt = (cnt+foo(n-i, k-1) )%MOD;
	}
	return pd[n][k] = cnt;
}

int main (int argc, char const* argv[]){
	mst(pd, -1);
	
	int n,k;
	while(1){
		sc2(n,k); if(!n && !k ) break;
		k = foo(n,k);
		printf("%d\n",k);
		
	}
	
	
	return 0;
}






