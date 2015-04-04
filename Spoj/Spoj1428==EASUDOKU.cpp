
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
bool cmp(int a, int b) { return a>b;}


int matrix[10][10], mres[10][10];
bool row[10][10], col[10][10], sqr[3][3][10];

bool foo(int r, int c){
	if( c>=9 ) {
		c=0;
		r++;
	}
	if(  r>=9 ) return 1;
	
	if( matrix[r][c] ) {
		mres[r][c] = matrix[r][c];
	 	return foo(r, c+1);
	 }

	int a, b;
	if ( r<=2 ) a = 0;
	else if ( r <= 5 ) a =1;
	else if (r <= 8) a =2;
	
	if( c <= 2 ) b =0;
	else if ( c<=5 ) b = 1;
	else if ( c <= 8 ) b = 2;
	fr(i,1,10){
		if( row[r][i] ) continue;
		if (col[c][i] ) continue;
		if ( sqr[a][b][i] ) continue;
		row[r][i] = col[c][i] = sqr[a][b][i] = 1;
		if ( foo(r, c+1 )  )  {
			mres[r][c] = i;	
			return 1;
		}
		row[r][i] = col[c][i] = sqr[a][b][i] = 0;
	}
	
	return 0;
	
}

int main (int argc, char const* argv[]) { 
	int t , k;
	sc1(t);
	while(t--){
		mst(row, 0);	
		mst(col,0);
		mst(mres,0);
		mst(sqr, 0);
		fr(i,0,9){
			fr(j,0,9){
				sc1(k);
				matrix[i][j]=k;
				if(k){
					mres[i][j] = k;
					int a, b;
					if (i<=2 ) a = 0;
					else if ( i <= 5 ) a =1;
					else if (i <= 8) a =2;
					if( j <= 2 ) b =0;
					else if ( j<=5 ) b = 1;
					else if ( j <= 8 ) b = 2;		
					row[i][k] = 1;
					col[j][k] = 1;
					sqr[a][b][k] = 1;
				}
				
			}
		}
		
		if(foo(0,0)) {
			fr(i,0,9){
				fr(j,0,9){
					printf("%d", mres[i][j]);
					if( j!=8) printf(" ");
				}
				_
			}
		
		}
		else {
			printf("No solution\n");
		}
		
		
	}
	
	
	
	
	return 0;
}






























