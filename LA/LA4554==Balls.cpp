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

int M , B; 
int pd[1005][55], pd_ok[1005][55], PASSO = 0;

int go(int m, int b ){
//	printf("Call m:%d b:%d\n", m, b );  
	if( m <= 0 ) return 0;
	if(m == 1) return 1; 
	if(pd_ok[m][b] == PASSO ) return pd[m][b];
	if(b == 1  ) {
		//printf("OI m: %d\n", m);
		return m; 
	}
	int res = inf, r1, r2;
	fe(i,1,m){
		
		if(i-1 > 0) r1 = 1 + go(i-1, b-1); 
		if(m-i > 0 ) r2 = 1 + go(m-i, b ); 
		//printf(
		res = min(res, max(r1, r2) );
	}
	//printf("Call m:%d b:%d | res: %d \n", m, b , res); 	
	pd_ok[m][b] = PASSO;
	pd[m][b] = res;
	return res;
	

}



int main (int argc, char const* argv[]){
	int caso, x;
	sc1(caso);
	PASSO = 1;
	fe(i,1,50){
		fe(j,1,1000){
			go(j, i);
		}
	}
	
	PASSO = 1;
	fe(t,1,caso){
		//PASSO++;
		sc1(x);
		sc2(B,M);
		int r = go(M, B ); 
		printf("%d %d\n",t,  r );
	
	
	} 	
	
	return 0;
}








