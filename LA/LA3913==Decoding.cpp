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
int len;
		
string res; 
char matrix[1005][1005];
bool mark[1005][1005];
int N, M;
int cont = 0; 
int go(int a,  int b, int c, int d, int sent){

//	printf("a: %d | b: %d | c: %d | d: %d | sent: %d \n", a,b,c,d,sent);
	mark[a][b] = 1;
	c++;
	d = 2*d + matrix[a][b]-'0'; 
	cont++; 
		
	if( c >= 5 ){
//		printf("c: %d |  d: %d\n", c,d );
		if(cont <= len ) { 
			if(  (d >= 0 && d <= 26) ) { 
				if(!d) res.pb(' ');
				else res.pb(d-1 + 'A' );
			}
		}
		d = 0; 
		c = 0;
	}	

	
	//sent = (sent+1)%4; 
	int novo = (sent+1)%4; 
	
	if(sent == 0 ) { // nort
		if(!mark[a-1][b]) go(a-1, b, c, d, sent);  
		else if (!mark[a][b+1] ) return go(a, b+1, c, d,novo); 		
	}
	else if(sent ==1 ) { // right 
		if( ! mark[a][b+1] ) go(a, b+1, c, d, sent);
		else if (!mark[a+1][b] ) return go(a+1, b, c, d,novo); 	
	}
	else if( sent == 2 ) { // sout
		if(! mark[a+1][b] ) return go(a+1, b, c, d, sent ); 
		else if (!mark[a][b-1] ) return go(a, b-1, c, d,novo); 
	}
	else{ // left
		if(! mark[a][b-1] ) return go(a, b-1, c, d, sent ); 
		else if (!mark[a-1][b] ) return go(a-1, b, c, d,novo); 		
	}
	
	
	
}

void pf(){
	fe(i,0,N+1){
		fe(j,0,M+1) printf("%d ", mark[i][j] );
		_
	}
}

char line[10000];
int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	fe(T,1,caso){
		sc2(N,M);
		scanf("%s", line);	
		cont = 0;
		len = strlen(line); 
		int id = 0; 
		fe(i,1,N){
			fe(j,1,M){
				if( id >= len) matrix[i][j] = '0'; 
				else matrix[i][j] = line[id++]; 
				
				
			}
		}
		
		res = "";
		mst(mark, 0); 
		fe(i,0,M) {
			mark[0][i] = 1;
			mark[N+1][i] = 1;
		}
		fe(i,0,N){
			mark[i][0] = 1;
			mark[i][M+1] = 1;
		}
		mark[N+1][M+1] = 1;
		//pf();
		go(1,1, 0, 0, 1);
		printf("%d ",T) ;
		
		int pos = res.length() ;
		fr(i,0,res.length() ) {
			if(res[i] != ' '){
				pos = i; break;
			}
		}
		int pr = 0;
		for(int i = res.length() -1 ; i >= 0 ; i-- ){
			if( res[i] != ' ') {pr = i; break; }
		}
		
		
		//printf("pos: %d | pos\n", pos );
		fe(i,pos,pr ) printf("%c", res[i] );
		_
	
	
	}
	
	
	
	
	return 0;
}
