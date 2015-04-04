#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b)  if(!b) {break;}
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a,b) memset(a, b, sizeof (a))
#define fr(i,a,b) for(int i = (a); i < (b); i++)
#define fe(i,a,b) for(int i = (a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a,i) for(int i =0; i < (a.size()); i++ ) { printf("%d ", a[i]); if(i != a.size() -1) printf(" "); }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;


int arr[100];
int arr2[100];
int n;

int get(int k){
	fr(i,0,n) if(arr[i]==k) return i;
}
int get2(int k){
	fr(i,0,n) if(arr2[i]==k) return i;
}

int main (int argc, char const* argv[]) {
	
	while(sc1(n)==1){
		fr(i,0,n){
			sc1(arr[i]);
		}
		fr(i,0,n){
			sc1(arr2[i]);
		}
		
		int cnt = 0;
		for(int i = n-1; i>= 0; i--){
			int k = arr2[i];
			int p = get(k);
			//printf("k: %d | p? %d\n", k, p);
			for(int j = p +1; j < n; j++){
				int w = get2(arr[j]);

				if( w < i ) cnt++;
			}
			
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
