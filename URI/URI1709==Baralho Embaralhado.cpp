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

ll g(ll a, ll b){
    if(!b) return a;
    return g(b, a%b);
}
ll mmc(ll a, ll b){
    return a*b/(g(a,b));
}


ll mem[2*100005];
ll arr[2*100005];
ll n, mid;
ll go(int p, ll cnt){
    
    if(arr[p]>=3)  {return mem[p]; }
    arr[p]++;
    //printf("p:%d | cnt:%d | arr: %d\n", p,cnt, arr[p]);    
    if(arr[p]>=2){
        arr[p] = 3;
        mem[p] = cnt - mem[p];
        return mem[p];
    } 
    else{
        mem[p] = cnt;
    }

    int p2;
    if(p <= mid) p2 = 2*p;
    else {
        p2 = (p - (mid+1))*2  +1;
    }

    ll r = go(p2, cnt+1);
    mem[p] = r;
    arr[p] =3;
  //  printf("r de %d -> %d\n", p, mem[p]);
    return mem[p];
}


int main(int argc, char const *argv[]) {
    
    while(scanf("%lld", &n)==1){
        mid = n/2;
        mst(mem, 0);
        mst(arr, 0);
        ll a,b, c;
        a = go(1, 1);
        b = go(2,1);

        a = mmc(a,b);
        fe(i,3,n){
            c = go(3, 1);
            a = mmc(a,c);
        }
        printf("%lld\n", a);



    }



}
