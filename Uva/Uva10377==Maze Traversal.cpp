#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii; 
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;

string matrix[70];
int n,m;
int des[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

bool val(int x, int y){
	if( x < 0 || x >= n ||y <0 || y>=m ) return 0;
	if (matrix[x][y] == '*') return 0;
	return 1;
}

int main (int argc, char const* argv[]) {
	int t;
	char ch;
	int px, py, r, dx,dy;
	char s[100];
	bool f = 1;
	sc1(t);
	while(t--){
		if(!f) _
		sc2(n,m); getline(cin, matrix[0]); 
		fr(i,0,n){
			getline(cin, matrix[i]);
		}
		sc2(px, py); 
		px--; py--;
		r = 0; 

		while(1) {
			scanf("%s", s); 
			int len = strlen(s);
			fr(i,0,len){
			//	if(s[i]!=32) printf("Lido %c rot %d  px,py: %d %d\n", s[i], r, px, py);
				if(s[i]=='R'){
			//		printf("rantg -> %d ", r);				
					r++; r%=4;
				//	printf("r -> %d ", r); _
				}
				else if (s[i]=='L'){
					r--; if(r<0) r= 3;
				}
				else if (s[i]=='F') {
				//	printf("px py %d %d --> ", px, py	);
					dx = px + des[r][0];
					dy = py + des[r][1];
					if(val(dx, dy ) ) {
						matrix[px][py]=' ';	
						px = dx, py =dy;
				//	printf("%d %d --> ", px, py);				_		 
					} 
				//	else printf("invalid!\n");
					
					
				}
				else if(s[i]=='Q'){
					goto fim;
				}
				matrix[px][py]= 'X';
		/*		
				fr(i,0,n){
					fr(j,0,m){
						printf("%c", matrix[i][j]);
					}_	
				}
			*/	
				
			}
		
		}

		fim:;
		if(r==0) ch='N';
		if(r==1) ch= 'E';
		if(r==2) ch='S';
		if (r==3) ch='W';
		
		printf("%d %d %c\n", px+1, py+1, ch);
		f=0;
		
		
	
	}
	
	
	
	
	return 0;
}






