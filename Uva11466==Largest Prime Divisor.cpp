#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define nd second
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
 
bool mark[10000000];
vll sieve;
void go(){
        mark[0]=mark[1]=1;
        fr(i,0,10000000){
                if(mark[i]) continue;
                sieve.pb(i);
                for(ll j = ll(i)*i; j<10000000 && j > 0; j+=i) mark[j]=1;
        }
}
int cnt;
ll get(ll n){
        int id = 0; ll pf = sieve[0];
        ll res = -1;
        bool ok;
        cnt =0 ;
        while(n!=1 && pf*pf <= n){
                ok =0 ;
                while( n%pf == 0 ) { n/=pf; ok =1;}
                if(ok) {res = max(res, pf); cnt++; }
                id++; pf = sieve[id];
        }
        if( n != 1) { res = max(res, n); cnt++; }
        return res;
}
 
int main(int argc, char const *argv[]){
        go();
        ll n, r;       
        while(1){
                scanf("%lld", &n); if(!n) break;
                if(n < 0 ) n*=-1;
                r = get(n);
                if(n==1 || cnt == 1 ) printf("-1\n");
                else printf("%lld\n", r);
        }
        return 0;
}
