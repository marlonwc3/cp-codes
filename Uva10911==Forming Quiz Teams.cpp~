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

#define on(k,p) ((k) | (1<<(p)) )
#define is(k,p) ((k) & (1<<(p) ) )

int cmp(double a, double b=0.0){
	if(fabs(a-b) < EPS) return 0; 
	return (a>b) ? 1 : -1;
}
ii arr[19];
int N;

double pd[(1<<(16)) +3 ];
int pd_ok[(1<<(16)) +3 ], PASSO;

double dist(ii a, ii b){
	return sqrt( (a.st - b.st)*(a.st - b.st) + (a.nd - b.nd)*(a.nd - b.nd)  );
}

void tobin(int n){
	printf("To bin (%d): ", n);
	if(!n) printf("0\n");
	while(n) { printf("%d", n%2); n/=2;} _
}

//int lol;
double go(int p, int mask){
		//printf("mask: %d\n", mask); tobin(mask);
	if(mask >= ((1<<(2*N))-1 ) ) {
	//	printf("mask: %d\n", mask); tobin(mask);
		return 0;
	}
	//lol = max(lol, mask);
	if(pd_ok[mask] == PASSO ) return pd[mask];
	double res = double(inf), r2;
	int mask_adj;

	fr(i,0,2*N){
//		printf("");
		if((is(mask, i)) ) continue;
		//printf("oi\n");
		fr(j,i+1,2*N){
			if((is(mask, j) )) continue;
			mask_adj = on(mask, i);
			mask_adj = on(mask_adj, j);
		//	tobin(mask_adj);
			r2 = dist(arr[i], arr[j] ) + go(p+1, mask_adj);
			if(cmp(r2, res) == -1 ) res = r2;
		}	
	}
	pd_ok[mask] = PASSO;
	return pd[mask] = res;
}




char str[30];
int main (int argc, char const* argv[]) {
	int x,y;
	PASSO=1;
	int t = 0;
	/*
	int k;
	N =8;
	int w = 1<<(15);
	tobin(w);
	k = pd[w];
	
	w--;
	tobin(w);
	k = pd[w];
	
	lol =0;
	*/
	//return 0;
	while(1){
		sc1(N); iz(N);
		t++;
		fr(i,0,2*N){
			scanf("%s %d %d", str, &x, &y);
			arr[i] = mp(x,y);
		}
		double r = go(0, 0);
		printf("Case %d: %.2lf\n", t, r);
	
		PASSO++;	
	//	tobin(lol);
	}
	
	return 0;
}













