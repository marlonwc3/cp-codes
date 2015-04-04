#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
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


int des[4][2] ={
    {0,1}, {0,-1}, {1,0}, {-1,0}
};

int r, c, n;
bool validate(int x, int y){
    if( x < 0 || x >= r || y < 0 || y >= c) return 0;
    return 1;
}


int m[105][105];

int aux[105][105];

int riv;

void battle(){
    int dx, dy, val;
   fr(i,0,r){
    fr(j,0,c){
        aux[i][j] = m[i][j];
    }
   }
    int adj, dif;
   fr(i,0,r){
    fr(j,0,c){
        val =m[i][j];
        
        fr(k,0,4){
            dx = i + des[k][0];
            dy = j + des[k][1];
            
            if(validate(dx,dy) == 0) continue;
            adj = m[dx][dy];
            if(val <=  riv ){
                
                dif = adj-val;
                if( val == n-1 && adj == 0) goto label;
                if( dif != 1)  continue;
                
                label:;
                aux[dx][dy] = val;
                
            }
            
        }
        
    }
   }   
   
   fr(i,0,r){
    fr(j,0,c){
        m[i][j] = aux[i][j];
    }
   }   


}


int main (int argc, char const* argv[])
{
    int k, val;
   
    while(1){
        sc4(n, r, c, k);
        if(!n && !r && !c && !k) break;
        riv = n;
        fr(i,0,r){
            fr(j,0,c){
                sc1(val);
                m[i][j] = val;
            }
        }  
   
        
        while(k--){
            battle();
        }
        
        fr(i,0,r){
            fr(j,0,c){
                printf("%d", m[i][j]);
                if(j!=c-1) printf(" ");
            }
            _
        }
 
       
    }
    
    return 0;
}

