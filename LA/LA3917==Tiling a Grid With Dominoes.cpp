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

ll f[40]; 
int main (int argc, char const* argv[])
{
	f[1] = 1;
	f[2] = 5;
	f[3] = 11;
	f[4] = 36;
	f[5] = 95;
	f[6] = 281;
	f[7] = 781;
	f[8] = 2245;
	f[9] = 6336;
	f[10] = 18061;
	f[11] = 51205;
	f[12] = 145601;
	f[13] = 413351;
	f[14] = 1174500;
	f[15] = 3335651;
	f[16] = 9475901;
	f[17] = 26915305;
	f[18] = 76455961;
	f[19] = 217172736;
	f[20] = 616891945;
	f[21] = 1752296281;

	int caso, N;
	sc1(caso);
	fe(T,1,caso){
		sc1(N);
		printf("%d %lld\n", T, f[N] ); 
	
	}


	
	
	
	
	return 0;
}
