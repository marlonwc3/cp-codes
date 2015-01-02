#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
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

vi e[2505];
int nivel[2505], boom, dia;
int niveis[2505];
bool mark[2505];
queue<int> q;
void bfs(int no){
	mst(mark, 0);
	mst(nivel, 0);
	mst(niveis,0);
	boom = -1, dia = -1;
	q = queue<int>();
	int adj, s, niv, nivCnt;
	nivel[no]=1;
	mark[no]=1;
	q.push(no);
	while(!q.empty()){
		no = q.front(); q.pop();
		s = e[no].size();
		niv = nivel[no];	
		//printf("no->%d | niv:%d \n", no, niv);	
		fr(i,0,s){
			adj= e[no][i];
			if(mark[adj])continue;
			mark[adj]=1;
			nivel[adj] = niv+1;
			niveis[niv]++;			
		//	printf("adj: %d niveis[%d]:%d\n", adj, niv, niveis[niv]);
			if(niveis[niv] > boom ){
					boom = niveis[niv];
				//	printf("novo boom :%d | dia %d \n", boom, niv);
					dia = niv;
			}
			q.push(adj);
		}
	}
	

}



int main (int argc, char const* argv[]) { 
	int E, k, num, t;
	sc1(E);
	fr(i,0,E){
		sc1(num);
		//printf("num:%d\n", num);
		fr(j,0,num){
			sc1(k);
			e[i].pb(k);
			//e[k].pb(i);	
		//	printf("(%d,%d) ", i,k);	
		}
	//	_
	}
	
	
	sc1(t);
	fr(i,0,t){
		sc1(k);
		bfs(k);
		if(boom == -1 || dia == -1 ) printf("0\n");
		else printf("%d %d\n", boom, dia);

	}
	
	return 0;
}



















