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
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

int freq[350];


char str[2*100005 ];
int main (int argc, char const* argv[]) {
    int n;
    sc1(n);
    scanf("%s", str);
//    fe(i,0,2*n - 2){
      //  if(i%2 == 0) freq[str[i]]++;
//    }
  //  fe(i,'a','z') printf("%d ", freq[i]);
  //  _
    int res = 0;
    for(int i =0; i < 2*n -2; i+=2){
        if(i+1 >=  2*n -2 ) break;
        if(str[i] == tolower(str[i+1]) ) continue;
   //     printf("i: %c | i+1: %c\n", str[i], str[i+1] );
        if(freq[tolower(str[i+1])]  ) {
            freq[tolower(str[i+1])]--;
            freq[str[i]]++;
        }
        else{
            res++;
            freq[str[i]]++;
        }
        
    }
    printf("%d\n", res);
    
    return 0;
}



