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

int N;

bool mark[500];

int K;
bool todos(){
	fe(i,K+1, 2*K) if(!mark[i]) return 0;
	return 1;
}


bool go(int k ){
	//printf("tentando k: %d\n", k);
	//k--;
	vi v; v.clear();
	fe(i,1,N){
		v.pb(i);
	}
	int s = N;
	int p = ( (k-1) %N);
	//pv(v,x);
	int x;
	mst(mark, 0);
	do { 
	
		//printf("p: %d\n", p);
		x = v[p];
	//	printf("morreu pos: %d | %d\n",p,  v[p] );		
		if( x <= K && !todos() ) {
			return 0;
		}
		mark[x] =1; 
		v.erase(v.begin() + p);
		//printf("s: %d\n", s);

		s--;
		if(s > 0 ) {
		//	printf("p-1: %d | k: %d | (p-1)+k: %d\n", p-1, k, p-1+k);
			p = ((p-1)+k)%s;
			if(p < 0 ) p = (p+s)%s;
		}
	} while ( s > 0 );
	return 1;
}


int bs(int lo, int hi){
	if( lo + 1>= hi ) return inf;
	int mid = (lo+hi)/2;
	if(go(mid)) return min(mid, bs(lo, mid));
	return bs(mid, hi);
}

int arr[14] = {
2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

int main (int argc, char const* argv[]){
	K =13;
	N =2*K;
	int r;
//	r = bs(29, 33);
	r = go(20);
	//printf("%d\n",r);

	//return 0;
	
	while(1){
		sc1(K); iz(K);
		//if(K==0 
		r = arr[K-1];
	//	N = 2*K;
		//int r = 0;
	//	fe(i,1000000,5*1000000){
		//	if(go(i)){r=i; break;}
	//	}
		
		printf("%d\n", r);
	
	}
	
	
	return 0;
}














