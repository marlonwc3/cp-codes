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

map<int, ii> mymap;
int main(int argc, char const *argv[]) {
    int cnt =0 ;
    fr(i,0,8){ fr(j,0,8) mymap[cnt++] = mp(i,j); }
    int a ,b, c;
    int xk, yk, xq, yq, xf, yf;
    while( sc3(a,b,c) == 3) {
        xk = mymap[a].st, yk = mymap[a].nd;
        xq = mymap[b].st, yq = mymap[b].nd;
        xf = mymap[c].st, yf = mymap[c].nd;
        if( xq == xk && yq == yk) {
            printf("Illegal state\n");
        }
        else if(  (xq != xf && yq != yf ) || ( xf == xk && yf == yk ) || ( xf == xq && yf == yq )  ) {
            printf("Illegal move\n");
        }
        else if (   (yq == yk && (xq < xk && xf > xk  )) || (  yq == yk && ( xq > xk && xf < xk   )    )   ){
            printf("Illegal move\n");
        }
        else if (   (xq == xk && (yq < yk && yf > yk  )) || (  xq == xk && ( yq > yk && yf < yk   )    )   ){
            printf("Illegal move\n");
        }
        else if( ( xf == xk && ( abs(yf - yk) ==1  ) ) ||  ( (yf == yk) && (  abs(xf - xk) ==1 )     )  )  {
            printf("Move not allowed\n");
        }
        else {
            bool ok = 1;
            if(xk == 0 && yk == 0 ){
                if(xf ==1 && yf ==1 ) ok = 0;
            }
            else if (xk == 7 && yk == 0){
                if(xf == 6 && yf == 1) ok = 0;
            }
            else if (xk == 0 && yk == 7){
                if( xf == 1 && yf == 6 ) ok = 0;
            }
            else if (xk == 7 && yk == 7){
                if(xf == 6 && yf == 6) ok =0;
            }
            if(ok) printf("Continue\n");
            else printf("Stop\n");
        }
    }






    return 0;
}