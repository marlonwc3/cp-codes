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



int problems[12][4], N;
int is(int mask, int p) { return mask & (1<<p) ;}
int ative( int mask, int p) { return mask | (1<<p) ; }

struct State{
	int mask, last ,minuto,  cnt;
	State(){}
	State(int _mask, int _last, int _minuto, int _cnt){
		mask=_mask; minuto=_minuto; cnt=_cnt;
		last=_last;
	}
	bool operator < (const State s) const{
		if(minuto == s.minuto ) {
			return cnt < s.cnt;
		}
		return minuto > s.minuto;
	}
};

int dist[(1<<12) +5 ][5];

int res;
void go(){
	res = 0;
	priority_queue<State> pq;
	State state = State(0,0,0,0);
	mst(dist, inf);
	dist[0][0] = 0;
	pq.push(state);
	int mask, last, minuto, cnt, minuto_adj;
	int mask_adj;
	while(!pq.empty()){
		state = pq.top(); pq.pop();
		mask = state.mask, last = state.last, minuto = state.minuto, cnt = state.cnt;
	  //printf("mask: %d | last: %d | minuto: %d | cnt: %d \n", mask, last, minuto, cnt);

		if(minuto != dist[mask][last]) continue;
		res = max(res, cnt);
		fr(i,0,N){
			if( mask & (1<<i)) continue;
			mask_adj = mask | (1<<i);
			fe(j,1,3){
				if(j==last) continue;
				minuto_adj = minuto + problems[i][j];
				if(minuto_adj  > 280 ) continue;
				if(dist[mask_adj][j] > minuto_adj ){
					dist[mask_adj][j] = minuto_adj;
					pq.push(State(mask_adj, j, minuto_adj, cnt+1) );
					
				}
				
				
			
			}
		
		}
	
	
	}
	
	
	
	
}

int main (int argc, char const* argv[]){
//	mst(pd_ok, 0);
//	PASSO=0;
	int t;
	sc1(t);
	while(t--){
	//	PASSO++;
		sc1(N);
		fe(i,1,3){
			fr(j,0,N){
				sc1(problems[j][i]);
			}
		}	
		//printf("oi\n");
	//	mst(mark,0);
		go();
		printf("%d\n", res);
	}
	
	
	return 0;
}




