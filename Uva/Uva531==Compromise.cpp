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

vector<string> v1;
vector<string> v2;
#define MAX_N 105
int pd[MAX_N][MAX_N], pd_ok[MAX_N][MAX_N], PASSO;
ii pai[MAX_N][MAX_N];
int go(int i, int j){
	if(i>=v1.size() || j>=v2.size() ) return 0;

	if(pd_ok[i][j] ==PASSO) return pd[i][j];
//	printf("i: %d | j: %d\n", i, j);	
	int r= 0;
	r = go(i+1, j);
	if(r > pd[i][j] ){
		pd[i][j] = r;
		pai[i][j] = mp(i+1, j);
	}
	r = go(i, j+1);
	if(r > pd[i][j] ){
		pd[i][j] = r;
		pai[i][j] = mp(i, j+1);
	}
	r = go(i+1, j+1);
//	printf("r: %d \n" , r);
	if(v1[i] == v2[j]) r++;
	if(r > pd[i][j] ){
		pd[i][j] = r;
		pai[i][j] = mp(i+1, j+1);
	}
	//printf("i: %d | j: %d | pd[i][j]: %d | pai: %d %d\n", i ,j, pd[i][j], pai[i][j].st, pai[i][j].nd ) ;
	pd_ok[i][j] = PASSO;
	return pd[i][j];
}

char line[35*100];
void add(int v){
	for(char *pch = strtok(line, " "); pch; pch =strtok(NULL, " ")){
		if(v) v1.pb(pch);
		else v2.pb(pch);
	}
}

vector<string> res;
void getPath( ii p ) {
	if(p.st == 102 ) return;
	int pi = pai[p.st][p.nd].st, pj = pai[p.st][p.nd].nd;
	if(pd[p.st][p.nd] > pd[pi][pj] ) {
		res.pb(v1[p.st]);
	} 
	getPath(mp(pi,pj));

}
	
int main (int argc, char const* argv[]){
	int c1, c2;
	PASSO =0;
	while( gets(line) ){
	//while(1) { 
		v1.clear(); v2.clear();
		PASSO++;


		add(1);
		while(1){
			gets(line);
			if(line[0]=='#') break;
			add(1);
		}
			
		while(1) {
			gets(line);
			if(line[0]=='#') break;
			add(0);		
		}
		c1 = v1.size(); 
		c2 = v2.size();
		fe(i,0,c1) fe(j,0,c2){
			pd[i][j] = 0;
			pai[i][j] = mp(102,102);
		}
		pd[102][102] = 0;
		pai[102][102] = mp(-1,-1);
		int r = go(0,0);
		if(0){
			fr(i,0,v1.size() ) printf("[%s] ", v1[i].c_str() ) ;
			_
			fr(i,0,v2.size()) printf("[%s] ", v2[i].c_str() );
			_
		}
		res.clear();
		getPath(mp(0,0));
//		printf("r: %d\n", r);
		
		fr(i,0,res.size()){
			printf("%s", res[i].c_str() ) ;
			if( i != res.size() -1 ) printf(" ");
		}
		_
	}	
	
	
	
	
	return 0;
}



