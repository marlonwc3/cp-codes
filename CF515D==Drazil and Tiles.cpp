By mras, contest: Codeforces Round #292 (Div. 2), problem: (D) Drazil and Tiles, Accepted, #
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

char grid[2015][2015];
char grau[2015][2015];
int des[4][2] = {
	{1,0},{-1,0}, {0,1},{0,-1}
};
int n,m;
bool val(int x, int y){ return !(x < 0 || x >=n || y < 0 || y>=m); }

typedef pair<char,char> pc;

pc get(int k){
	if(k==0) return mp('^', 'v');
	if(k==1) return mp('v', '^');
	if(k==2) return mp('<', '>');
	if(k==3) return mp('>', '<');
}

int cfind;
ii find(int x, int y){
	int dx,dy;
	fr(i,0,4){
		dx = x + des[i][0], dy = y + des[i][1];
		if(!val(dx, dy) || grid[dx][dy] != '.') continue;
		cfind=i;
		return mp(dx,dy);
	}
}



int main (int argc, char const* argv[]) {

	sc2(n,m);

	fr(i,0,n){
		scanf("%s", grid[i] );
	}
	
	queue<ii> q;
	int dx , dy, cnt;
	fr(i,0,n){
		fr(j,0,m){
			if(grid[i][j] != '.' ) continue;
			cnt = 0;
			fr(l,0,4){
				dx = i + des[l][0], dy = j + des[l][1];
				if(!val(dx,dy) || grid[dx][dy] != '.') continue;
				cnt++; 
			}
			grau[i][j] = cnt;
			if(cnt==1){
				q.push(mp(i,j));	
				grau[i][j]=0;
			}			
		}
	}
	ii par;
	int x , y, k, px , py;
	pc parc;
	bool ok = 1;
	while(!q.empty()){
		par = q.front(); q.pop();
		x = par.st, y = par.nd;
		if(grid[x][y] != '.')continue;
		par = find(x,y);
		px = par.st, py = par.nd;
		if(grid[px][py] != '.') { ok =0; break; }
		k = cfind;
		parc = get(k);
		grid[x][y] = parc.st, grid[px][py] = parc.nd;
		grau[px][py]=0;
		fr(l,0,4){
			dx = px +des[l][0], dy = py + des[l][1];
			if(!val(dx,dy) || grid[dx][dy] != '.') continue;
			grau[dx][dy]--;
			if(grau[dx][dy] ==1 ) {
				q.push(mp(dx,dy));
			}
		}
	}
	




	//printf("total %d | st %d\n", total, stotal);

	fr(i,0,n){
		fr(j,0,m) ok =ok && !(grid[i][j]=='.');
	}

	if(!ok) printf("Not unique\n");
	else {
		fr(i,0,n) printf("%s\n", grid[i]);

	}
	
	
	
	
	
	
	return 0;
}
