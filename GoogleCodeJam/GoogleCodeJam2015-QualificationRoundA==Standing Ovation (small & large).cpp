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






#define MAX_N 1010
char line[MAX_N];
int N;
int total;

bool f(int k){
	int sum = 0;
	fe(i,0,N){
		if(sum + k >= i ){
			sum+=line[i]-'0';
		}
	}
	return sum >= total;
}

int bs(int lo, int hi){
	if(lo+1 >= hi ) return inf;
	int mid = (lo+hi)/2;
	if(f(mid)) return min(mid, bs(lo, mid));
	return bs(mid, hi);
}



int main (int argc, char *argv[]) {
	int caso;
	sc1(caso);
	int sum;
	fe(t,1,caso){
		scanf("%d %s", &N, line);
		total = 0;
		fe(i,0,N){
			total += line[i] - '0';
		}
		sum = bs(-1, (total*10) + 30);
		printf("Case #%d: %d\n", t, sum);
	
	}
	
	
	return 0;
}


















