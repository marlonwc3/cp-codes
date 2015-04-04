#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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


int main(int argc, char const *argv[]) {
    int caso;
    sc1(caso);
    int a1, m1, d1, a2, m2, d2;
    int k, cnt;
    fe(t,1,caso){
        scanf("%d/%d/%d", &d2, &m2, &a2);
        scanf("%d/%d/%d", &d1, &m1, &a1);
        if(a2 < a1 ) {
            printf("Case #%d: Invalid birth date\n", t);
        }
        else {
            k = a2 - a1;
            if( k == 0 ){
                if(m2 < m1 ) printf("Case #%d: Invalid birth date\n", t);
                else if (m2==m1){
                    if( d2 >= d1 ) printf("Case #%d: 0\n", t); 
                    else printf("Case #%d: Invalid birth date\n", t);
                }
                else {
                    printf("Case #%d: 0\n", t); 
                }
            }
            else{
                bool ok = 1;
                if( m2 < m1 ) ok = 0;
                else if(m2 == m1){
                    ok = d2 >= d1;
                } 
                else ok = 1;
                k -= !ok;
                if(k > 130) printf("Case #%d: Check birth date\n", t);    
                else printf("Case #%d: %d\n", t, k);
            }
        }



    }


    
}
