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
int x, y, k, n, m;
int matrix[325][245];
int my[15][15];

bool val(int dx, int dy){
	if( dx < 0 || dx >= n || dy < 0 || dy >= m) return 0;
	return 1;
}

int main (int argc, char const* argv[]) {
	int res = 0, t= 0;
	while(1){
		sc2(x,y);
		if(!x && !y ) break;
		t++;
		fr(i,0,x){
			fr(j,0,y){
				sc1(my[i][j]);			
			}
		}
		sc3(k, n, m);
		res = 0;
		while(k--){
			fr(i,0,n){
				fr(j,0,m){
					sc1(matrix[i][j]);
					//printf("%d ",matrix[i][j]);
				}
//				_
			}
			
			
			
			bool ok; int dx, dy;
			fr(i,0,n){
				fr(j,0,m){
					ok = 1;
					fr(a,0,x){
						fr(b,0,y){
							dx = i+a, dy = j+b;
							if(!val(dx,dy) || matrix[dx][dy]!=my[a][b]){
								ok = 0;
								goto label;
							}

						}
					}
					label:;
					if(ok){
						res ++;
					}
				
				}
			}
		
			
		}

		printf("Logotipo %d\n%d\n\n", t,res);
		
	
	}
	
	
	
	return 0;
}



















