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


int freq[2*100005];


char str[2*100005];
int main (int argc, char const* argv[]) {
    scanf("%s", str);
    int len = strlen(str);
    int m,k;
    sc1(m);
    while(m--){
        sc1(k);
        freq[k] += 1;
        freq[len - k + 1 + 1] += -1;
    }
    fe(i,1,len) {
        freq[i]+=freq[i-1];
    }
  // fr(i,1,len) printf("%d ", freq[i] );
  //  _
    fe(i,1,len){
        if(freq[i] % 2 == 0) printf("%c" , str[i-1]);
        else {
            int p = len - i  +1;
            printf("%c", str[p-1] );
            
        }
    }
    _
    
    return 0;
}


