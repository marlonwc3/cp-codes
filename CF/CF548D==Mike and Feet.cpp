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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const int MAX_N = 2*(100000);
int L[MAX_N+10], R[MAX_N+10];
int arr[MAX_N+10], N;
int freq[MAX_N+10];

int main (int argc, char const* argv[]){
	sc1(N);
	fe(i,1,N) sc1(arr[i]);
	int k;
	stack<int> lol;
	int menor = inf;
	fe(i,1,N){
		k = arr[i];
		menor = min(menor , k);
		while(!lol.empty() && arr[lol.top()] >= k) lol.pop();
		if(lol.empty() ) L[i] = 0;
		else L[i] = lol.top();
		lol.push(i);
	}
	lol = stack<int>();
	for(int i = N; i >= 1; i--){
		k = arr[i];
		while(!lol.empty() && arr[lol.top()] >= k) lol.pop();
		if(lol.empty() ) R[i] = N+1;
		else R[i] = lol.top();
		lol.push(i);
	}	

	if(0 ) fe(i,1,N){
		printf("i: %d | arr:%d | L[i]: %d | R[i]: %d \n", i, arr[i], L[i] , R[i] );
	}
	mst(freq, 0);

	int d;
	fe(i,1,N){	
		d = R[i] - L[i] - 1;
		//d = (R[i]-1) - (L[i]+1) - 1;
	//	printf("i:%d |  ate: %d |  arr[i]: %d\n", i, d, arr[i]);
		freq[d] = max(freq[d], arr[i]);
	}	
	freq[N] = max(freq[N], menor);
	for(int i = N; i >= 1; i--) freq[i] = max(freq[i], freq[i+1]);
	printf("%d", freq[1]);
	fe(i,2,N) printf(" %d", freq[i]); _

	
	
	
	
	
	
	
	
	return 0;
}
