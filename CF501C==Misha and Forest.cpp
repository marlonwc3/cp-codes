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

int grau[65546];
int sum[65546] , n;

vii edges;
void go(){
	queue<int> q;
	int no, g, x;
	fr(i,0,n){
		if(grau[i]==1) q.push(i);
	}
	while(!q.empty()){
		no = q.front(); q.pop();
		//printf("no: %d\n", no);
		g = grau[no], x = sum[no];
		if(g!=1) continue;
		grau[no]=0;
		sum[no]=0;
		edges.pb(mp( no, x  ));
		//printf("x: %d | g: %d\n", x, g);
		grau[x]--;


		sum[x]^=no;
		if(grau[x]==1) q.push(x);

	}


}


int main(int argc, char const *argv[]) {
	sc1(n);
	int a, b;
	fr(i,0,n){
		sc2(a,b);
		grau[i]=a;
		sum[i]=b;
	}
	go();
	a = edges.size();
	printf("%d\n", a);
	fr(i,0,a){
		printf("%d %d\n", edges[i].st, edges[i].nd);
	}

	return 0;
}
