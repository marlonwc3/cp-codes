#include <bits/stdc++.h>
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
typedef pair<char, int> ci;


int arr[1005];
int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	fe(t,1,caso){
		int N;
		int maior = 0;		
		sc1(N);
		fr(i,0,N){
			sc1(arr[i]);
			maior = max(maior, arr[i]);	
		}
		int res = inf;
		fe(i,1,maior){
			int acc = 0;
			fr(j,0,N){
				if(arr[j] <= i ) continue;
				acc += ((arr[j] + i-1)/i) - 1;
			}
			acc += i;
			res = min(res, acc);
		}
		printf("Case #%d: %d\n", t, res);
	}
	
	return 0;
}








