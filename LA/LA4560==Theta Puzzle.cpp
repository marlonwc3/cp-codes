#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <string>
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
#define rp(a,b) fr(a,0,b)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second   
#define EPS 1e-8
#define oi(__) cout << "Oi ["<< __ << "]" << endl
#define clr(a, b) memset(a, b, sizeof(a)) // tati 

using namespace std;
typedef vector<int> vi;
typedef   long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii; // tati
const int INF = 0x3f3f3f3f; // tati
const double PI = acos(-1);



vi e[7];

map<string, pair<string, char > > pai; 


struct State{
	int p, d; 
	string s;
	State(){}
	State(string _s, int _p, int _d ){ s = _s, p = _p; d = _d; }
	State(string _s, int a, int b, int _d){ // na posicao a será o b, a  vira a livre
		s = _s;
		swap(s[a], s[b] ); 
		p = a; 
		d = _d;
	}
	void pf(){ printf("[State | s: %s |  pos: %d \n", s.c_str() ,p );  }
	bool operator <( const State &s ) const { 
		return d > s.d; 
	}
};

map<string, int> mymap;

int go(string str1,string final ) {
	pai.clear(); 	
	mymap.clear();
	pai[str1] = mp("", 'x') ;
	State state = State(str1, 6, 1);
	queue<State> q;
	
	mymap[state.s] = 1; 
	q.push(state); 
	string s , adj;
	State stateAdj;
	int d, p, padj;
	while(!q.empty( ) ) {
		state = q.front(); q.pop();
		s = state.s, p = state.p , d = state.d;
		//state.pf(); 
		if(s == final ) return d; 
		fr(i,0,e[p].size() ) {
			padj = e[p][i]; 
			stateAdj = State(s, padj, p  , d+1); 
			if(mymap[stateAdj.s]) continue;
			mymap[stateAdj.s] = 1 + d; 
			pai[stateAdj.s] = mp(s, stateAdj.s[p] ) ; 
			q.push(stateAdj); 	
			
		}
		
		
		
	}
		
	
	
	return -1; 	
	
}

string path(string s ) {
	if(s.empty() ) return ""; 
	pair<string, char> par = pai[s]; 
	string aux; aux = par.nd; 
	
	aux += path(par.st);
	return aux;
}


char str[10];
const string final = "FABCDE#";
int main (int argc, char const* argv[]){
	e[0].pb(1);
	e[0].pb(5);
	e[1].pb(0); 
	e[1].pb(2);
	e[2].pb(1);
	e[2].pb(6);
	e[2].pb(3);
	e[3].pb(2);
	e[3].pb(4);
	e[4].pb(5);
	e[4].pb(3);
	e[5].pb(4);
	e[5].pb(6);
	e[5].pb(0);
	e[6].pb(5);
	e[6].pb(2);            
	
	
	int caso, x;
	string ini,lol;
	sc1(caso);
	fe(t,1,caso){
		sc1(x);
		ini = "!!!!!!#";
		scanf("%s", str);
		fr(i,0,6){
			ini[(i+1)%6] = str[i]; 
		}
		//printf("INI: %s\n", ini.c_str()  );
		int r = go(ini, final );
		if( r > 0 ) {
			r--;
			lol = path(final);

			printf("%d %d ", t, r, lol.c_str()  );
			for(int i = lol.size() -2 ; i >= 0; i-- ) printf("%c", lol[i] );
			_
		}
		else printf("%d NO SOLUTION\n", t);
//		printf("r: %d\n", r);
	}                                              

	
	
	return 0;
}





























