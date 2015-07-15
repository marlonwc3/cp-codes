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
#define oi(x) cout <<"Oi [" << x << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef   long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int mycmp(double a , double b = 0.0 ) {
	if(fabs(a-b) <= EPS ) return 0;
	return a>b ? 1 : -1;
}


ll N, S, Y;

const int MAX_N =  1000000;
pair<ll, ll> todos[MAX_N + 5] ;
ll res[MAX_N +5];
int pode[MAX_N+5], PASSO = 0;

int main (int argc, char const* argv[]){
	ll a, b,c, d;
	int caso = 1;
	while(scanf("%lld %lld %lld", &N,&S,&Y) == 3 ){
		//if(caso++==24) printf("CASO %d %d %lld\n", N,S,Y );
		PASSO++;
		fr(i,0,S){
			scanf("%lld %lld", &todos[i].st, &todos[i].nd );
		}
		sort(todos, todos+S);
		double total = Y;
		fr(i,0,S-1){ 
			a = todos[i].st, b = todos[i].nd, c = todos[i+1].st, d = todos[i+1].nd;
		//	oi(a);
			total -= (c-(a))*(min(b,d));
//			print-f("c: %d | a: %d | area tirar: %d\n", c, a, (c-(a))*(min(b,d)) );
			total -= abs(b-d)/2.0;
			fe(j,a+1,c-1){
				pode[j] = PASSO;
				//oi(j);
				res[j] = min(b,d);		
			//	oi("b: "); oi(b);
			//	oi("d: "); oi(d);
				//oi("res:"); oi(res[j] );
			}
		}
//		printf("final Y: %
		bool lasco = 0 ;
		if(mycmp(total) == -1 || fmod(total, 1) != 0 ) {  
			lasco = 1;
			//printf("fudeu\n"); 
		} 
		else{ 	
			Y = total; 
			//printf("nao tem virgula | Y: %d \n", Y); 
			//fe(i,0,N) if(pode[i] == PASSO) printf("(%d) ", res[i] ); _
		

			ll q, h, d2, d3;
			for(int i = S-1; i>=1; i-- ){
				c = todos[i].st, d = todos[i].nd, a = todos[i-1].st, b = todos[i-1].nd;
				q = (c-(a+1));
				h = abs(b-d);
				if( Y >= q*h ) {
					//printf("cheguei aqui Y: %d\n" , Y );
					 fe(j,a+1,c-1) res[j] = max(b,d);
					Y -= q*h;
					continue;
				}
				//printf("h: %d	\n", h );
				if(d > b ) {				
					//printf("CHEGOU | Y: %d\n", Y );
					for(int j = c-1; j >= a+1; j-- ){
						d2 = min(Y, h);
						res[j] += d2;
						Y -= d2;
					}				
				}
				else{
					if(q ) {

						d3 = Y/q;
						Y -= d3*q;
						d2 = Y%q; 

						//printf("Oi ! d3: %d | q: %d | d2: %d \n", d3 , q , d2); 
						for(int j=a+1, k = 0;   j<= c-1; j++, k++   ) {
							//printf("j: %d | res[j]: %d\n", j, res[j] ); 
							res[j]+= (k < d2) + d3;
							if(k < d2 ) Y--;
						}
					}
				}
			
			
					
			}
			if( Y > 0 ) lasco = 1;
		}
		if(lasco) printf("N\n");
		else{
			printf("S");
			//bool first = 1;
			fe(i,0,N) if(pode[i] == PASSO){
			  printf(" %lld", res[i] ); 
			  //first = 0;  
			}
			_	
		}	
		
	
	
	}
	
	
	return 0;
}



























