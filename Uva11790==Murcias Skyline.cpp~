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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
 
int arr[2005];
int arr2[2005];
int n;

ll pd[2005][2005][3];

	

ll go(int p, int last, bool inc){
	if(p > n ) return 0;
	if(pd[p][last][inc] != -1 ) return pd[p][last][inc];
	//printf("p: %d | last: %d\n", p, last);
	ll r = go(p+1, last, inc);
	
	ll r2 = 0;
	if(inc){
		if(arr[p] > arr[last]) {
			r2 = arr2[p];
			r2 += go(p+1, p, inc);			
		}	
	}
	else {
		if(arr[p] < arr[last]) {
			//printf("p: %d | %d < %d\n", p, arr[p], last);
			r2 = arr2[p];
			r2 += go(p+1, p, inc);			
		}
	} 

	r = max(r, r2);
	//printf("[RES]p: %d | last: %d | Res %lld\n", p, last, r);

	return pd[p][last][inc] =  r;
	
	
	
}


int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	fe(t,1,caso){
		sc1(n);
		fe(i,1,n){ sc1(arr[i]); }
		fe(i,1,n){ sc1(arr2[i]); }
	
	
		//mst(pd, -1);
		
		fe(i,0,n+3){
			fe(j,0,n+3){
				pd[i][j][0]=pd[i][j][1] = -1;
			}
			
		}
		
		arr[n+3] = inf;
		arr[0] = -1;		
		ll r1, r2;
		r1 = go(1, 0, 1);

		arr[n+3] = inf;
		arr[0] = -1;	
		
		r2 = go(1, n+3, 0);
		//printf("r1 : %lld | r2: %lld\n", r1, r2);
		if(r1 >= r2){
			printf("Case %d. Increasing (%lld). Decreasing (%lld).\n", t, r1, r2);
		}
		else{
			printf("Case %d. Decreasing (%lld). Increasing (%lld).\n", t, r2, r1);
		}


	}
	
	
	return 0;
}















