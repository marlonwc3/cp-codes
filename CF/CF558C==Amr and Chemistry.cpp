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

#include <tr1/unordered_map>
using namespace tr1; 


const int MAIOR = 100000;
int pd_qnt[MAIOR+10], pd_sum[MAIOR+10];
int pd1[MAIOR+10];
int pd_ok[MAIOR+10];
int PASSO =0 ;

int S = 64;

int gerou[MAIOR+10], NEXT = 0;

int ans = inf;

int main (int argc, char const* argv[]){
	int N, x;
	int  k1, k2;
	int SL, SR; 
	sc1(N);
	fr(i,0,N) {
		sc1(x);
		k1 = x;
		PASSO++;
		NEXT = 0 ;
		fr(sl,0,S){
			k2 = k1;
			fr(sr,0,S){
				if(pd_ok[k2] != PASSO ){
					pd_ok[k2] = PASSO;
					pd_qnt[k2]++;
					pd1[k2] = sl+sr;
					gerou[NEXT++] = k2;
					//printf("NEXT: %d\n", NEXT);
					assert(NEXT < (16*16)+50 ); 
				}
				else pd1[k2] = min(pd1[k2], sl+sr);
				k2 >>= 1;
				if(k2 <= 0 ) break;  
			}
			k1 <<= 1;
			if(k1 > MAIOR ) break; 
		}
		k1 = x;
		fr(sl,0,S){
			k2 = k1;
			fr(sr,0,S){
				if(pd_ok[k2] != PASSO ){
					pd_ok[k2] = PASSO;
					pd_qnt[k2]++;
					pd1[k2] = sl+sr;
					gerou[NEXT++] = k2;
				}
				else pd1[k2] = min(pd1[k2], sl+sr);				
				k2 <<= 1; 
				if(k2 > MAIOR)  break;
			}
			k1 >>= 1;
			if(k1 <= 0 ) break; 
		}		
		int b;
		fr(j,0,NEXT) {
			b = gerou[j];
			pd_sum[b] += pd1[b]; 
			if(i==N-1 && pd_qnt[b] == N ){
				ans = min(ans, pd_sum[b] ); 
			}
		}
	
	}

	int q; 

	printf("%d\n", ans );
	
	
	
	return 0;
}



