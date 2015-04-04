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






bool is(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u';
}

string s1, s2;
int main (int argc, char const* argv[]) {
    int n;
    sc1(n);
    getline(cin, s1);
    bool ok;
    while(n--){
        getline(cin, s1);
        getline(cin, s2);
        ok = s1.length() == s2.length();
        if(ok){
            fr(i,0,s1.length()){
                if(is(s1[i])){
                    ok = ok && is(s2[i]);
                }    
                else {
                    ok = ok && s1[i] == s2[i];
                }
                
            
            }    
            
            
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
        
    
    
    }
    
    
        
    return 0;
}













