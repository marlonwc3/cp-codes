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

int nums[5];

char op[4];

int f(int a, int b, int p){
    char c = op[p];
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
}
bool lol;
bool bt(int p){
    if(p==4){
        int sum = nums[0];

        sum = f(sum, nums[1], 0); 
        sum = f(sum, nums[2], 1); 
        sum = f(sum, nums[3], 2); 
        sum = f(sum, nums[4], 3);   
  
        if(sum==23) return 1;

        return 0;
    }
    
    op[p]='+';
    if( bt(p+1) ) return 1;
    op[p]='*';
    if( bt(p+1) ) return 1;
    op[p]='-';
    if( bt(p+1) ) return 1;    
    return 0; 
}

int main (int argc, char const* argv[]){ 
    lol=1;
    while(1){
        fr(i,0,5) sc1(nums[i]);
        if(!nums[0] &&  !nums[1] && !nums[2] && !nums[3] && !nums[4] ) break;
        
        sort(nums, nums+5);
        bool ok = 0;
        do{
            ok = ok || bt(0);
        //    fr(i,0,5) printf("%d ", nums[i]);
         //   _
        } while( next_permutation(nums, nums+5) );
        if(!ok) printf("Impossible\n");
        else printf("Possible\n");
    }
    
    
    
    return 0;
}








