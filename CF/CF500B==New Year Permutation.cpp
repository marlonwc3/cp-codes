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

vi e[305];
int arr[305];
struct  numero{
	int num;
	numero(){}
	numero(int _num){ num = _num; }
	bool operator < (const numero &n) const{	
		return num > n.num;
	}
};

priority_queue<numero> compo[305];
int cpos[305];
bool mark[305];
void dfs(int no, int c){
	cpos[no]=c;
	compo[c].push(numero(arr[no]) );
	mark[no] = 1;
	int s = e[no].size();
	fr(i,0,s){
		if(!mark[ e[no][i] ]  ){
			dfs(e[no][i], c);
		}
	}
}

int main (int argc, char *argv[]) {
	int n, k, a;
	sc1(n);
	fr(i,0,n) sc1(arr[i]);
	fr(i,0,n){
		fr(j,0,n){
			scanf("%1d", &k);
			if(k){
				e[i].pb(j);
			}
		}
	}
	int c = 0;
	fr(i,0,n){
		if(!mark[i]){
			dfs(i, c);
			c++;
		}
	}
	fr(i,0,n){
		k = cpos[i];
		a = compo[k].top().num;
		compo[k].pop();
		printf("%d", a);
		if(i!=n-1) printf(" ");
	}
	_
	return 0;
}

