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

int m[100][100];
int n;

void row(int a, int b){
	int aux;
	fr(i,0,n){
		aux = m[a][i];
		m[a][i] = m[b][i];
		m[b][i] = aux;
	}
}

void col(int a, int b){
	int aux;
	fr(i,0,n){
		aux = m[i][a];
		m[i][a] = m[i][b];
		m[i][b] = aux;
	}
}

void in(int k){
	fr(i,0,n){
		fr(j,0,n){
			m[i][j]+=k;
			if(m[i][j] >= 10 ) m[i][j] = 0;
			if(m[i][j] < 0 ) m[i][j] =  9;
		}
	}
}
	
void tra(){
	int mr[50][50];
	fr(i,0,n){
		fr(j,0,n){
			mr[i][j] = m[j][i];
		}
	}	
	fr(i,0,n){
		fr(j,0,n){
			m[i][j] = mr[i][j];
		}
	}
}	
	




int main (int argc, char const* argv[]) {
	int w, k, a, b,d;
	char str[30];
	sc1(w); w++;
	fr(t,1,w){
		sc1(n);
		fr(i,0,n){
			scanf("%s", str);
			fr(j,0,n){
				m[i][j] = str[j]-'0';
			}
		}
		
		sc1(k);
		while(k--){
			scanf("%s", str);
			if(str[0]=='i' || str[0]=='d') {
				d = (str[0]=='i') ? 1:-1;
				in(d);
			}
			else if (str[0]=='r'){
				sc2(a,b); a--; b--;
				row(a,b);
			}
			else if(str[0]=='c'){
				sc2(a,b); a--; b--;
				col(a,b);
			}
			else if (str[0]=='t'){
				tra();
			}	
		}
		
		printf("Case #%d\n", t);
		fr(i,0,n){
			fr(j,0,n){
				printf("%d", m[i][j]);
			}
			_
		}
		_
		
		
	}
	
	
	return 0;
}








