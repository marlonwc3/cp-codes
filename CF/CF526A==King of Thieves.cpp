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


char str[1000];
int n;
int tenta(int k,int ini){
	int x = ini;
	if(x >= n || str[x] != '*') return 0;
	int cnt = 0;
	while( x < n && str[x] == '*'){
		x += k;
		if(x < n && str[x] =='*'){
			cnt++;
		}
	}
	
	return cnt >= 4;
}




int main (int argc, char *argv[]) {
	sc1(n);
	scanf("%s", str);
	n = strlen(str);
	
	bool ok = 0;
	fr(i,0,n){
		fr(j,1,n+2){
			if(tenta(j, i) ){
				//printf("i: %d | j : %d\n", i, j);
				ok=1;break;
			}
			
		}
		if(ok) break;
	}
	
	if(ok) printf("yes\n");
	else printf("no\n");
	
	return 0;
}

