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

int num[1005], low[1005];
vi e[1005];
stack<int> myst;
int NODE_CNT, NEXT_COMPO;
vi compo[1005];
int mark[1005], PASSO;
void go(int no){
	num[no] = low[no] = NODE_CNT++;
	mark[no] = PASSO;
	int s = e[no].size(), adj;
	myst.push(no);
	bool ok = 0;
	fr(i,0,s){
		adj = e[no][i];
		if(!num[adj]){
			ok = 1;
			go(adj);
		}
		if(mark[adj] == PASSO ){
			low[no] = min(low[no], low[adj]);
		}
	}
	//printf("no: %d | low %d | num no %d\n", no, low[no], num[no] );
	if(low[no] == num[no]){
	//	printf("[fortemente]\n");
		while( myst.top() != no ) {
			compo[NEXT_COMPO].pb(myst.top());
	//		printf("%d ", myst.top() );
			mark[myst.top()] = PASSO-1;
			myst.pop();
			
		}
		compo[NEXT_COMPO].pb(myst.top());
		mark[myst.top()] = PASSO-1;		
//		printf("%d ", myst.top() );		
//		_
		myst.pop();		
		NEXT_COMPO++;
	}
}




map<string, int> mymap;
int NEXT;
int get(string s){
	int r = mymap[s];
	if(!r) r =  mymap[s] = NEXT++;
	return r;
}

string line, line2;
int main (int argc, char const* argv[]) {
	int p, t, a, b;	
	while( 1  ){
		sc2(p,t); if(!p && !t) break;
		getline(cin,line);
		fe(i,0,p){
			num[i] = low[i] = 0;
			e[i].clear();
		}
		PASSO++;
		myst = stack<int>();
		NODE_CNT = 1; NEXT_COMPO = 0;
		NEXT = 1;
		mymap.clear();
		fe(i,0,1000) compo[i].clear();	
		fr(i,0,p){
			getline(cin,line);
			a = get(line);
		}
		fr(i,0,t){
			getline(cin,line); a = get(line);
			getline(cin,line2); b = get(line2);
			e[a].pb(b);
			//printf("%d -> %d\n", a, b);
		}
		fr(i,1,NEXT){
			if(!num[i]){
				go(i);
			}
		}
		printf("%d\n", NEXT_COMPO);
	
	
	}
	
	
	
	
	return 0;
}
















