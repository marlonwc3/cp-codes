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


char grid[150][150], grid2[150][150];
int n, m, k;
int des[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool val(int x,int y){ return !(x < 0 || x >= n || y < 0 || y >= m);}
/*
Rocks always defeat Scissors,
 Scissors always defeat Papers, 
 and Papers always defeat Rocks.
*/
bool win(char c1, char c2){
    if( c1 == 'R' && c2 == 'S') return 1;
    if( c1 == 'S' && c2 == 'P' ) return 1;
    if( c1 == 'P' && c2 =='R') return 1;
    return 0;
}

int main(int argc, char const *argv[]) {
    int t , dx ,dy;
    sc1(t);
    bool first = 1;
    while(t--){
        if(!first) _
        sc3(n, m, k);
        fr(i,0,n){
            scanf("%s", grid[i]);
        }
        while(k--){
            memcpy(grid2, grid, sizeof grid);
            fr(i,0,n){
                fr(j,0,m){
                    fr(d,0,4){
                        dx = i + des[d][0], dy = j + des[d][1];
                        if(!val(dx,dy))continue;
                        if(win(grid2[i][j], grid2[dx][dy])){
                            grid[dx][dy] = grid2[i][j];
                        }
                    }
                }
            }

        }
        fr(i,0,n){
            printf("%s\n", grid[i]);
        }
        first = 0;
    }
    return 0;
}