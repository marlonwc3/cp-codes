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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef pair<char, int> ci;


vii adjList[60];
list<int>  cyc;
void EulerTour(list<int>::iterator i, int u){	
	//printf("am\n");
	for(int  j= 0; j < adjList[u].size(); j++){
		ii v = adjList[u][j];
		if(v.nd){
			adjList[u][j].nd = 0;
			for(int k = 0; k < adjList[v.st].size(); k++){
				ii uu = adjList[v.st][k];
				if(uu.st == u && uu.nd ) {
					adjList[v.st][k].nd = 0;
					break;
				}
			}
			
			EulerTour(cyc.insert(i, u) , v.st );
		}
		
		
	}
}

int rep[55];
int init(int n) { fe(i,0,n) rep[i]=i; }
int find(int a) { return rep[a] = (rep[a]==a) ? a: find(rep[a]);  }
void uni(int a, int b) { rep[find(a)] = find(b);  }
bool iss(int a,int b){ return find(a) == find(b) ;}



int N;
int freq[55];
vi v;
int main (int argc, char const* argv[]){
	int caso, a,b;
	bool first = 1;
	sc1(caso);
	fe(T,1,caso){
		if(!first) _
		fe(i,0,54) adjList[i].clear();
		sc1(N);
		init(51);
		mst(freq,0);
		v.clear();
		//printf("N: %d\n", N);
		
		fr(i,0,N){
			sc2(a,b);
			adjList[a].pb(mp(b,1));
			adjList[b].pb(mp(a,1));
			uni(a,b);
			
			freq[a]++; if(freq[a] == 1 ) v.pb(a);
			freq[b]++; if(freq[b] == 1 ) v.pb(b);
		}
		bool ok = 1;
		for( int i =0; i< v.size() ; i++ ) {
			if(adjList[v[i]].size() % 2 != 0 ) {ok=0; break; }
			
		
		
		}
		
		int r = find(v[0]);
		fr(i,1,v.size()){
			if(!iss(r,find(v[i]))) {ok=0; break;}
		}
		
		printf("Case #%d\n", T);
		if(!ok) printf("some beads may be lost\n");
		else{
			cyc.clear();
			EulerTour(cyc.begin(), v[0] );
			cyc.push_back(cyc.front()  );
			//printf("oi!\n");
			for(list<int>::iterator it = cyc.begin(), it2 = it++; it != cyc.end(); it++, it2++ ){
				a = *it2; b = *it;
				printf("%d %d\n", a, b);
				
			}
		//	printf("%d %d\n", cyc.back() , cyc[0] );
		
		}

		first =0 ;
	}
	
	
	return 0;
}














