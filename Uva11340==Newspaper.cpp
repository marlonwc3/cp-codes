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

map<char, int> my;

int main (int argc, char const* argv[]) {    
    int t, k, n, len;
    sc1(t);
    string line;
    while(t--){
        sc1(k);
        my.clear();
        char c;
        int val;
        while(k--){
            scanf(" %c %d", &c, &val);
            my[c]=val;
        }
        sc1(n);
        //printf("n->%d\n", n);
        int sum = 0;
        getline(cin, line);
        fr(i,0,n){
            getline(cin, line);
            len = line.length();
          //  printf("line-> %s\n", line.c_str());
            fr(j,0,len){
                c = line[j];
                if(my.count(c) ){
                    sum += my[c];
                }
            
            }
        }
        
        double res = sum/100.0;
        printf("%.2lf$\n", res);
    }
    
    
    
    return 0;
}


