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
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int zr[105], zc[105];
int matrix[105][105];
int mres[105][105]; // matriz de resposta
int n,m;

bool solve(){
	fr(i,0,n){
		fr(j,0,m){
			if(matrix[i][j]){
				if(zr[i]!=0 && zc[j]!=0) {
					return 0; 
				}
				if(zr[i]==0 && zc[j]==0) {
					mres[i][j]=1;
				}
			}
		}
	}
	return 1;
}

int main (int argc, char const* argv[]) {
	int k;
	sc2(n,m);
	bool ok1, ok2; ok1=ok2=0;
	fr(i,0,n){
		fr(j,0,m){
			sc1(k); matrix[i][j] = k;
			if(!k) {
				zr[i]++;
				zc[j]++;
			}
		}
		if(zr[i]==0) ok1=1;
	}
	fr(j,0,m){
		ok2 = ok2 || !zc[j];
	}
	if (  (ok1 && !ok2 ) || (!ok1 && ok2 ) ){
		printf("NO\n");
	}
	else {
		ok1 = solve();
		if(!ok1){
			printf("NO\n");
		}
		else {
			printf("YES\n");
			fr(i,0,n){
				fr(j,0,m){
					printf("%d", mres[i][j]);
					if(j!=m-1) printf(" ");
				}
				_
			}
		}
	}
	return 0;
}









