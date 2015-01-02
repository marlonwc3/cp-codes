#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

ii arr[200005];
int n;

int main (int argc, char *argv[]) {
	ii p; ii middle; int a, b;
	int contA, contB;
	
	while( 1 ) { 
		sc1(n); iz(n);
		contA = contB =0;
		fr(i,0,n){
			sc2(a,b);
			p = mp(a,b);	
			if( i == n/2) middle = p;			
			arr[i] = p;			
		}
		
		fr(i,0,n) {
			contA +=  ( ( arr[i].st > middle.st && arr[i].nd > middle.nd ) || ( arr[i].st < middle.st && arr[i].nd < middle.nd  ) );
			
			contB +=  ( arr[i].st < middle.st && arr[i].nd > middle.nd ) || ( arr[i].st > middle.st && arr[i].nd < middle.nd);
			
		}
		
		printf("%d %d\n", contA, contB );
		
	}
	return 0;
}




