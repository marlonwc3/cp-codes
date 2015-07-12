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
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int adjMat[105][105], V;
int go(){
	fr(k,0,V){
		fr(i,0,V){
			fr(j,0,V){
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
			}
		}
	}
}

char str[100];
int main (int argc, char const* argv[]){
	
	while(sc1(V) ==1 ) {
		memset(adjMat, inf, sizeof adjMat);
		adjMat[0][0] = 0;
		fr(i,1,V){
			adjMat[i][i] = 0;
			fr(j,0,i){
				scanf("%s", str);
				if(str[0] =='x') continue;
				sscanf(str, "%d", &adjMat[i][j]);
				adjMat[j][i] = adjMat[i][j];
			}
		}
		go();
		int sum = 0;
		fr(i,1,V){
			//printf("%d\n", adjMat[0][i]);
			//sum += adjMat[0][i];
			sum = max(sum, adjMat[0][i]);
		}	
		printf("%d\n", sum);
	}
	
	return 0;
}



















