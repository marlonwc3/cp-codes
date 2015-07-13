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

int N, L, C;

int boys[1010];
char str[90];
int main (int argc, char const* argv[]){
	int nc, nl, np;

	int len;
	while( sc3(N,L,C) == 3 ){
		fr(i,0,N){
			len =0;
			scanf("%s", str);
			for(int j = 0; str[j]; j++, len++);
			boys[i] = len;
		}
		np = 1; nc = C; nl = 0;
		int w;
		bool first = 1;
		fr(i,0,N){
			w = boys[i];
		//	printf("w: %d\n", w);
			if(nc >= w+!first ) {
				nc -= w+!first;
				first = 0;
			}
			else{
				nl++;
				nc = C;
				if(nl >= L){
					nl = 0;
					np++;
				}
				nc -= w;
				first = 0;
			}
			
			
		}
		printf("%d\n", np);
		
		
	
	}
	
	
	
	
	return 0;
}
