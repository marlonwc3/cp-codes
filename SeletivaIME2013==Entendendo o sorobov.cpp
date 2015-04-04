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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
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

ll n;
int matrix[12][12];
string line;

int main (int argc, char const* argv[]){
	int r;
	while ( getline(cin,line)  ){
		
		int d = 8;
		
		fe(i,0,10){
			fe(j,0,10) matrix[i][j] = 0;
		}

		
		for(int l = line.length() -1; l >= 0; l --) {
			r = line[l]-'0';
			
			if(r == 0 ){
				matrix[d][0] = 1;
				fe(i,4,7) matrix[d][i] = 1;
				n/=10;
				d--;				
				continue;
			}
			
			
			matrix[d][0] = 1;
			matrix[d][1] = 0;
			if( r >= 5 ){
				matrix[d][1] = 1;
				matrix[d][0] = 0;				
				r-=5;
			}
			int p = 3;
			int cnt = 0;
			while(r) {
				matrix[d][p]=1;
				p++;
				r--;
				cnt++;
			}
			
			for(int i = 8; cnt <= 4; cnt++, i--){
				matrix[d][i]=1;
			
			}
			
			
			n/=10;
			d--;
		}
		
		while( d >= 0){
				matrix[d][0] = 1;
				fe(i,4,7) matrix[d][i] = 1;
				n/=10;
				d--;						
		}
		
		fe(i,0,1){
			fe(d,0,8){
			
				printf("%d", matrix[d][i]);
			}
			_
		}
		fe(i,0,8) printf("-");
		_
		fe(i,3,7){
			fe(d,0,8){
				printf("%d", matrix[d][i]);
			}
			_
		}		
		_
	}
	
	
	return 0;
}





