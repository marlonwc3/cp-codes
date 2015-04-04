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
 
 
vi v;
 
bool go(int n){
        v.clear();
        ll k = 1;
        fr(i,2,10){
                while(n%i==0) {
                        n/=i;
                        if(k*i >= 10 ) { v.pb(k); k = 1;}  
                        k*=i;
                }
        }
        if(k!=1) v.pb(k);
        if(n != 1) return 0;
        return 1;
}
 
 
int main(int argc, char const *argv[]) {
        int t, n;
        sc1(t);
        while(t--){
                sc1(n);
                if(!n) printf("10\n");
                else if(n < 10 ) printf("%d\n", n);
                else if(go(n)){
                        sort(v.begin(), v.end());
                        fr(i,0,v.size() ) printf("%d", v[i]);
                        _
                }
                else printf("-1\n");
 
        }
        return 0;
}
