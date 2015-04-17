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

#define MAX_N 5800
ll pd[MAX_N][MAX_N], N;
pair<ll, ll> arr[MAX_N];

bool mycmp( ii a, ii b){
	if(a.nd == b.nd ) return a.st < b.st;
	return a.nd < b.nd;
}

int main (int argc, char const* argv[]){
	int N = 1;
	ll a, b;
	while ( scanf("%lld %lld", &a, &b) == 2) {
		arr[N++] = mp(a,b);
	}
	//printf("N: %d\n", N);
	sort(arr, arr+N, mycmp);
	//fr(i,1,N) printf("(%lld, %lld) ", arr[i].st, arr[i].nd );
	//_
	int r = 0;
	fe(i,0,N) fe(j,0,N) pd[i][j] = linf;
	
	fr(i,1,N) pd[1][i] = (arr[i].st <= arr[i].nd ) ? arr[i].st : linf;
	
	//pd[1][0] = 0;
	fr(i,0,N) pd[0][i] = 0; 
	
	fr(i,1,N){
		//printf("[i]: %d\n", i);
		fr(j,1,N){
			//printf("[j]: %d  | (%lld %lld) \n", j, arr[j].st, arr[j].nd );
			pd[i][j] = min(pd[i][j], pd[i][j-1]);
			if( pd[i-1][j-1] + arr[j].st <= arr[j].nd && pd[i][j] > pd[i-1][j-1] + arr[j].st ) {
				pd[i][j] = pd[i-1][j-1] + arr[j].st;
				r = max(r, i);
			}
			//printf("depois pd[%d][%d]: %lld\n", i, j, pd[i][j]);
		
		
		}
	
	}
	printf("%d\n", r);
	
	
	return 0;
}










