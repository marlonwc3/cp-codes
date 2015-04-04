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
//#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll , ll> pll;

vii v;
int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	int N, W, a, b;
	fe(t,1,caso){
		v.clear();
		sc2(W,N);
		int sum = 0;
		int k = 0;
		int curr = 0;
		int last= 0;
		fr(i,0,N){
			
			sc2(a,b);
			sum += a-last;
			last = a;
		//	printf("k: %d | sum: %d | curr %d\n", k, sum ,curr);
			if(curr+b > W ){
		//		printf("entrou\n");
				curr = 0;	
				sum += 2*a;
		//		printf("nva %d\n", sum);
			}
			curr += b;
			if(curr==W){
				
				if(i!= N-1){
			//	printf("Entrou 2\n");
					sum +=  2*a;
					curr = 0;
				}
			}
			
		}
	//	printf("k: %d %d\n", k, sum);		
		sum += last;
		printf("%d\n", sum);
	
	
	}
	
	
	
	return 0;
}





