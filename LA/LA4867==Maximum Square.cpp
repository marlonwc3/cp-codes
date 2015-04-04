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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef pair<ll , ll> pll;

int n, m,  grid[1005][1005], arr[1005][1005];		
bool f(int tam){
		int r = -inf;
		int w;
		int res=0;
		fr(i,0,n){
			fr(j,0,m){
				int l = i+tam-1;
				int k = j+tam-1;
				if(l >= n || k >= m) continue;
		
				int sub = arr[l][k];
				if( i > 0 ) sub -= arr[i-1][k];
				if( j > 0 ) sub -= arr[l][j-1];
				if( i>0 && j > 0) sub += arr[i-1][j-1];					
			//	printf("l: %d |  k: %d sub: %d\n", l, k, sub);
				if(tam*tam == sub){
				 return 1;
				}			
				
			}
		}
		return 0;
}
int bs(int lo, int hi){
	if(lo+1 >= hi ) return 0;
	int mid = (lo+hi)/2;
	if(f(mid)) return max(mid, bs(mid, hi) );
	return bs(lo, mid);
}

int main (int argc, char const* argv[]){
	

		
		while(1) { 
			sc2(n,m); if(!n && !m) break;
			mst(arr, 0);	
			if(n==1 && m ==1 ) {
				sc1(n);
				printf("%d\n", n);
			}
			else{
				fr(i,0,n){
					fr(j,0,m){
						scanf("%1d", &arr[i][j]);
						if(i>0) arr[i][j] += arr[i-1][j];
						if(j>0) arr[i][j] += arr[i][j-1];
						if( i > 0 && j > 0 ) arr[i][j] -= arr[i-1][j-1];
					}
				}
			//	bool ok = f(2);
			//	printf("ok: %d\n", ok);
				//printf("');
				int res = bs(0, max(n,m) ) ;	
				printf("%d\n", res); // resposta	
			}
		}
	
	
	
	
	return 0;
}


