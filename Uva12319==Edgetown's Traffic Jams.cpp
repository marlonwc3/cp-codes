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
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

int adjMatrix_1[105][105], adjMatrix_2[105][105];
int N;
bool go(bool first){
	fe(k,1,N) fe(i,1,N) fe(j,1,N){ 
		first ? adjMatrix_1[i][j] = min(adjMatrix_1[i][j], adjMatrix_1[i][k] + adjMatrix_1[k][j]) : adjMatrix_2[i][j] = min(adjMatrix_2[i][j], adjMatrix_2[i][k] + adjMatrix_2[k][j]);
	}
}


char line[ (100*3) + 15];
int main (int argc, char const* argv[]) {
	int a,b;
	int x,y;
	while(1){
		sc1(N); 
//		printf("N: %d\n", N);		
		iz(N);
		gets(line);
		fe(i,0,N) fe(j,0,N){adjMatrix_1[i][j] = adjMatrix_2[i][j]= (i!=j) ? inf : 0 ;  };		
		fe(i,1,N){
			gets(line);
//			printf("a: %d | line: %s \n", a, line);
			int cnt =0 ;
			for(char *pch = strtok(line, " "); pch; pch=strtok(NULL, " "), cnt++){
				sscanf(pch, "%d", &b);
				if(!cnt) a = b;	
				else adjMatrix_1[a][b]=1;
			}
		}
		go(1);
		fe(i,1,N){
			gets(line);
//			printf("a: %d | line: %s \n", a, line);
			int cnt =0 ;
			for(char *pch = strtok(line, " "); pch; pch=strtok(NULL, " "), cnt++){
				sscanf(pch, "%d", &b);
				if(!cnt) a = b;	
				else adjMatrix_2[a][b]=1;
			}
		}	
		go(0);
		sc2(x,y);
	//	printf("x: %d | y: %d\n", x, y);
		bool ok = 1;
		fe(i,1,N){
			fe(j,1,N){
	//			printf("(%d, %d) == |%d , %d| no max %d \n", i, j, adjMatrix_1[i][j], adjMatrix_2[i][j], adjMatrix_1[i][j]*x + y);
				if( adjMatrix_2[i][j] > adjMatrix_1[i][j]*x + y ) {
					
					ok =0; break;
				}
			
			}
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	//	break;
		
	}


	
	return 0;
}

