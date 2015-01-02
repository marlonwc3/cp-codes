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

int rep[30005];
void init(int n){
    fr(i,0,n+1) rep[i] = i;
}
int find(int a){
    if(rep[a] == a) return a;
    return rep[a] = find(rep[a]);
}
void uni(int a, int b){
    int repA = find(a);
    int repB = find(b);
    if(!repB) {
        rep[repA] = repB;
    }
    else {
        rep[repB] = repA;
    }

}
int nums[30005];
int main (int argc, char const* argv[]) {
    int n,m, k, a, b;
    while(1){
        sc2(n,m);
        if(!n && !m) break;
        init(n);
        fr(i,0,m){
            sc1(k);
            sc1(a); k--;
            fr(j,0,k){
               sc1(b);
               uni(a,b);
            }
        }
        int ri;
        int cnt = 0;
        fr(i,0,n){
            ri = find(i);
            if(!ri) cnt++;
        }
        printf("%d\n", cnt);
    }
        
    return 0;
}


