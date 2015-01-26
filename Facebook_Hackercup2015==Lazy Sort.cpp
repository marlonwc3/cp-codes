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

bool go(deque<int> s, deque<int> d){
        int cnt = 0, k;
        bool ok = 1;   
        while(1 && !s.empty() ){
            if(cnt == 2 ) {
                ok =0 ; break;
            }
            if(!cnt){
                k = s.front();
                s.pop_front();
            }
            else {
                k = s.back();
                s.pop_back();
            }
            if( d.empty() ) { d.pb(k); cnt=0; } 
            else if ( k - d.back() == 1 ){
                d.push_back(k); cnt = 0;
            }
            else if ( d.front() - k == 1 ){
                d.push_front(k); cnt =0;
            }
            else {
                if(cnt == 0) s.push_front(k);
                if(cnt == 1) s.push_back(k);
                cnt++;
            }         
        }
        return ok;
}


deque<int> s;
deque<int> d;
int main(int argc, char const *argv[]) {
    int caso, n, k;
    sc1(caso);
    fe(t,1,caso){
        s.clear();
        d.clear();
        sc1(n);
        fr(i,0,n){
            sc1(k); 
            s.pb(k);
        }  
        int k = s.front();
        s.pop_front();
        d.pb(k);
        bool ok = go(s,d);
        if(!ok){
            s.push_front(k);
            d.pop_back();
            k = s.back();
            s.pop_back();
            d.pb(k);
            ok = go(s,d);
        }

        if(ok) printf("Case #%d: yes\n", t);
        else printf("Case #%d: no\n", t);

    }




    return 0;
}