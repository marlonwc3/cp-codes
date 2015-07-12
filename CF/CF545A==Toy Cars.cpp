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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int mat[200][200];


int main (int argc, char *argv[]){
	int n;
	sc1(n);
	set<int> bons;
	fr(i,0,n){
		bons.insert(i);
		fr(j,0,n) {
			sc1(mat[i][j]);
			if(mat[i][j]== -1) continue;
			if(mat[i][j] == 1) bons.erase(i);
			if(mat[i][j]==2) bons.erase(j);
			if(mat[i][j] == 3){bons.erase(i); bons.erase(j);}
		}
	}
	int s = bons.size();
	printf("%d\n", s);
	if(s){
	set<int>::iterator it = bons.begin();
	printf("%d", (*it)+1);
	it++;
	for(; it!=bons.end(); it++) printf(" %d", (*it)+1);
	_
}
	
	
	
	
	return 0;
}


