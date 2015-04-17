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

#define MAX_S 405
struct node {
    int adj[5];
    int& operator [] (int i) {return adj[i];}
} tree[ MAX_S];

char word[30];// Palavra Alvo
void init(int no) { fr(i,0,5) tree[no][i] = -1; }
int cnt, LEN, N;
void addWord() {
    int at = 0,last = 0;
    for (int i = 0; i < LEN; ++i) {
        int to = word[i] - '0';     
        if (tree[at][to] == -1) {
            tree[at][to] = ++cnt;
            init(cnt);
        }
        if(i==LEN-1) last = at;
        at = tree[at][to];
    }
    if(word[LEN-1] == '0' ) tree[last][2] = 0;
    else tree[last][3] = 0;
}

struct State{
	string str;
	int x, y, b, tam;
	State(){}
	State(int _x, int _y, int _b, int _tam) { 
		x=_x, y=_y, b=_b, tam=_tam;
		str = "";
	}
	State(int _x, int _y, int _b, int _tam, State s, char c) { 
		x=_x, y=_y, b=_b, tam=_tam;
		string aux; aux =c;
		str = s.str + aux;
	}	
	bool operator < ( const State &s ) const {
		if( str.length()  != s.str.length()  ) return str.length() > s.str.length();
		return str > s.str;
		
	}
};

int get(int k){
	if(k==0 || k== 2 ) return '0';
	return '1';
}
const int PSTR = 1;	
inline bool val(int x, int y) { return x >= 0 && y >=0 ;}

int pd_ok[ MAX_S][ MAX_S][5], PASSO;
State pai[ MAX_S][ MAX_S][5];
string str;
int go(){
	priority_queue<State> q;
	State state;
	int x, y, b, tam, dx ,dy;
	mst(pd_ok, inf);
	pd_ok[0][0][0] = 0;
	pai[0][0][0] = State(-1,-1,-1,-1);
	q.push(State(0,0,0,0));
	while(!q.empty()){
		state = q.top();
		q.pop();
		x = state.x, y=state.y, b=state.b, tam=state.tam;
		if(tam != pd_ok[x][y][b]) continue;
		if(!x && !y && b) {
			str = state.str;
			break;
		}
		dx = tree[x][0], dy = tree[y][0];
		if(val(dx,dy) && pd_ok[dx][dy][b] >= tam+1 ){
			pai[dx][dy][b] = State(x, y, b, 0);
			pd_ok[dx][dy][b] = tam+1;
			if(PSTR) q.push(State(dx, dy, b, tam+1, state, get(0) ));
		}
		dx = tree[x][0], dy = tree[y][2];
		if(val(dx,dy) && pd_ok[dx][dy][1] >= tam+1 ){		
			pai[dx][dy][1] = State(x, y, b, 0);
			pd_ok[dx][dy][1] = tam+1;
			if(PSTR) q.push(State(dx, dy, 1, tam+1, state, get(0)));				
		}		
		dx = tree[x][2], dy = tree[y][0];
		if(val(dx,dy) && pd_ok[dx][dy][1] >= tam+1 ){		
			pai[dx][dy][1] = State(x, y, b, 0);
			pd_ok[dx][dy][1] = tam+1;
			if(PSTR) q.push(State(dx, dy, 1, tam+1, state, get(0)));
		}		
		dx = tree[x][2], dy = tree[y][2];
		if(val(dx,dy) && pd_ok[dx][dy][b] >= tam+1 ){		
			pai[dx][dy][b] = State(x, y, b, 0);
			pd_ok[dx][dy][b] = tam+1;
			if(PSTR) q.push(State(dx, dy, b, tam+1, state, get(0)));
		}		
		
		dx = tree[x][1], dy = tree[y][1];
		if(val(dx,dy) && pd_ok[dx][dy][b] >= tam+1 ){		
			pai[dx][dy][b] = State(x, y, b, 1);
			pd_ok[dx][dy][b] = tam+1;
			if(PSTR) q.push(State(dx, dy, b, tam+1, state, get(1)));
		}
		dx = tree[x][1], dy = tree[y][3];
		if(val(dx,dy) && pd_ok[dx][dy][1] >= tam+1 ){		
			pai[dx][dy][1] = State(x, y, b, 1);
			pd_ok[dx][dy][1] = tam+1;
		 	if(PSTR) q.push(State(dx, dy, 1, tam+1, state, get(1))); 			
		}
		dx = tree[x][3], dy = tree[y][1];
		if(val(dx,dy) && pd_ok[dx][dy][1] >= tam+1 ){		
			pai[dx][dy][1] = State(x, y, b, 1);
			pd_ok[dx][dy][1] = tam+1;
			if(PSTR) q.push(State(dx, dy, 1, tam+1, state, get(1)));
		}
		
		dx = tree[x][3], dy = tree[y][3];
		if(val(dx,dy) && pd_ok[dx][dy][b] >= tam+1 ){		
			pai[dx][dy][b] = State(x, y, b, 1);
			pd_ok[dx][dy][b] = tam+1;
			if(PSTR) q.push(State(dx, dy, b, tam+1, state, get(1)));										 		 		 
		}
	}
}


string getPath(State state){
	if(state.x == -1 && state.y == -1) return "";
	string aux, r; aux = get( state.tam);
	r = getPath(pai[state.x][state.y][state.b]);
	return r + aux;
}


string todas[30];
int main (int argc, char const* argv[]){
	int t = 0;
	while(1){
		sc1(N); iz(N);
		str = ""; fr(i,0, MAX_S) str += "2";
		t++;
		fr(i,0, MAX_S) init(i);
		init(cnt = 0);
		fr(i,0,N){
			scanf("%s", word);
			LEN = strlen(word);
			addWord();
			todas[i] = word;
		}
		go();
		fr(i,0,N){
			fr(j,i+1,N){
				if(todas[i]!=todas[j]) continue;
				if(todas[i].length() < str.length() ) { str = todas[i] ;  break;}
				else if( todas[i].length() == str.length() && (todas[i] < str ) ){
					str = todas[i]; break;
				}
			}
		}
		LEN = str.length();
		int i =0;
		printf("Code %d: %d bits\n", t, LEN);
		while ( i < LEN ) {
			for(int j =0 ; j < 20 && i < LEN; j++, i++) printf("%c", str[i] );
			_
		}

		_
	}
	
	
	
	return 0;
}


