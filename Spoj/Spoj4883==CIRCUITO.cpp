#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;

int arr[1005];

int main (int argc, char const* argv[]) {
	int p, n, m, k, cont;
	while(1){
		scanf("%d %d %d", &p, &n, &m);
		if(!p && !n && !m ) break;
		mst(arr, 0);
		cont=0;
		fr(i, 0, n){
			fr(j, 0, p){
				sc1(k);
				if(!k) arr[j] = 0;
				else arr[j]++;
				cont+= arr[j]==m;
			}
		}
		printf("%d\n", cont);
	}
	return 0;
}







