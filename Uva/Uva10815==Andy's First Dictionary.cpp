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

vector<string> vs;
string line;

set<string> ss;

int main (int argc, char const* argv[]) {
    int len;
    char *pch;
    
    char str[10005];
    
    while(scanf("%s", str) != EOF) {
        scanf("\n");
        len = strlen(str);
        if(!len) continue;
        fr(i,0,len){
            str[i] = tolower(str[i]);
            if(str[i] < 'a' || str[i] >'z') str[i] = 32;
        }
        
        pch = strtok(str, " ");
       while (pch != NULL)
        {
            if(strlen(pch) != 0)ss.insert(pch);
            pch = strtok (NULL, " ");
       }
    
    }    
    
    set<string>::iterator it;
    for( it = ss.begin(); it != ss.end(); it++){
        printf("%s\n", (*it).c_str() );
    }
    
    
    
    return 0;
}

