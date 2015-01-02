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
 
 
int nums[10005];
int main (int argc, char const* argv[]) {
	
	int z, i, m, l;
	int t =0;
	while(1){
		sc4(z,i,m,l);
		if(!z && !i && !m && !l) break;
		t++;
		mst(nums,0);
		int seed = l;
		int cnt = 1; 
		int cycle;
		while(1){
			
			seed =  (z*seed + i )%m;
		//	printf("seed: %d | cnt: %d | nums: %d\n", seed, cnt, nums[seed] );
			if(nums[seed]) {
				
				cycle = cnt - nums[seed];
				break;
			}
			else nums[seed] = cnt++;
			
		}  
	
		printf("Case %d: %d\n", t, cycle);
	}
	
	
	return 0;
}





