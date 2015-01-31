#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
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

int arr[13][10] = {
	{0,1,2,4,5,6,10},
	{2,6,10,10,10,10,10},
	{0,2,3,4,5,10,10},
	{0,2,3,5,6,10,10},
	{1,2,3,6,10,10,10},
	{0,1,3,5,6,10,10},
	{0,1,3,4,5,6,10},
	{0,2,6,10,10,10,10},
	{0,1,2,3,4,5,6},
	{0,1,2,3,5,6,10}
};
bool ok(int a, int b){ //a in b
	int k;
	fr(i,0,7){
		k = arr[a][i];
		if(k==10) continue;
		if(!binary_search(arr[b], arr[b]+7, k) ) { return 0;}
	}	
	return 1;
}
int main (int argc, char const* argv[]) {
	int a, b, c;
	sc1(c);
	a = c/10;
	b = c%10;
	sii res;
	fr(i,0,10){
		if(!ok(a,i) ) continue;
		fr(j,0,10){
			if(!ok(b, j) ) continue;	
			res.insert(mp(i,j));
		}
	}
	a = res.size();
	printf("%d\n", a);		
	return 0;
}
