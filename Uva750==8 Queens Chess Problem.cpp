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


int linhas[10], teste, a, b, contador;

bool place(int col, int tentar){
    for(int prev = 1; prev < col; prev++){
        if(linhas[prev]==tentar || abs(linhas[prev] - tentar) == abs(prev-col) ){
        return 0; 
        }
    }
    return 1;
}


void bt(int col){
    for(int tentar =1 ; tentar <= 8; tentar++){
        if(place(col, tentar)){
            linhas[col] = tentar;
            if(col==8 && linhas[b] ==a ) {
                printf("%2d      %d", ++contador, linhas[1]);
                for(int j=2; j<=8; j++){
                    printf(" %d", linhas[j]);
                
                }
                printf("\n");
            }
            else bt(col+1);
        }
    }
}

int main (int argc, char const* argv[]) {
    
    sc1(teste);
    while(teste--){
        sc2(a,b);
        mst(linhas,0); contador = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        bt(1);
        if(teste) printf("\n");
    
    }
    
    
    return 0;
}

