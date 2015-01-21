#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define nd second
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
 
int grid[120][120];
int n;
int des[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
bool val(int x,int y){ return !(x < 0 || x>= n || y < 0 || y >= n );}
 
int cnt;
void ff(int x, int y, int id){
        grid[x][y] = -1;
        int dx,dy;
        cnt++;
        fr(i,0,4){
                dx = x + des[i][0]; dy = y + des[i][1];
                if(!val(dx,dy)) continue;
                if(grid[dx][dy] != id) continue;
                ff(dx,dy,id);
        }
}
 
 
char line[20000];
int main(int argc, char const *argv[]) {
        int x,y;
        while(1){
                sc1(n); iz(n);
                getchar();
                mst(grid, 0);
                int k = 0;
                fr(i,1,n){
                        gets(line);
                        char *pch = strtok(line, " ");
                        while( pch != NULL ) {
                                if(!k) sscanf(pch, "%d", &x);
                                else {
                                        sscanf(pch, "%d", &y);
                                        x--, y--;
                                        grid[x][y] = i;
                                }
                                k = !k;
                                pch = strtok(NULL, " ");
                        }
                }
                int sum = 0;
                bool ok = 1;
                fr(i,0,n){
                        fr(j,0,n){
                                if(grid[i][j]!=-1) {
                                        sum++;
                                        cnt = 0;
                                        ff(i,j,grid[i][j]);
                                        ok = ok && (cnt == n);
                                }
                        }
                }
                ok = ok && (sum==n);
                if(ok)printf("good\n");
                else printf("wrong\n");
 
        }
 
        return 0;
}
