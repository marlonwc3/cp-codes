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
#define fe(i,a,b) for(int i=a; i <= b; i++)
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
typedef long double lb;

bool mark[200];
int matrix[200][200];
int res, n, m;

bool bt(int p, int b, int sum){
    //printf("p %d | b %d | sum %d\n", p, b, sum);
    if( p >= n) {
        if( sum < res ) {
            res = sum;
            return 1;
        }
        return 0;
    }
    
    
  //  if( p==1 ) b = b+1;
  //  else if ( p == 2 ) b = b+1;
  //  else if ( p == 3 ) b = b;
  //  else b = b -1;
    
   // printf("b: %d %d\n", b, matrix[p][b]);
    //return bt(p+1, b, sum + matrix[p][b]);
    
    bool ok = 0;
    fe(i,-1,1){
        if( b + i >= 0 && b+i  < m ){
            bt(p+1, b+i, sum + matrix[p][b+i]);
        }
    }

}

int main (int argc, char const* argv[]) {
    sc2(n,m);
    fr(i,0,n){
        fr(j,0,m){
            sc1(matrix[i][j]);
        }
    }
    
   res = inf;
   if(1) fr(i,0,m) { 
       //  mst(mark, 0);
         bt(1,i, matrix[0][i]); 
    }


    
    printf("%d\n", res);
    return 0;
}
