#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
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
typedef long double lb;

bool mycmp(ii a, ii b){
	if(a.st==b.st){
		return a.nd < b.nd;
	}
	return a.st>b.st;
}

int m[105][105];
ii pt[105];

int main (int argc, char const* argv[]) {
	int n, g, k, w, x, lol;
	while(1){
		sc2(n,g);
		if(!n && !g) break;

		fr(i,0,n){
			fr(j,0,g){
				sc1(k); k--;
				m[i][k] = j;
			}
		}
		sc1(k);
		fr(i,0,k){
			sc1(w);
			//printf("corrida %d\n", i);
			fr(j,0,g){
				pt[j].st = 0;
				pt[j].nd = j;
			}
			fr(j,0,w){
				sc1(x); // x pontos pro j-esimo lugar				
				fr(l,0,n){
					lol = m[l][j];
					pt[lol].st += x;
				}			
				
			}
			sort(pt, pt+g, mycmp);
			int maximo = pt[0].st;
			int j =0;
			while( j < g && pt[j].st == maximo ) {
				printf("%d ", pt[j].nd + 1);
				j++;
			}
			_
		}
		
		
		
		
	}	
		
	
	
	return 0;
}




















