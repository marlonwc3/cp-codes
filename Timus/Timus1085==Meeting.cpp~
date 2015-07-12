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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vi e[105];
vi rotas[105]; // rotas das paradas
vi tem[105];  // que cidades tem a i-esima rota
int mat[105][105];
int N, M;
void fw(){
	fe(k,1,M){
		fe(i,1,M){
			fe(j,1,M) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j] ); 	
		}
	}

}

void pf(){
	fe(i,1,M) {
		printf("[%d]: ", i);
		fe(j,1,M) printf("%d ", mat[i][j]); 
		_
	}
}

int money[105];
int ini[105];
int livre[105];
int dist[105][105]; // distance entre cidades
int quais[105][105];

int main (int argc, char const* argv[]){
	mst(mat, inf);
	mst(dist, inf);
	int L, k;
	sc2(N,M);
	fe(i,1,M){
		sc1(L);
		fr(j,0,L){
			sc1(k);
			rotas[k].pb(i);
			tem[i].pb(k);
			
		}
	}	
	int boy, p2;
	fe(i,1,M){
		fr(j,0,tem[i].size()){
			boy =  tem[i][j];
			fr(l,0,rotas[boy].size()){
				p2 = rotas[boy][l];
				mat[i][p2] = 4;
				mat[p2][i] = 4;
			}
		}
		mat[i][i] = 0;
	}
	//pf();
	fw();
	//pf();
	int Q, a, b, c;
	sc1(Q);
	fr(i,0,Q){
		sc3(money[i], ini[i], livre[i]);
	}
	fe(i,1,N){
		fe(j,1,N){
			fr(l,0,rotas[i].size()){
				fr(k,0,rotas[j].size()){
					dist[i][j] = min(dist[i][j], mat[rotas[i][l]][rotas[j][k]]);
					
				}
			}
		}
		dist[i][i] = 0;
	}
	if(0) fe(i,1,N){
		printf("Cidade (%d): ", i);
		fe(j,1,N){
			printf(" %d", dist[i][j]);
		}
		_
	}
		
	
	
//	return 0;
	
	int ans = inf, acc, k2, custo, r2 = 0;
	fe(i,1,N){
		acc = 0;
		fr(j,0,Q){
			if(dist[ini[j]][i] >= inf) {
				acc = inf; break;
			}
			if(livre[j]) continue;
			if(ini[j] != i ) custo = 4;
			else custo = 0; 
			custo += dist[ini[j]][i];
			if(money[j] < custo ){ acc = inf; break; }
			acc += custo;
		}
		if( acc < ans ) {
			//printf("melhor comecar em %d | %d\n", i, acc); 
			ans = acc;
			r2 = i;
		}
		//printf("cidade %d -> %d\n", i, acc);
	
	}
	if( ans >= inf ) printf("0\n");
	else printf("%d %d\n", r2, ans);
	
	
	return 0;
}













