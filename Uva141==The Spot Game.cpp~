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

int N;
struct State{
	char grid[55][55];
	string str;
	State(){str= "";}
	State(char _grid[][55]){
		str="";
		string aux;
		fr(i,0,N){
			fr(j,0,N){
				grid[i][j]=_grid[i][j];
				aux = _grid[i][j];
				str += aux;
			}
		}
	}
	void pf(){
		printf("Grid: %s\n", str.c_str() );
	}
	
};



map<string, int> mymap;


char line[100];
int a,b; char ch;

char grid[55][55];
void init(){
	fe(i,0,N) fr(j,0,N){ grid[i][j] = 'x';}
}


void pg(){
	printf("--GRID--\n");
	fr(i,0,N) printf("%s\n", grid[i]);
	
}


int main (int argc, char const* argv[]){
	State state;
	State s, s1, s2, s3, s4;
	int round;
	int p1, p2, p3, p4, perdedor;
	while(1){
		sc1(N); 
		iz(N);
		
		init();
		mymap.clear();
		init();
		state = State(grid);
		s2 = State(grid);
		s3 = State(grid);
		s4 = State(grid);
		gets(line);
		bool win = 0;
		fr(i,0,2*N){
		//	printf("i:%d \n", i);
			//pg();
			gets(line);
			//printf("Line: %s\n", line);
			
			sscanf(line, "%d %d %c", &a, &b, &ch);
			
			
			if(win) continue;
			s1 = State(grid);
			s1.grid[a-1][b-1] = (ch=='+') ? '+' : 'x';
			s1 = State(s1.grid);
			
			//s1.pf();
			
			p1 = mymap[s1.str];
			
			s2 = State(s2.grid); // 180 
			s2.grid[b-1][a-1] = (ch=='+') ? '+' : 'x';
			s2 = State(s2.grid);
			
			p2 = mymap[s2.str];
			
			s3 = State(s3.grid); // +90
//			printf("a: %d | b: %d \n", a, b);
			s3.grid[b-1][(N-1) - (a-1)] =  (ch=='+') ? '+' : 'x';
			s3 = State(s3.grid);						
			
			p3 = mymap[s3.str];
			
			s4= State(s4.grid); // -90
			s4.grid[(N-1) - (b-1)][(a-1)] =  (ch=='+') ? '+' : 'x';
			s4 = State(s4.grid);						
			p4 = mymap[s4.str];
			//p4=0;			
			
			
			
			//printf("p1: %d | p2: %d | p3: %d | p4: %d\n", p1, p2, p3 , p4);
			if(p1){
				perdedor = p1;
				round = i+1;
		//		printf("Venceu p1 -> %s \n", s1.str.c_str());
				win =1;
			}
			else if(p2){
				perdedor = p2;
				round = i+1;
		//	printf("Venceu p2 -> %s \n", s2.str.c_str());
				win =1;
			}
			else if(p3){
				perdedor = p3;
				round = i+1;
//printf("Venceu p3 -> %s \n", s3.str.c_str());
				win =1;
			}
			else if(p4){
				perdedor = p4;
				round = i+1;
//printf("Venceu p4 -> %s \n", s4.str.c_str());
				win =1;
			}		
			mymap[s1.str] = (i%2) ? 1: 2;			
			mymap[s2.str] = (i%2) ? 1: 2;				
			mymap[s3.str] = (i%2) ? 1: 2;
			mymap[s4.str] = (i%2) ? 1: 2;							
			grid[a-1][b-1] = (ch=='+') ? '+' : 'x';
			
		
		
		}
		
		if(!win) printf("Draw\n");
		else {
	//		int venc = (perdedor == 1) ? 2 : 1;
			int venc = perdedor;
			printf("Player %d wins on move %d\n", venc, round);
		}
	
		//break;
	}
	
	
	
	return 0;
}











