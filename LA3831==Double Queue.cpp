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
set<ii> s;

int main (int argc, char const* argv[]){
    int o;
    int a, p;
    set<ii>::iterator it;
    while(1){
        sc1(o); iz(o);
        if(o == 1) {
            sc2(a,p);
            s.insert(mp(p,a));
        }
        if(o==3){
           if(s.empty()){
                a = 0;
           }
           else {
            a= (*s.begin()).second;
            s.erase(s.begin());
           }
           printf("%d\n", a);
        }
        if (o==2){
           if(s.empty()){
                a =0;
           }
           else {
                it = s.end();
               it--;
               a = (*it).nd;
               s.erase(it);
               
               
           }            
           printf("%d\n", a) ;          
        }
        
    }
    
    
    
    
    return 0;
}

