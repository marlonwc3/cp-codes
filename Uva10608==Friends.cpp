#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
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


int rep[30005];

int ini(int n){ fr(i,0,n+1) rep[i]=i; }
int find(int a) { return rep[a] = (rep[a]==a) ? a : find(rep[a] ) ; }  
void uni(int a, int b){
	int ra = find(a);
	int rb = find(b);
	rep[ra] = rb;
}


int nums[30005];
int main (int argc, char const* argv[]) {
	int t, n, k, a, b;
	sc1(t);
	while(t--){
		sc2(n,k);
		ini(n);
		fr(i,0,k){
			sc2(a,b);
			uni(a,b);
		}
		mst(nums,0);
		int maior = 0, ra;
		fr(i,1,n+1){
			ra = find(i);
			nums[ra]++;
			maior = max(maior, nums[ra]);
		}
		printf("%d\n", maior);
	}
	
	
	return 0;
}












