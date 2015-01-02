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
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


typedef pair<ii, int> iii;
int dist[10][10]; 
int des[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<iii> q;
bool val(int x,int y){
	return (x<0 || x >= 8 || y < 0 || y >= 8) ? 0 : 1;
}

int c, d;
void dkstra(ii ini){
	q = queue<iii>();
	mst(dist, inf);
	int x, y, d , dx, dy;
	iii tr;
	dist[ini.st][ini.nd] = 0;
	q.push(mp(ini,0));
	while(!q.empty()){
		tr = q.front(); q.pop();
		ini = tr.st, d = tr.nd;
		x = ini.st, y = ini.nd;
		if(dist[x][y] != d ) continue;
		for(int i = 0 ; i < 4; i+=2){ // 
			for(int j = 1; j < 4; j+=2){
				dx = x + 2*des[i][0];
				dy = y + des[j][1];
				if(!val(dx,dy)) continue;
				if(dist[dx][dy] > d +1 ) {
					dist[dx][dy] = d+1;
					q.push(mp( mp(dx,dy), dist[dx][dy] ) );
				}
			}
		}
		for(int i = 0 ; i < 4; i+=2){ // 
			for(int j = 1; j < 4; j+=2){
				dx = x + des[i][0];
				dy = y + 2*des[j][1];
				if(!val(dx,dy)) continue;				
				if(dist[dx][dy] > d +1 ) {
					dist[dx][dy] = d+1;
					q.push(mp( mp(dx,dy), dist[dx][dy] ) );
				}
			}
		}			
	}
}



int main (int argc, char const* argv[]) {
	char str[5], str2[5];
	while(scanf("%s %s", str, str2) == 2 ){
		int a = str[0]-'a' , b = str[1]-'0';
		c = str2[0]-'a', d = str2[1]-'0';
		b--, d--;
		if(a==c && b==d ){
			a = 0;
		}
		else {
			dkstra(mp(a,b));
			a = dist[c][d];
		}
		printf("To get from %s to %s takes %d knight moves.\n", str, str2, a);
		
	}
	
	
	
	return 0;
}









