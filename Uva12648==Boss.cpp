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

int idade[505];
vi pais[505];
int swaps[505];
int memo[505];

int findSwap(int a, int b){
	if(swaps[a] == b) return a;
	return findSwap( swaps[a], b  ); 
}


void swap(int a, int b){
	vi aux = pais[a];
	pais[a] = pais[b];
	pais[b] = aux;
	int la = findSwap(a, a);
	int lb = findSwap(b, b);
	int auxSwap = swaps[la];
	swaps[la] = swaps[lb];
	swaps[lb]=auxSwap;
	
}

int n;

int find(int a){
	int res = idade[a], s, adj;
	int acima = inf, pai;
	if(memo[a]!=-2) {
		return min(memo[a], idade[a]);
	}	
	s = pais[a].size();
	fr(i,0,s){
		adj = pais[a][i];
		pai = swaps[adj];
		acima = min( acima,  find(pai) ) ;
	}	
	res = min(res, acima);
	memo[a] = acima;
	return res;	
}

void atualize(){
	fr(i,0,n+1) memo[i]=-2;
	for(int j = 1; j<= n; j++){
		if(memo[j]==-2){
			find(j);
		}
	}

}
int main (int argc, char const* argv[]) {
	 int m, inst , a, b;
	char str[3];
	while( sc3(n,m,inst) == 3) {
		fr(i,0,n+2){ 
			pais[i].clear();
			swaps[i]=i;
		}
		fr(i,1,n+1){	
			sc1(idade[i]);
		}
		fr(i,0,m){
			sc2(a,b);
			pais[b].pb(a);
		}
		atualize();	
		fr(i,0,inst){
			scanf("%s", str);
			if(str[0]=='T'){
				sc2(a,b);
				swap(a,b);
				atualize();
			}
			else if (str[0]=='P'){
				sc1(a);			
				b = memo[a];
				if(b <= 0 || b >= inf ) printf("*\n");
				else printf("%d\n", b);
			}
		}	
	}
	return 0;
}


















