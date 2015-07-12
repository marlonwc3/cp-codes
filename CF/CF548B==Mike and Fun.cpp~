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



int mat[505][505];
int rows[505];
int N, M, Q;
int get(int r){
	int res = 0;
	int r2 = 0;
	int i  =1;
	while(i<=M){
		while( i <= M && mat[r][i] != 1 ) i++;
		r2 = 0;
		if(i<=M) r2 = 1;
		else break;
		i++;
		while(i <=M && mat[r][i] != 0 ) {r2++; i++; }
		res = max(res, r2);
	}
	res = max(res, r2);
	return res;

}


int main (int argc, char const* argv[]){

	sc3(N,M,Q);
	fe(i,1,N) fe(j,1,M) sc1(mat[i][j]);
	fe(i,1,N){
		rows[i] = get(i);
	//	printf("row %d | rows[i]: %d\n", i, rows[i]);
	}
	int a, b;
	fr(i,0,Q){
		sc2(a,b);
		mat[a][b] = !mat[a][b];
		rows[a] = get(a);
		int res = 0;
		fe(j,1,N){
		
			//printf("row %d | rows[i]: %d\n", j, rows[j]);		
			res = max(res, rows[j]);
		}	
		
		printf("%d\n", res);
			
	}
	
	
	return 0;
}
