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
    int n,m;
    fe(t,1,caso){
        sc2(n,m);
        ll ana = 0, bob =0 ;
        if(n%2 ==1 ) {
            bob += m;
            n--;
        }
        if(m%2 == 1) {
            bob += n;
            m--;
        }
        int q = (n/2)*(m/2);
        ana = ((q+1)/2)*4;

        bob += 4*(q/2);
        if(ana==bob) printf("Caso #%d: Empate\n", t);
        else if ( ana > bob ){
            printf("Caso #%d: Ana\n", t);
        }
        else {
            printf("Caso #%d: Bob\n", t);
        }
        //printf("ana %lld | bob %lld\n", ana, bob);



    }

    return 0;
}
