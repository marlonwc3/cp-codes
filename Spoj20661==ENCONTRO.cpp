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



int n, m;
int des[5][2] = {
    {0,0}, {+1, 0}, {-1, 0}, { 0, +1}, {0, -1}
};

bool val(int x, int y){
    return !( x <= 0 || x > m || y <= 0 || y > n );
}



int main (int argc, char const* argv[]) {
    sc2(n,m);
    int a=1, b=1, c=m, d=n, dx1, dx2, dy1, dy2;
    int p, d1, d2;
    sc1(p);
    bool ok = 0;
    
    fe(i,1,p){
        sc2(d1, d2);
        dx1 = a + des[d1][0];
        dy1 = b + des[d1][1];
        
        dx2 = c + des[d2][0];
        dy2 = d + des[d2][1];
        
       // _
       // printf("%d %d %d %d\n", a, b, c, d);
       // printf("%d %d %d %d\n", dx1, dy1, dx2 ,dy2);
        
        
        if( dx1 == dx2 && dy1 == dy2 ){
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", dy1, dx1, i);
            
            ok = 1;
            break;
        }
        else if ( !val(dx1, dy1) ) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", dy1, dx1, i);
            ok = 1;
            break;
        }
        else if ( !val(dx2, dy2) ) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", dy2, dx2, i);
            ok = 1;
            break;
        }
     
        a = dx1, b =dy1;
        c = dx2, d =dy2;
    
    
    }
    
    if(!ok) printf("Nao se encontraram\n");
    
    
    
    
    
    
    
    
    return 0;
}























