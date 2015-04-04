#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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

int arr[50], t;
int cmp(double a, double b){
	if(fabs(a-b) < EPS ) return 0;
	return (a>b) ? 1 : -1;
}
double f(double r){
	double x = (1+r) , sum = 0;
	fe(i,0,t){
		sum += arr[i]*pow(x, t-i);
	}
	return sum;
}
double res;
bool bs(){
	double lo = -1, hi = 1e9, mid, val;
	res = 0;
	while( fabs(hi-lo) > 1e-7 ){
		mid = (hi+lo)/2;
		val = f(mid);
		if(cmp(val,0 )==0 ){
			res =  mid;
			return 1;
		}
		if(cmp(val, 0) == -1  )	 hi = mid;
		else  lo = mid;

	}
	res = mid;	
	return 0;	
}
int main (int argc, char const* argv[]) {
	while(1){
		sc1(t); iz(t);
		fe(i,0,t) sc1(arr[i]);
		bs();
		printf("%.2lf\n", res);
	}
	return 0;
}

























