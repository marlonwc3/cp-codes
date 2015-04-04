#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
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

int matrix[10][10], mres[10][10];
int col[10][10], row[10][10], sqr[4][4][10], n;

void pm(){		
	fr(i,0,n) {
		fr(j,0,n){
			printf("%d", mres[i][j]);
			if(j!=n-1) printf(" ");
		}
		_
	}
}

bool bt(int r, int c){
	//printf("Call r,c -> %d %d\n", r, c);
	if(r==n){
		r = 0;
		c++;
		if(c==n){
			return 1;
		}
		return bt(r, c);
	}
	
	if(matrix[r][c]) return bt(r+1,c);
	
	int sx, sy;
	if(n==1 ) sx = 0;
	else if ( n==4 ) {
		sx = (r <= 1) ? 0 : 1;
	}
	else if(r<=2) sx = 0;
	else if ( r <= 5 ) sx = 1;
	else if ( r<= 8 ) sx = 2;

	if (n==1) sy = 0;
	else if( n==4 ) {
		sy = (c <= 1) ? 0 : 1;
	}
	else if( c <= 2) sy= 0;
	else if (c <= 5 ) sy = 1;
	else if( c<=8)  sy =2;
	
	fr(i,1,n+1){
	//	printf("colocando i:%d\n", i);

		if(row[r][i]) {
		//	printf("falhou linha\n");
			continue;
		}

		if(col[c][i]) {
		//	printf("falhou coluna\n");
			continue;
		}
		
		if(sqr[sx][sy][i]){
			//printf("falhou sqr (%d | %d -> %d) \n", sx, sy, sqr[sx][sy][i]);
		 	continue;
		 }
		row[r][i]=col[c][i]=sqr[sx][sy][i] = 1;
		 mres[r][c]=i;		
		// printf("conseguiu %d | sx:%d , sy: %d !\n", i, sx, sy);
		//printf("@@ print %d %d para i: %d\n", r, c, i);
		//pm();

		if(bt(r+1, c) ) return 1;
		row[r][i]=col[c][i]=sqr[sx][sy][i] = 0;		
	}
	

	return 0;
}

int main (int argc, char const* argv[]) {
	int k, sx, sy;
	bool first = 1;
	while(sc1(n)==1){
		if(!first) {
			_
		}
	
		bool ok = 1;
		n*=n;
		mst(mres, 0);
		mst(row, 0);
		mst(col, 0);
		mst(sqr, 0);
		fr(r,0,n){
			fr(c,0,n){
				sc1(k);	
				matrix[r][c] =k;
				if(k){
				
					if(n==1 ) sx = 0;
					else if ( n==4 ) {
						sx = (r <= 1) ? 0 : 1;
					}
					else if(r<=2) sx = 0;
					else if ( r <= 5 ) sx = 1;
					else sx = 2;

					if (n==1) sy = 0;
					else if( n==4 ) {
						sy = (c <= 1) ? 0 : 1;
					}
					else if( c <= 2) sy= 0;
					else if (c <= 5 ) sy = 1;
					else sy =2;			
					
					if(row[r][k] || col[c][k] || sqr[sx][sy][k] || k <= 0 || k>n ) ok = 0;
						
					mres[r][c] =k;
					row[r][k]=col[c][k]=sqr[sx][sy][k] = 1;
				}
						
			}
		}

		
						
		if( ok && bt(0,0) ) { 		
			pm();
		}
		else printf("NO SOLUTION\n");
		
		
		first = 0;

	}
	
	return 0;
}











