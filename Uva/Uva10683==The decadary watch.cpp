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

/*
(10h + 100minutos + 100segundos)
   12*3*3 ---------  5*25
      x    ---------- y
      y = (x*5*25)/12*
*/
void print(ll k){
    if( k < 10 ) printf("0");
    printf("%lld", k);
}

int main(int argc, char const *argv[]) {
    ll h, m, s, c, sum;
    while (scanf("%2lld%2lld%2lld%2lld", &h, &m, &s, &c) == 4  ){
      //  printf("%lld %lld %lld %lld\n", h,m,s,c);
        sum = h;
        sum = 60*sum + m;
        sum = 60*sum + s;
        sum = 100*sum + c;

        ll r =  trunc((sum*125)/(108+0.0));

        c = r%100;
        r/=100;
        s = r%100;
        r/=100;
        m = r%100;
        r/=100;
        h = r%100;
        r/=100;

        printf("%lld", h);
        print(m);
        print(s);
        print(c);
        _
        


    }


    return 0;
}