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


ll dg[5];
ll row[3000], col[3000];
bool mark[1000005];



int main (int argc, char const* argv[]){
    ll n;
    ll k;
    scanf("%lld", &n);     
    bool ok = 1; 
    fr(i,0,n){
        fr(j,0,n){
            scanf("%lld", &k);      
            if( k <= 0 || k > n*n )  ok = 0;
            else if( mark[k]) ok = 0;
            else{ mark[k]=1; }
            
            row[i]+=k;
            col[j]+=k;
            if(i==j) dg[0]+=k;
            if( (i+j)==(n-1) ){
                dg[1]+=k;
            } 
        }
    }
    ll sum = dg[0];
    if( sum != dg[1] ) ok = 0;
    
    fr(i,0,n){
        
        if( sum != row[i] ) ok = 0;
        if( sum != col[i] ) ok = 0;
    }
    if(ok) {
        printf("%lld\n", sum);
    }
    else printf("0\n");
    
    
    
    return 0;
}













