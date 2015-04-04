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

int matrix[105][105];
int dim[105][2];
int n, k;

int main (int argc, char const* argv[]) {
	sc2(n,k);
	fr(i,0,n){
		sc1(dim[i][0]);
	}
	while(1){
		fe(i,1,k){
			fr(j,0,n){
				if(dim[j][1] >= dim[j][0]) continue;
				matrix[j][ dim[j][1]  ] = i;
				dim[j][1]++;
			}
		}

		bool sair = 1;
		fr(i,0,n){
			sair= sair && (dim[i][1] >= dim[i][0]);
		}
		if(sair) break;
	
	
	
	}
	vi v;
	bool ok=1;
	vi res[105];

		fe(i,1,k){
			v.clear();
			int cnt;
			//printf("comecando cor %d\n", i);
			fr(j,0,n){
				cnt = 0;
				//printf("j: %d | dim: %d \n", j, dim[j][0] );
				fr(l,0,dim[j][0]){
					//printf("%d ",  matrix[j][l] ); 
					if(!matrix[j][l]) {ok = 0; break;}
					res[j].pb( matrix[j][l] );
					if(matrix[j][l]==i) cnt++;
				}
				//_
				v.pb(cnt);
			}
			//printf("cor: %d cnt de j %d\n", i, cnt);
			if(!ok) break;
			sort(v.begin(), v.end());
			if( v.back() - v[0] > 1 ) { ok =0; break;}
		}

	
	
	if(ok){
		printf("YES\n");
		fr(i,0,n){
			printf("%d", res[i][0]);
			fr(j,1,dim[i][0]){
				printf(" %d", res[i][j]);
			}
			_
		}

	}
	else printf("NO\n");
	

	

	
	
	
	
	
	
	return 0;
}



