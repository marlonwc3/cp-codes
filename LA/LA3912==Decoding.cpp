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
char boy[10000];
bool mark[1005][1005];
int N, M;
int cont = 0; 
int go(int a,  int b, int p, int sent){

//	printf("a: %d | b: %d | c: %d | d: %d | sent: %d \n", a,b,c,d,sent);
	mark[a][b] = 1;
	if(p < len ) matrix[a][b] = boy[p];
	else matrix[a][b] = '0'; 


	
	//sent = (sent+1)%4; 
	int novo = (sent+1)%4; 
	p++; // ICNREMENTA P @@@@@@@@@@@22
	if(sent == 0 ) { // nort
		if(!mark[a-1][b]) go(a-1, b, p, sent);  
		else if (!mark[a][b+1] ) return go(a, b+1, p,novo); 		
	}
	else if(sent ==1 ) { // right 
		if( ! mark[a][b+1] ) go(a, b+1,p, sent);
		else if (!mark[a+1][b] ) return go(a+1, b,p,novo); 	
	}
	else if( sent == 2 ) { // sout
		if(! mark[a+1][b] ) return go(a+1, b,p, sent ); 
		else if (!mark[a][b-1] ) return go(a, b-1, p,novo); 
	}
	else{ // left
		if(! mark[a][b-1] ) return go(a, b-1, p, sent ); 
		else if (!mark[a-1][b] ) return go(a-1, b, p,novo); 		
	}
	
	
	
}

void pf(){
	fe(i,0,N+1){
		fe(j,0,M+1) printf("%d ", mark[i][j] );
		_
	}
}
string bres; 
int toBin(int n){
	bres = !n ? "0" : "";
	while(n){
		bres.pb((n%2) + '0'); 
		n/=2;
	}
	while(bres.length() < 5 ) bres.pb('0');
	reverse(bres.begin(), bres.end());
}



string line;
int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	char ch;
	fe(T,1,caso){
		scanf("%d %d", &N, &M);
		//getline(cin, line);
		getline(cin, line);
		
		//printf("lido: %d %d%s\n", N, M, line.c_str()   );
		//len = strlen(line); 
		len = line.length(); 
		int p = 0;
		int len2 = 0;
		fr(i,1,len){
			int k = (line[i] == ' ') ? 0 : (line[i] - 'A' +1 ) ;
		//	printf("line[i]: %c | k: %d\n", line[i], k );
			toBin(k);
		//	printf("bres: %s\n", bres.c_str() ); 
			fr(j,0,5){
				boy[p++] = bres[j]; 
				len2++;
			}
		}
		len = len2;
		//printf("boy: %s \n", boy ); 
	//	00001 00011 01101
	//	00001 10100 101100
		
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
		go(1,1, 0, 1);
		printf("%d ",T) ;
		fe(i,1,N) fe(j,1,M){
			printf("%c", matrix[i][j]);
		}
		_
		
	//	01000 00000 0 00010000000010
	//	01000 01000 0 11010110000010
		
		
	
	}
	
	
	
	
	return 0;
}
