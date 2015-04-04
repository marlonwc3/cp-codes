	#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
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

vi e[105];
char str[1000];

bool mark[100];
int cnt;
void dfs(int no){
	mark[no]=1;
	cnt++;
	int s = e[no].size();
	fr(i,0,s){
		if(mark[e[no][i]]) continue;
		dfs(e[no][i]);
	}
	
}


int main (int argc, char const* argv[]) {
	int t; sc1(t);
	char a , b;
	vector<int> vc;
	while(t--){
		fr(i,0,100) e[i].clear();
		vc.clear();
		while(1){
			scanf("%s", str);
			if(str[0]=='*') break;
			sscanf(str, "(%c,%c)", &a, &b);
			e[a-'A'].pb(b-'A');
			e[b-'A'].pb(a-'A');
		}
		scanf("%s", str);
		for(int  i=0 ; str[i]; i++){
			if(str[i] < 'A' || str[i] > 'Z' ) continue;
			vc.pb(str[i]-'A');
		}
		
		mst(mark, 0);
		int c1=0, c2 =0;
		fr(i,0,vc.size()){
			a = vc[i];
			if(!mark[a]){
				cnt = 0;
				dfs(a);
				c2 += cnt==1;
				c1 += cnt!=1;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", c1, c2);
		
		
		
		
	}
		
	
	
	return 0;
}




 




