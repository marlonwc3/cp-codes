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
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

string line;
int N;

vi v;
int main (int argc, char const* argv[]){
	while(1){
		sc1(N); iz(N);
		getline(cin,line);

		v.clear();
		int menor= inf;		
		fr(i,0,N){
			getline(cin,line);
			//printf("line: %s\n", line.c_str());
			int p1 =-inf,p2 = inf;
			fr(i,0,line.length()){
				if(line[i]=='B' || line[i]==' ') {p1 = i; break; }
			}
			for(int i = line.length()-1; i>=0; i-- ){
			if(line[i]=='B' || line[i]==' ') {p2 = i; break; }
			}
			
			
		//	printf("p1: %d | p2 :%d\n", p1, p2 );	
			if(p1 == -inf || p2 == inf ) {
				v.pb(0);
			}
			else {
			
				v.pb(p2 - p1 + 1);
					
			}				
			menor = min(menor, v.back());
		
		}
	//	printf("menor: %d\n", menor);
			int s = 0;
			fr(i,0,v.size()){
				//printf("v[i] :%d\n", v[i] );
				s += v[i] - menor;
			}
			printf("%d\n", s);
			
		
		
	}
	
	
	return 0;
}

















