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



int price[5];
int n,m;
int arr1[1005], arr2[1005]; // bus troller
int main (int argc, char const* argv[]) {
	fr(i,0,4) sc1(price[i]);
	sc2(n,m);
	int s1=0,s2=0; 
	fr(i,0,n) {
		sc1(arr1[i]);
		if(arr1[i]*price[0] > price[1]){
			s1 += price[1];
		}	
		else s1 += arr1[i]*price[0]; 
	}
	fr(i,0,m) {
		sc1(arr2[i]);
		if(arr2[i]*price[0] > price[1] ){
			s2 += price[1];
		}
		else s2 += arr2[i]*price[0];
	}
	int total = s1+s2, res = total;
	res = min(res, total - s1 + price[2] );
	res = min(res, total - s2 + price[2] );
	res = min(res, total - s1 - s2 + 2*price[2] );
	res = min(res, price[3] );
	printf("%d\n", res);
	return 0;
}


