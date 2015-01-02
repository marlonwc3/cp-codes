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

vi v;
int n, m; // m vacas
bool ok(int val){
  // printf("val: %d\n", val);
    int cnt = 1 ;
    int p = v[0];
    int i = 1;
    while(  i < n ) {
     //   printf("p: %d  i : %d  v[i]: %d | sub %d \n", p, i , v[i] , v[i] - p);
        if ( v[i] - p  >= val) {
        
            cnt++;
           // printf("entrou!\n");
            p = v[i];
            i++;
            
        }     
        else i++;
    }
    return cnt >= m;

}


int bs(int hi, int lo){
  //  printf("hi %d lo %d\n", hi, lo);
    if( lo+1 >= hi ) return -1;
    int mid = (hi+lo)/2;
    
    if( ok(mid )) {
        return max(mid, bs(hi, mid));
    }
    return bs(mid, lo);
    
    
}



int main (int argc, char const* argv[]) {
    
    int t, k;
    sc1(t);
    while(t--){
        v.clear();
        sc2(n,m);
        fr(i,0,n){
            sc1(k);
            v.pb(k);
        }
    
        sort(v.begin(), v.end());
        int hi = v[n-1] - v[0];
        hi++;
        
        int r =  bs(hi, -1);
        printf("%d\n", r);
        
        
        
          
       // break;
    }
    
    
    return 0;
}
