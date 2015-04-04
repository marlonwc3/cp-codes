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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


vi e[2035];
int num[2035], low[2035], scc[2035];
stack<int> mystack;
int NODE_CNT, PASSO, NEXT_SCC;
int mark[2035];
int neg[2035];
bool OK;
void go(int no){
	if(!OK) return;
	num[no] = low[no] = NODE_CNT++;
	int s = e[no].size(), adj;
	mark[no] = PASSO;
	mystack.push(no);
	//printf("no: %d na pilha | markno: %d | num %d | low %d \n", no, mark[no], num[no], low[no] );
	fr(i,0,s){
		adj = e[no][i];
//		printf("adj: %d\n", adj);
		if(!num[adj]){
			go(adj);
		}
		if(mark[adj] == PASSO ){
			low[no] = min(low[no],  low[adj]);
		}	
	}
	if(num[no] == low[no] ){
	//	printf("no: %d eh root\n", no);
		while(1){
			adj = mystack.top(); mystack.pop();	
			mark[adj] = PASSO-1;
			scc[adj] = NEXT_SCC;
			if(scc[adj] == scc[neg[adj]]) {OK = 0; break;}
			if(no == adj) break;
		}	
		NEXT_SCC++;
		
	}
	
	
}



int NEXT;
map<string, int> mymap;
int get(string s){
	int r = mymap[s];
	if(!r) r = mymap[s] = NEXT++;
	return r;
}
string auxNeg;
int getneg(string s1){
	if(s1[0] == '!') s1 = s1.substr(1);
	else s1 = auxNeg + s1;
	return get(s1);
}


char str1[40], str2[40];
int main (int argc, char const* argv[]) {
	auxNeg = '!';
	int n, a, b, na, nb, t = 0;
	string s1,s2;
	while(sc1(n)==1){
		t++;
		mymap.clear();
		NEXT = 1;
		NODE_CNT = 1;
		PASSO++;
		NEXT_SCC = 1;
		mystack = stack<int>();
		fe(i,0,2020){
		 	e[i].clear();
		 	scc[i] = 0;
		 	num[i]=low[i]=0;
		}
		fr(i,0,n){
			scanf("%s %s", str1, str2);
			a = get(str1); b = get(str2);
			na = getneg(str1); nb = getneg(str2);	
			e[na].pb(b);
			e[nb].pb(a);
			neg[a] = na; neg[na] = a;
			neg[b] = nb; neg[nb] = b;
			
			
		}
		if(0) fr(i,1,NEXT){
			//printf("i: %d | neg: %d \n", i, neg[i] );
			fr(j,0,e[i].size()){
				printf("%d ", e[i][j]);
			}
			if(!e[i].empty())_
		}
	//	printf("Rodando SCC\n");
		OK = 1;		
		for(int i=1; i < NEXT && OK; i++){
			//printf("Nao scc: %d\n", i);
			if(!scc[i]){
				go(i);
			}
		}
		printf("Instancia %d\n", t);
		if(OK) printf("sim\n");
		else printf("nao\n");
		_
	}
	
	
	return 0;
}

















