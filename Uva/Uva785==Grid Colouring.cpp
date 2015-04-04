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

char grid[50][100];
bool mark[50][100];
int rowLen[50], n;

bool val(int x,int y){
    if( x < 0 || x >= n) return 0;
    return !(y <0 || y >= rowLen[x] );
}
int des[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
bool cant[500];

bool ff_test(int x,int y, char ch){
    mark[x][y] =1 ;
    int dx, dy;
    fr(i,0,4){
        dx = x + des[i][0], dy = y + des[i][1];
        if(!val(dx,dy)) return 0;
        if(mark[dx][dy]) continue;
        if(cant[grid[dx][dy]]) continue;
        if(grid[dx][dy]!=ch && grid[dx][dy] != ' ' ) return 0;
        if( !ff_test(dx,dy, ch) ) return 0;
    }
    return 1;
}

void ff(int x, int y, char ch){
    grid[x][y] = ch;
    int dx,dy;
    fr(i,0,4){
        dx = x + des[i][0], dy = y + des[i][1];
        if(grid[dx][dy] == ch) continue;
        if(grid[dx][dy] != ' ') continue;
        ff(dx,dy, ch);
    }
}

int main(int argc, char const *argv[]) {

    int len, m, cnt;
    n = 0;
    bool ok, fim = 0; 
    while(!fim){
        n = 0;
        while( 1 ){
            if(! ( gets(grid[n]) )  ){ 
                fim = 1;
                break;
            }
            ok = 1;
            cnt = 0;
            for(int  i = 0; grid[n][i]; i++){
                ok = ok && (grid[n][i]=='_');
                cnt++;
            }    
            rowLen[n] = cnt;
            n++; 
            if(ok) break;  
        }
        mst(cant, 0);
        char ch;
        fr(i,0,n){  
            fr(j,0,rowLen[i]){
                ch = grid[i][j];
                if(ch == ' ') continue;
                if(cant[ch]) continue;
                mst(mark, 0);
                if(!ff_test(i, j, ch ) ) cant[ch] = 1;
                else ff(i,j,ch);
            }
        }
        fr(i,0,n) printf("%s\n", grid[i] );
    }
    fim:;
    return 0;
}